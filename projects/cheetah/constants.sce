 // constants
g=9.81; // m/s^2

// trim conditions
betaAngle=0; // trim
wy=0; //trim
wz=0; //trim
wx=0; //trim
phi=0; //trim
psi=0; // trim
gammaAngle=0; // flight path angle,for level flight is zero

// aerodynamics
rho=1.225; // kg/m^3
rBlade=0.125; // metres
Cd0= 0.42; // guess
K_cd_cl=0.02; //guess
s_frame=.1; //guess in m^2
s_frame_side=.1; // guess in m^2

// airframe
m=1.25;  //kg
dm=.24; // guess in metres, motor moment arm

cmR = .08; // radius of sphere approximation for mass
cmZ = .1; // center of mass 10 cm below center of airframe
JSolidSphere = 2/5*m*cmR^2;
Jy=JSolidSphere + m*cmZ^2; // moments of inertia, kg-m^2
Jz=JSolidSphere; // guess, for now using solid sphere
Jx=JSolidSphere + m*cmZ^2;
Jxy = 0; Jyz = 0; Jxz = 0;
printf("\tinertia guess assuming solid sphere: %f kg-m^2",JSolidSphere);

// motor
KV=850 // rpm/Volts 
batVolt=11.1; //Volts
tau_motor=46.2; // from  motor pole (rad/s) source: https://dspace.ist.utl.pt/bitstream/2295/574042/1/Tese_de_Mestrado.pdf
T_max = 4.9; // max motor thrust in newtons
torque_max = 0.8*dm; // max motor thrust in newton-m
C_T = T_max / (rho*%pi*rBlade^4*(KV*2*%pi/60*batVolt)^2);
C_Q = torque_max / (rho*%pi*rBlade^4*(KV*2*%pi/60*batVolt)^2);
controlPeriodAtt = 1/200; // attitude control rate 50 Hz
controlPeriodPos = 1/50; // position control rate 50 Hz
navDelay = 0.100 // seconds of navigation delay

// trim
T_sum_trim = 900*g*m/(%pi^3*rho*batVolt^2*KV^2*rBlade^4*C_T);
u0=[T_sum_trim;0;0;0];

//hover
U = 0; V = 0; W = 0; // hover

// controllers

// position control loop
PID_POS_INTERVAL = 0.02; // 50 hz
PID_POS_P = 1; //1.7;
PID_POS_I = 0;// 0.25; 
PID_POS_D = 5; //2.8
PID_POS_LIM = 0.15;
PID_POS_AWU = 0.1;
PID_POS_Z_P = 0.35;
PID_POS_Z_I = 0.2;
PID_POS_Z_D = 0.15;
PID_POS_Z_LIM = 0.2;
PID_POS_Z_AWU = 3;
VEL_OFFSET_X = 0;
VEL_OFFSET_Y = 0;

// attitude control loop
PID_ATT_INTERVAL = 0.005; // 200 hz
PID_ATT_P= 90;
PID_ATT_I= 0; //60;
PID_ATT_D= 30;
PID_ATT_LIM= 100;
PID_ATT_AWU= 0.3;
PID_YAWPOS_P= 3.1; //5;
PID_YAWPOS_I= 1;
PID_YAWPOS_D= 31; //1;
PID_YAWPOS_LIM= 2;
PID_YAWPOS_AWU= 1;
PID_YAWSPEED_P= 15;
PID_YAWSPEED_I= 5;
PID_YAWSPEED_D= 0;
PID_YAWSPEED_LIM= 20;
PID_YAWSPEED_AWU= 1;
ATT_OFFSET_X =0;
ATT_OFFSET_Y =0;
ATT_OFFSET_Z = -0.080;

// mixing
MIX_REMOTE_WEIGHT = 1;
MIX_POSITION_WEIGHT =1;
MIX_POSITION_Z_WEIGHT = 1;
MIX_POSITION_YAW_WEIGHT = 1;
MIX_OFFSET_WEIGHT =1;

// waypoint
POSITION_SETPOINT_X = 0;
POSITION_SETPOINT_Y = 0;
POSITION_SETPOINT_Z = 0;
POSITION_SETPOINT_YAW = 0.0;

THRUST_HOVER_OFFSET = 160;

// zero order hold pade approximation
function sys = pade(controlPeriod)
	sys = (1-%s*controlPeriod/6)/(1 + %s*controlPeriod/3);
endfunction

// continuous pid controller model
function sys = pidCont(kP,kI,kD,controlPeriod)
	sys = pade(controlPeriod)*syslin('c',kP+kI/%s+%s*kD);
endfunction

// linear approximations of controllers
H.pitch_FB = -0.005*pidCont(PID_ATT_P,PID_ATT_I,PID_ATT_D,PID_ATT_INTERVAL);
H.roll_LR = 0.005*pidCont(PID_ATT_P,PID_ATT_I,PID_ATT_D,PID_ATT_INTERVAL);
H.yawRate_LRFB = pidCont(PID_YAWSPEED_P,PID_YAWSPEED_I,PID_YAWSPEED_D,PID_ATT_INTERVAL);
H.yaw_yawRate = pidCont(PID_YAWPOS_P,PID_YAWPOS_I,PID_YAWPOS_D,PID_ATT_INTERVAL);
H.pN_pitch = pidCont(PID_POS_P,PID_POS_I,PID_POS_D,PID_POS_INTERVAL);
H.pE_roll = pidCont(PID_POS_P,PID_POS_I,PID_POS_D,PID_POS_INTERVAL);
H.pD_SUM = pidCont(PID_POS_Z_P,PID_POS_Z_I,PID_POS_Z_D,PID_POS_INTERVAL);

x0 = [
U; // U
W; // W
0; // theta
wy; // wy
V; // V
0; // phi
wx; // wx
psi; // psi
wz]; //wz

r = createIndex(["pN","pE","pD","yaw"]);
m = createIndex(["Vfwd","psi","h","Vside"]);
x = createIndex(["U","W","pitch","pitchRate","V","roll","rollRate","yaw",..
	"yawRate","vN","vE","vD","pN","pE","pD"]);
u = createIndex(["SUM","FB","LR","LRFB"]);
y = x;
