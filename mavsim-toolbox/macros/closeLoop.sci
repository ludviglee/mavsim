function dataNew = closeLoop(data,y,u,H)
    olss = minss(data.clss(y,u)*H);

    if (olss == 0)
        pm = -%inf;
        gm = -%inf;
    else
        pm = p_margin(olss)+180;
        for i=1:length(pm)
            if (pm(i) >= 180) pm(i) = pm(i) - 360; end
            if (pm(i) < -180) pm(i) = pm(i) + 360; end
        end
        gm = g_margin(olss);
    end

    data.clss = unityFeedback(y,u,data.clss,H);
    data.cltf = ss2tf(data.clss);
    uNew = max(size(data.u.str))+1;
    data.u = createIndex(data.y.str(y),data.u);
    
	dcGain = norm(horner(ss2tf(olss),%eps));
    if (dcGain > 1e6) dcGain = %inf; end;

    dcGainH = norm(horner(H,%eps));
    if (dcGainH > 1e6) dcGainH = %inf; end;

    deff("y=clMag(s)","y=norm(horner(ss2tf(minss(data.clss(y,uNew))),%i*s*2*%pi))");
    if (olss==0)
        gfc=%inf;
    else
        deff("y=clbw3dB(s)","y=clMag(s)-0.7079");
        freqGuess = 0;
        while(1)
            [gfc,v,info]=fsolve(freqGuess,clbw3dB,[],1e-30);
            if (info == 1 | freqGuess > 500) break; end;
            freqGuess = freqGuess+1;
        end
        if (gfc<0) gfc = -gfc; end
    end

    if ( size(pm) == 0) pm = -%inf; end
    if ( size(gm) == 0) gm = -%inf; end
    if ( size(gfc) == 0) gfc = %inf; end
    if ( min(gm) < 0 | min(pm) < 0)
        stability = "unstable";
    else 
        stability = "stable";
    end

    printf("%10s\t%10s\t%10s\t%7.2f\t%7.2f\t%7.2f\t%7.2f\t%7.2f\n",..
        data.y.str(y), data.u.str(u),..
        stability, min(gm),min(pm),min(gfc),dcGainH,100.0/dcGain);

    dataNew = data;
endfunction
// vim:ts=4:sw=4:expandtab