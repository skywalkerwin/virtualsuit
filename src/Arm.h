#pragma once
#include "ofMain.h"
using namespace std;

class Arm
{
public:

	void armSetup(string com);
	void armUpdate();
	Arm();
	~Arm();

	// serial communication variables
	ofSerial port;
	string coms;
	bool firstContact = false;
	unsigned char inBuffer[122];
	int off = 0;
	//magnetic calibration variables
	float magmin[3][3] = { { 60000, 60000, 60000 }, { 60000, 60000, 60000 }, { 60000, 60000, 60000 } };
	float magmax[3][3] = { { -60000, -60000, -60000 }, { -60000, -60000, -60000 }, { -60000, -60000, -60000 } };
	float magbias[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	float magscale[3][3] = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
	float avgrad[3] = { 1, 1, 1 };
	float scalebias[3][3] = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
	// touch values
	int ttime = 0;
	int switchbinary = 0;
	int thumbPressure = 0;
	int switches[4] = { 0, 0, 0, 0 };
	int minpress = 1000;
	int maxpress = 0;
	int rangepress = 0;
	float normpress = 0;
	float presst[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	double totalPress = 0;
	// sensor fusion stuff
	float deltat = 0;
	static constexpr float GyroMeasError = PI * (50.0f / 180.0f); // gyroscope measurement error in rads/s (start at 40 deg/s)
	static constexpr float GyroMeasDrift = PI * (5.0f / 180.0f); // gyroscope measurement drift in rad/s/s (start at 0.0 deg/s/s)
	const float beta = sqrt(3.0f / 4.0f) * GyroMeasError; // compute beta
	const float zeta = sqrt(3.0f / 4.0f) * GyroMeasDrift;
	float q[8][4];
	//scalar multipliers for sensors
	const float ascale = .000488;
	const float gscale = .061068;
	const int negcheck = 32767;
	// roll pitch yaw
	float roll[11];// { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	float pitch[11];// { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	float yaw[11];// { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	float mx = 0;
	float my = 0;
	float mz = 0;

private:
	// current sensor values
	float imu[6][6];
	float magno[3][9];
	// sensor history
	int hcount = 0;
	static const int histlength = 180;
	static const int nframes = 1;
	float mhist[3][9][histlength];
	float ihist[5][6][histlength];
	float nimu[12][6][nframes];
	float nmag[3][9][nframes];
	float magadj[3] = { 176, 176, 165 };
	float ypltscales[3] = { 16, 2000, 1000 };

};
