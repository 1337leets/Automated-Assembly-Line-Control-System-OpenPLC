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





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void CONVEYOR_init__(CONVEYOR *data__, BOOL retain) {
  __INIT_VAR(data__->SENSORIN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORMIDDLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOROUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STARTBUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOPBUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESETBUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYORMOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARMJAM,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TONFILL,retain);
  TON_init__(&data__->TONJAM,retain);
  CTU_init__(&data__->CTUIN,retain);
  CTU_init__(&data__->CTUOUT,retain);
  __INIT_VAR(data__->FILLDONE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->JAMMED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ERRORSTATE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IODIFF,0,retain)
  __INIT_VAR(data__->DIFFALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUTORESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESETSTATE,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  __INIT_VAR(data__->SUB27_OUT,0,retain)
  __INIT_VAR(data__->GE29_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void CONVEYOR_body__(CONVEYOR *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,CONVEYORMOTOR,,(((!(__GET_VAR(data__->ERRORSTATE,)) && (__GET_VAR(data__->FILLDONE,) || (!(__GET_VAR(data__->SENSORMIDDLE,)) && __GET_VAR(data__->SENSORIN,)))) && !(__GET_VAR(data__->STOPBUTTON,))) && (__GET_VAR(data__->CONVEYORMOTOR,) || __GET_VAR(data__->STARTBUTTON,))));
  __SET_VAR(data__->TONFILL.,IN,,__GET_VAR(data__->SENSORMIDDLE,));
  __SET_VAR(data__->TONFILL.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TONFILL);
  __SET_VAR(data__->,FILLDONE,,__GET_VAR(data__->TONFILL.Q,));
  __SET_VAR(data__->TONJAM.,IN,,__GET_VAR(data__->SENSORMIDDLE,));
  __SET_VAR(data__->TONJAM.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TON_body__(&data__->TONJAM);
  __SET_VAR(data__->,JAMMED,,__GET_VAR(data__->TONJAM.Q,));
  __SET_VAR(data__->,RESETSTATE,,(__GET_VAR(data__->AUTORESET,) || __GET_VAR(data__->RESETBUTTON,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->SENSORIN,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->R_TRIG1.Q,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTUIN.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTUIN.,R,,__GET_VAR(data__->RESETSTATE,));
  __SET_VAR(data__->CTUIN.,PV,,5002);
  CTU_body__(&data__->CTUIN);
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->SENSOROUT,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_VAR(data__->R_TRIG3.Q,));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->CTUOUT.,CU,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTUOUT.,R,,__GET_VAR(data__->RESETSTATE,));
  __SET_VAR(data__->CTUOUT.,PV,,5000);
  CTU_body__(&data__->CTUOUT);
  __SET_VAR(data__->,SUB27_OUT,,SUB__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->CTUIN.CV,),
    (INT)__GET_VAR(data__->CTUOUT.CV,)));
  __SET_VAR(data__->,IODIFF,,__GET_VAR(data__->SUB27_OUT,));
  __SET_VAR(data__->,GE29_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->IODIFF,),
    (INT)3));
  __SET_VAR(data__->,DIFFALARM,,__GET_VAR(data__->GE29_OUT,));
  __SET_VAR(data__->,AUTORESET,,(!(__GET_VAR(data__->DIFFALARM,)) && __GET_VAR(data__->CTUOUT.Q,)));
  __SET_VAR(data__->,ERRORSTATE,,(!(__GET_VAR(data__->RESETBUTTON,)) && ((__GET_VAR(data__->DIFFALARM,) || __GET_VAR(data__->ERRORSTATE,)) || __GET_VAR(data__->JAMMED,))));
  __SET_VAR(data__->,ALARMJAM,,__GET_VAR(data__->ERRORSTATE,));

  goto __end;

__end:
  return;
} // CONVEYOR_body__() 





