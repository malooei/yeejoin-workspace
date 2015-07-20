#ifndef SI443X_CONST_B1_H
#define SI443X_CONST_B1_H

#include <common.h>
//#include "si4432.h"
//#include "si4432_v2.h"

#define NUMBER_OF_SAMPLE_SETTING		4
#define NUMBER_OF_PARAMETER_B1			15



extern const SEGMENT_VARIABLE (RfSettingsB1[NUMBER_OF_SAMPLE_SETTING][NUMBER_OF_PARAMETER_B1], U8, SEG_CODE);


#endif //SI443X_CONST_B1_H
