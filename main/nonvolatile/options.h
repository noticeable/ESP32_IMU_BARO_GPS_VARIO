#ifndef OPTIONS_H_
#define OPTIONS_H_

typedef struct VARIO_PARAMS_ {
	int16_t  climbThresholdCps;
	int16_t  zeroThresholdCps;
	int16_t  sinkThresholdCps;
	int16_t  crossoverCps;
} VARIO_PARAMS;


typedef struct KALMAN_FILTER_PARAMS_ {
	int16_t  accelVariance; // environmental acceleration disturbance variance, divided by 1000
	int16_t  zMeasVariance; // z measurement noise variance
} KALMAN_FILTER_PARAMS;

typedef struct MISC_PARAMS_ {
   int16_t  backlitSecs;
   int16_t  utcOffsetMins;
	int16_t  trackIntervalSecs;
	int16_t  gyroOffsetLimit1000DPS;
   int16_t  glideRatioIIR;
   int16_t  gpsStableDOP;
   int16_t  trackStartThresholdm;
   int16_t  magDeclinationdeg;
   int16_t  speakerVolume;
   int16_t  logType;
} MISC_PARAMS;

typedef struct OPTIONS_ {
	VARIO_PARAMS vario;
	KALMAN_FILTER_PARAMS kf;
	MISC_PARAMS misc;
	uint16_t checkSum;
} OPTIONS;


extern OPTIONS opt;


#define MAX_OPTIONS 20

int opt_init(void);
int opt_save(VARIO_PARAMS* pVario, KALMAN_FILTER_PARAMS* pKF, MISC_PARAMS* pMisc );
void opt_setDefaults();

#endif

