F[0+rowsF*0] = a*d*wz+a*c*wy+a*b*wx;
F[0+rowsF*1] = -((Omega*cosL-2*b*d*wz-2*b*c*wy+(-dd-cc-3*bb-aa)*wx)*R+Ve)/R/2.0;
F[0+rowsF*2] = ((2*c*d*wz+(dd-3*cc+bb+aa)*wy+2*b*c*wx)*R+Vn)/R/2.0;
F[0+rowsF*3] = ((Omega*sinL+(3*dd+cc+bb+aa)*wz+2*c*d*wy+2*b*d*wx)*R+Ve*tanL)/R/2.0;
F[0+rowsF*4] = c/R/2.0;
F[0+rowsF*5] = (d*tanL-b)/R/2.0;
F[0+rowsF*7] = ((b*Omega*sinL+d*Omega*cosL)*R+d*Ve*secLsecL)/R/2.0;
F[0+rowsF*9] = -(d*Ve*tanL+c*Vn-b*Ve)/RR/2.0;
F[1+rowsF*0] = ((Omega*cosL+(-4*b*d-6*a*c)*wz+(6*a*d-4*b*c)*wy+(3*dd+3*cc-bb-3*aa)*wx)*R+Ve)/R/2.0;
F[1+rowsF*1] = (b*c-2*a*d)*wz+(-b*d-2*a*c)*wy-a*b*wx;
F[1+rowsF*2] = -((Omega*sinL+(-dd-3*cc-bb+3*aa)*wz+(6*c*d+4*a*b)*wy-6*a*c*wx)*R+Ve*tanL)/R/2.0;
F[1+rowsF*3] = (((2*c*d-4*a*b)*wz+(-3*dd-3*cc-bb+3*aa)*wy+6*a*d*wx)*R+Vn)/R/2.0;
F[1+rowsF*4] = d/R/2.0;
F[1+rowsF*5] = -(c*tanL-a)/R/2.0;
F[1+rowsF*7] = -((a*Omega*sinL+c*Omega*cosL)*R+c*Ve*secLsecL)/R/2.0;
F[1+rowsF*9] = (c*Ve*tanL-d*Vn-a*Ve)/RR/2.0;
F[2+rowsF*0] = -(((4*c*d-6*a*b)*wz+(-3*dd-cc-3*bb+3*aa)*wy+(6*a*d+4*b*c)*wx)*R+Vn)/R/2.0;
F[2+rowsF*1] = ((Omega*sinL+(-dd-cc-3*bb+3*aa)*wz+6*a*b*wy+(2*b*d-4*a*c)*wx)*R+Ve*tanL)/R/2.0;
F[2+rowsF*2] = (-2*a*d-b*c)*wz+a*c*wy+(c*d-2*a*b)*wx;
F[2+rowsF*3] = ((Omega*cosL+(-2*b*d-4*a*c)*wz+6*a*d*wy+(3*dd+cc+bb-3*aa)*wx)*R+Ve)/R/2.0;
F[2+rowsF*4] = -a/R/2.0;
F[2+rowsF*5] = (b*tanL+d)/R/2.0;
F[2+rowsF*7] = -((d*Omega*sinL-b*Omega*cosL)*R-b*Ve*secLsecL)/R/2.0;
F[2+rowsF*9] = -(b*Ve*tanL-a*Vn+d*Ve)/RR/2.0;
F[3+rowsF*0] = -((Omega*sinL+(dd-3*cc-3*bb+3*aa)*wz+(4*c*d+6*a*b)*wy+(4*b*d-6*a*c)*wx)*R+Ve*tanL)/R/2.0;
F[3+rowsF*1] = ((6*a*b*wz+(dd+3*cc+3*bb-3*aa)*wy+(-4*a*d-2*b*c)*wx)*R-Vn)/R/2.0;
F[3+rowsF*2] = -((Omega*cosL-6*a*c*wz+(4*a*d-6*b*c)*wy+(dd+3*cc+bb-3*aa)*wx)*R+Ve)/R/2.0;
F[3+rowsF*3] = -a*d*wz+(b*d-2*a*c)*wy+(-c*d-2*a*b)*wx;
F[3+rowsF*4] = -b/R/2.0;
F[3+rowsF*5] = -(a*tanL+c)/R/2.0;
F[3+rowsF*7] = ((c*Omega*sinL-a*Omega*cosL)*R-a*Ve*secLsecL)/R/2.0;
F[3+rowsF*9] = (a*Ve*tanL+b*Vn+c*Ve)/RR/2.0;
F[4+rowsF*0] = 2*c*fz-2*d*fy+2*a*fx;
F[4+rowsF*1] = 2*d*fz+2*c*fy+2*b*fx;
F[4+rowsF*2] = 2*a*fz+2*b*fy-2*c*fx;
F[4+rowsF*3] = 2*b*fz-2*a*fy-2*d*fx;
F[4+rowsF*5] = -(2*Omega*sinL*R+Ve*tanL)/R;
F[4+rowsF*6] = Vn/R;
F[5+rowsF*0] = -2*b*fz+2*a*fy+2*d*fx;
F[5+rowsF*1] = -2*a*fz-2*b*fy+2*c*fx;
F[5+rowsF*2] = 2*d*fz-2*c*fy+2*b*fx;
F[5+rowsF*3] = 2*c*fz-2*d*fy+2*a*fx;
F[5+rowsF*4] = (2*Omega*sinL*R+Ve*tanL)/R;
F[5+rowsF*6] = (2*Omega*cosL*R+Ve)/R;
F[6+rowsF*0] = 2*a*fz+2*b*fy-2*c*fx;
F[6+rowsF*1] = -2*b*fz+2*a*fy+2*d*fx;
F[6+rowsF*2] = -2*c*fz+2*d*fy-2*a*fx;
F[6+rowsF*3] = 2*d*fz+2*c*fy+2*b*fx;
F[6+rowsF*4] = -Vn/R;
F[6+rowsF*5] = -(2*Omega*cosL*R+Ve)/R;
F[7+rowsF*4] = 1/R;
F[7+rowsF*9] = -Vn/RR;
F[8+rowsF*5] = 1/(cosL*R);
F[8+rowsF*7] = Ve*sinL/(cosLcosL*R);
F[8+rowsF*9] = -Ve/(cosL*RR);
F[9+rowsF*6] = -1;