void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PWM_TEST_PROGRAM_init__(PWM_TEST_PROGRAM *data__, BOOL retain) {
  PWM_CONTROLLER_init__(&data__->PWM_CONTROLLER0,retain);
  __INIT_VAR(data__->START_PB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CHANNEL,3,retain)
  __INIT_VAR(data__->FREQ,1.0,retain)
  __INIT_VAR(data__->DUTY_CYCLE,50.0,retain)
  __INIT_LOCATED(BOOL,__QX0_1,data__->SERVO,retain)
  __INIT_LOCATED_VALUE(data__->SERVO,0)
  __INIT_LOCATED(UINT,__QW0,data__->ANALOG_PWM,retain)
  __INIT_LOCATED_VALUE(data__->ANALOG_PWM,9830)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  __INIT_LOCATED(BOOL,__QX0_2,data__->SERVO_OUT_PWM_MANUAL,retain)
  __INIT_LOCATED_VALUE(data__->SERVO_OUT_PWM_MANUAL,0)
  __INIT_LOCATED(BOOL,__QX0_3,data__->SERVO_OUT_PWM_MANUAL0,retain)
  __INIT_LOCATED_VALUE(data__->SERVO_OUT_PWM_MANUAL0,0)
}

// Code part
void PWM_TEST_PROGRAM_body__(PWM_TEST_PROGRAM *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->PWM_CONTROLLER0.,CHANNEL,,__GET_VAR(data__->CHANNEL,));
  __SET_VAR(data__->PWM_CONTROLLER0.,FREQ,,__GET_VAR(data__->FREQ,));
  __SET_VAR(data__->PWM_CONTROLLER0.,DUTY,,__GET_VAR(data__->DUTY_CYCLE,));
  PWM_CONTROLLER_body__(&data__->PWM_CONTROLLER0);
  __SET_LOCATED(data__->,SERVO,,__GET_VAR(data__->PWM_CONTROLLER0.SUCCESS,));
  __SET_VAR(data__->TON1.,IN,,!(__GET_LOCATED(data__->SERVO_OUT_PWM_MANUAL,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 17, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 3, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_LOCATED(data__->,SERVO_OUT_PWM_MANUAL,,__GET_VAR(data__->TON0.Q,));

  goto __end;

__end:
  return;
} // PWM_TEST_PROGRAM_body__() 





