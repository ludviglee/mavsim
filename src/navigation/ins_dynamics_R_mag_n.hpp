R_mag_n[0+rows_R_mag_n*0] = (cosDec2*cosDip2*sigDec2+cosDec2*cosDip2)*sigDip2+cosDec2*cosDip2*sigDec2;
R_mag_n[0+rows_R_mag_n*1] = (cosDec*sinDec*cosDip2-cosDec*sinDec*cosDip2*sigDec2)*sigDip2-cosDec*sinDec*cosDip2*sigDec2;
R_mag_n[0+rows_R_mag_n*2] = -cosDec*cosDip*sinDip*sigDip2;
R_mag_n[1+rows_R_mag_n*0] = (cosDec*sinDec*cosDip2-cosDec*sinDec*cosDip2*sigDec2)*sigDip2-cosDec*sinDec*cosDip2*sigDec2;
R_mag_n[1+rows_R_mag_n*1] = (cosDec2*cosDip2*sigDec2+cosDec2*cosDip2)*sigDip2+cosDec2*cosDip2*sigDec2;
R_mag_n[1+rows_R_mag_n*2] = -sinDec*cosDip*sinDip*sigDip2;
R_mag_n[2+rows_R_mag_n*0] = -cosDec*cosDip*sinDip*sigDip2;
R_mag_n[2+rows_R_mag_n*1] = -sinDec*cosDip*sinDip*sigDip2;
R_mag_n[2+rows_R_mag_n*2] = cosDip2*sigDip2;
