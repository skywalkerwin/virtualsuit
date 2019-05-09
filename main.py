import serial
import time
import numpy as np

magno = np.zeros((3, 9), dtype=np.int16)
imu = np.zeros((5, 6), dtype=np.int16)
ser = serial.Serial('COM5', 12000000, timeout=None, parity = serial.PARITY_EVEN, rtscts = 1)
# ser.open()
a=ser.read()
ser.write(1)

while(True):
    inBuffer=ser.read(122)
    ser.write(1)
    for i in range(3):
        magno[i][0] = (inBuffer[0 + (i * 18)] << 8 | inBuffer[1 + (i * 18)] & 0xff)
        magno[i][1] = (inBuffer[2 + (i * 18)] << 8 | inBuffer[3 + (i * 18)] & 0xff)
        magno[i][2] = (inBuffer[4 + (i * 18)] << 8 | inBuffer[5 + (i * 18)] & 0xff)

        magno[i][3] = (inBuffer[6 + (i * 18)] << 8 | inBuffer[7 + (i * 18)] & 0xff)
        magno[i][4] = (inBuffer[8 + (i * 18)] << 8 | inBuffer[9 + (i * 18)] & 0xff)
        magno[i][5] = (inBuffer[10 + (i * 18)] << 8 | inBuffer[11 + (i * 18)] & 0xff)

        magno[i][6] = (inBuffer[12 + (i * 18)] << 8 | inBuffer[13 + (i * 18)] & 0xff)
        magno[i][7] = (inBuffer[14 + (i * 18)] << 8 | inBuffer[15 + (i * 18)] & 0xff)
        magno[i][8] = (inBuffer[16 + (i * 18)] << 8 | inBuffer[17 + (i * 18)] & 0xff)

    for i in range(5):
        imu[i][0] = (inBuffer[54 + (i * 12)] << 8) | (inBuffer[55 + (i * 12)] & 0xff)
        imu[i][1] = (inBuffer[56 + (i * 12)] << 8) | (inBuffer[57 + (i * 12)] & 0xff)
        imu[i][2] = (inBuffer[58 + (i * 12)] << 8) | (inBuffer[59 + (i * 12)] & 0xff)

        imu[i][3] = (inBuffer[60 + (i * 12)] << 8) | (inBuffer[61 + (i * 12)] & 0xff)
        imu[i][4] = (inBuffer[62 + (i * 12)] << 8) | (inBuffer[63 + (i * 12)] & 0xff)
        imu[i][5] = (inBuffer[64 + (i * 12)] << 8) | (inBuffer[65 + (i * 12)] & 0xff)


    print(magno)
    print(imu)