d_x_wind(0,0) = (F_b_(1,0)*sinBeta+(F_b_(2,0)*sinAlpha+F_b_(0,0)*cosAlpha)*cosBeta)/m;
d_x_wind(1,0) = -(F_b_(0,0)*sinAlpha-F_b_(2,0)*cosAlpha)/(cosBeta*m*Vt);
d_x_wind(2,0) = cosPhi*wy-sinPhi*wz;
d_x_wind(3,0) = (Jxy*Jz+Jxz*Jyz)*(-wy*(Jz*wz-Jyz*wy-Jxz*wx)+wz*(-Jyz*wz+Jy*wy-Jxy*wx)+M_b_(0,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy))+(Jx*Jz-JxzJxz)*(wx*(Jz*wz-Jyz*wy-Jxz*wx)-wz*(-Jxz*wz-Jxy*wy+Jx*wx)+M_b_(1,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy))+(Jx*Jyz+Jxy*Jxz)*(-wx*(-Jyz*wz+Jy*wy-Jxy*wx)+wy*(-Jxz*wz-Jxy*wy+Jx*wx)+M_b_(2,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy));
d_x_wind(4,0) = -((F_b_(2,0)*sinAlpha+F_b_(0,0)*cosAlpha)*sinBeta-F_b_(1,0)*cosBeta)/(m*Vt);
d_x_wind(5,0) = tanTheta*(cosPhi*wz+sinPhi*wy)+wx;
d_x_wind(6,0) = (Jy*Jz-Jyz)*(-wy*(Jz*wz-Jyz*wy-Jxz*wx)+wz*(-Jyz*wz+Jy*wy-Jxy*wx)+M_b_(0,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy))+(Jxy*Jz+Jxz*Jyz)*(wx*(Jz*wz-Jyz*wy-Jxz*wx)-wz*(-Jxz*wz-Jxy*wy+Jx*wx)+M_b_(1,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy))+(Jxy*Jyz+Jxz*Jy)*(-wx*(-Jyz*wz+Jy*wy-Jxy*wx)+wy*(-Jxz*wz-Jxy*wy+Jx*wx)+M_b_(2,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy));
d_x_wind(7,0) = (cosPhi*wz+sinPhi*wy)/cosTheta;
d_x_wind(8,0) = (Jxy*Jyz+Jxz*Jy)*(-wy*(Jz*wz-Jyz*wy-Jxz*wx)+wz*(-Jyz*wz+Jy*wy-Jxy*wx)+M_b_(0,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy))+(Jx*Jyz+Jxy*Jxz)*(wx*(Jz*wz-Jyz*wy-Jxz*wx)-wz*(-Jxz*wz-Jxy*wy+Jx*wx)+M_b_(1,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy))+(Jx*Jy-JxyJxy)*(-wx*(-Jyz*wz+Jy*wy-Jxy*wx)+wy*(-Jxz*wz-Jxy*wy+Jx*wx)+M_b_(2,0))/(Jx*(Jy*Jz-Jyz)-Jxy*(Jxy*Jz+Jxz*Jyz)-Jxz*(Jxy*Jyz+Jxz*Jy));
