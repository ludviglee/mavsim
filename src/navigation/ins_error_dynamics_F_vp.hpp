F[0+rows_F*1] = -(2*Omega*sinL*R+Ve*tanL)/R;
F[0+rows_F*2] = Vn/R;
F[1+rows_F*0] = (2*Omega*sinL*R+Ve*tanL)/R;
F[1+rows_F*2] = (2*Omega*cosL*R+Ve)/R;
F[2+rows_F*0] = -Vn/R;
F[2+rows_F*1] = -(2*Omega*cosL*R+Ve)/R;
F[3+rows_F*0] = 1/R;
F[3+rows_F*5] = -Vn/RR;
F[4+rows_F*1] = 1/(cosL*R);
F[4+rows_F*3] = Ve*sinL/(cosLcosL*R);
F[4+rows_F*5] = -Ve/(cosL*RR);
F[5+rows_F*2] = -1;