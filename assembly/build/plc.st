TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM conveyor
  VAR_INPUT
    SensorIn : BOOL;
    SensorMiddle : BOOL;
    SensorOut : BOOL;
    StartButton : BOOL;
    StopButton : BOOL;
    ResetButton : BOOL;
  END_VAR
  VAR_OUTPUT
    ConveyorMotor : BOOL;
    AlarmJam : BOOL;
  END_VAR
  VAR
    TONFill : TON;
    TONJam : TON;
    CTUIn : CTU;
    CTUOut : CTU;
    FillDone : BOOL;
    Jammed : BOOL;
    ErrorState : BOOL;
    IODiff : INT;
    DiffAlarm : BOOL;
    AutoReset : BOOL;
    ResetState : BOOL;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    SUB27_OUT : INT;
    GE29_OUT : BOOL;
  END_VAR

  ConveyorMotor := NOT(ErrorState) AND (FillDone OR NOT(SensorMiddle) AND SensorIn) AND NOT(StopButton) AND (ConveyorMotor OR StartButton);
  TONFill(IN := SensorMiddle, PT := T#2s);
  FillDone := TONFill.Q;
  TONJam(IN := SensorMiddle, PT := T#5s);
  Jammed := TONJam.Q;
  ResetState := AutoReset OR ResetButton;
  R_TRIG1(CLK := SensorIn);
  R_TRIG2(CLK := R_TRIG1.Q);
  CTUIn(CU := R_TRIG2.Q, R := ResetState, PV := 5002);
  R_TRIG3(CLK := SensorOut);
  R_TRIG4(CLK := R_TRIG3.Q);
  CTUOut(CU := R_TRIG4.Q, R := ResetState, PV := 5000);
  SUB27_OUT := SUB(CTUIn.CV, CTUOut.CV);
  IODiff := SUB27_OUT;
  GE29_OUT := GE(IODiff, 3);
  DiffAlarm := GE29_OUT;
  AutoReset := NOT(DiffAlarm) AND CTUOut.Q;
  ErrorState := NOT(ResetButton) AND (DiffAlarm OR ErrorState OR Jammed);
  AlarmJam := ErrorState;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : conveyor;
  END_RESOURCE
END_CONFIGURATION
