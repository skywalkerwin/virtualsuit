#include "Arm.h"

void Arm::armSetup(string c) {
	//ofSetLogLevel(OF_LOG_VERBOSE);
	coms = c;
	port.setup(c, 12000000);
}

void Arm::armUpdate() {
	if (firstContact == false) {
		char myByte = port.readByte();
		if (myByte == OF_SERIAL_NO_DATA)
			ofLog() << "no data was read";
		else if (myByte == OF_SERIAL_ERROR)
			ofLog() << "an error occurred";
		else {
			port.flush();
			firstContact = true;
			port.writeByte('A');
		}
	}
	else {
		if (port.available() > 121) {
			int res = port.readBytes(inBuffer, 122);
			port.writeByte('A');
			for (int i = 0; i < 3; i++) {
				// ACCEL
				magno[i][0] = ((inBuffer[0 + (i * 18)] << 8 | inBuffer[1 + (i * 18)] & 0xff));
				magno[i][1] = ((inBuffer[2 + (i * 18)] << 8 | inBuffer[3 + (i * 18)] & 0xff));
				magno[i][2] = ((inBuffer[4 + (i * 18)] << 8 | inBuffer[5 + (i * 18)] & 0xff));
				// GYRO
				magno[i][3] = ((inBuffer[6 + (i * 18)] << 8 | inBuffer[7 + (i * 18)] & 0xff));
				magno[i][4] = ((inBuffer[8 + (i * 18)] << 8 | inBuffer[9 + (i * 18)] & 0xff));
				magno[i][5] = ((inBuffer[10 + (i * 18)] << 8 | inBuffer[11 + (i * 18)] & 0xff));
				// MAGNO
				magno[i][6] = ((inBuffer[12 + (i * 18)] << 8 | inBuffer[13 + (i * 18)] & 0xff));
				magno[i][7] = ((inBuffer[14 + (i * 18)] << 8 | inBuffer[15 + (i * 18)] & 0xff));
				magno[i][8] = ((inBuffer[16 + (i * 18)] << 8 | inBuffer[17 + (i * 18)] & 0xff));
				for (int j = 0; j < 9; j++) {
					if (magno[i][j] > negcheck) //magno[i][j] = -(magno[i][j] - negcheck);//??????????????????????
						if (j < 3) magno[i][j] = magno[i][j] * ascale;
						else if (j > 2 && j < 6) magno[i][j] = magno[i][j] * gscale;
						else {
							//magno[i][j-6] = magno[i][j-6];
							if (magno[i][j] > magmax[i][j - 6]) { magmax[i][j - 6] = magno[i][j]; }
							if (magno[i][j] < magmin[i][j - 6]) { magmin[i][j - 6] = magno[i][j]; }
							magbias[i][j - 6] = (magmax[i][j - 6] + magmin[i][j - 6]) / 2;
							magscale[i][j - 6] = (magmax[i][j - 6] - magmin[i][j - 6]) / 2;
							avgrad[i] = (magscale[i][0] + magscale[i][1] + magscale[i][2]) / 3;
							if (magscale[i][j - 6] != 0) { scalebias[i][j - 6] = avgrad[i] / magscale[i][j - 6]; }
							magno[i][j] -= magbias[i][j - 6];
							magno[i][j] *= scalebias[i][j - 6];
						}
					//magno[i][j]=(float)(magno[i][j]*(((magadj[(-6+j)]-128) *.5)/128)+1);
					// APPEND TO HISTORIES
					for (int j = 0; j < 9; j++) {
						nmag[i][j][off] = magno[i][j];
						mhist[i][j][hcount] = magno[i][j];
					}
					// 5x imu6
					for (int i = 0; i < 5; i++) {
						// ACCEL
						imu[i][0] = ((inBuffer[54 + (i * 12)] << 8) | (inBuffer[55 + (i * 12)] & 0xff));
						imu[i][1] = ((inBuffer[56 + (i * 12)] << 8) | (inBuffer[57 + (i * 12)] & 0xff));
						imu[i][2] = ((inBuffer[58 + (i * 12)] << 8) | (inBuffer[59 + (i * 12)] & 0xff));
						// GYRO
						imu[i][3] = ((inBuffer[60 + (i * 12)] << 8) | (inBuffer[61 + (i * 12)] & 0xff));
						imu[i][4] = ((inBuffer[62 + (i * 12)] << 8) | (inBuffer[63 + (i * 12)] & 0xff));
						imu[i][5] = ((inBuffer[64 + (i * 12)] << 8) | (inBuffer[65 + (i * 12)] & 0xff));

						for (int j = 0; j < 6; j++) {
							if (imu[i][j] > negcheck) {//imu[i][j] = -(imu[i][j] - negcheck);}
								if (j < 3) { imu[i][j] = imu[i][j] * ascale; }
								else { imu[i][j] = imu[i][j] * gscale; }
							}
							// APPEND TO HISTORIES
							for (int j = 0; j < 6; j++) {
								nimu[i][j][off] = imu[i][j];
								ihist[i][j][hcount] = imu[i][j];
							}

							// touch stuff
							thumbPressure = ((inBuffer[114] << 8) | (inBuffer[115] & 0xff));
							if (thumbPressure > maxpress) { maxpress = thumbPressure; }
							if (thumbPressure < minpress) { minpress = thumbPressure; }
							rangepress = maxpress - minpress;
							normpress = (1.0f * thumbPressure - minpress) / rangepress;
							switches[0] = 1 - inBuffer[116];
							switches[1] = 1 - inBuffer[117];
							switches[2] = 1 - inBuffer[118];
							switches[3] = 1 - inBuffer[119];
							switchbinary = (switches[3] << 3 | switches[2] << 2 | switches[1] << 1 | switches[0]);
							ttime = ((inBuffer[120] << 8) | (inBuffer[121] & 0xff));
							off = off + 1;
							if (off == nframes) { off = 0; }
						}
						deltat = ttime / 1000000.0f;
					}
					//sensorfusion();
					hcount++;
					if (hcount == histlength) { hcount = 0; }
				}
			}
		}
	}
	ofLog() << coms<<": "<<ttime << endl;
}

Arm::Arm()
{

}


Arm::~Arm()
{
}
