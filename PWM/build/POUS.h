#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PWM_TEST_PROGRAM
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  PWM_CONTROLLER PWM_CONTROLLER0;
  __DECLARE_VAR(BOOL,START_PB)
  __DECLARE_VAR(SINT,CHANNEL)
  __DECLARE_VAR(REAL,FREQ)
  __DECLARE_VAR(REAL,DUTY_CYCLE)
  __DECLARE_LOCATED(BOOL,SERVO)
  __DECLARE_LOCATED(UINT,ANALOG_PWM)

} PWM_TEST_PROGRAM;

void PWM_TEST_PROGRAM_init__(PWM_TEST_PROGRAM *data__, BOOL retain);
// Code part
void PWM_TEST_PROGRAM_body__(PWM_TEST_PROGRAM *data__);
#endif //__POUS_H
