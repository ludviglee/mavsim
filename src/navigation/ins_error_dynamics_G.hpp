G(0,0) = -(b*dd+b*cc+bbb+aa*b)/2.0;
G(0,1) = -(c*dd+ccc+(bb+aa)*c)/2.0;
G(0,2) = -(ddd+(cc+bb+aa)*d)/2.0;
G(1,0) = -(3*a*dd+3*a*cc-a*bb-aaa)/2.0;
G(1,1) = (ddd+(cc+bb-3*aa)*d+4*a*b*c)/2.0;
G(1,2) = -(c*dd-4*a*b*d+ccc+(bb-3*aa)*c)/2.0;
G(2,0) = -(ddd+(cc+bb-3*aa)*d-4*a*b*c)/2.0;
G(2,1) = -(3*a*dd-a*cc+3*a*bb-aaa)/2.0;
G(2,2) = (b*dd+4*a*c*d+b*cc+bbb-3*aa*b)/2.0;
G(3,0) = (c*dd+4*a*b*d+ccc+(bb-3*aa)*c)/2.0;
G(3,1) = -(b*dd-4*a*c*d+b*cc+bbb-3*aa*b)/2.0;
G(3,2) = (a*dd-3*a*cc-3*a*bb+aaa)/2.0;
G(4,3) = -dd-cc+bb+aa;
G(4,4) = 2*b*c-2*a*d;
G(4,5) = 2*b*d+2*a*c;
G(5,3) = 2*a*d+2*b*c;
G(5,4) = -dd+cc-bb+aa;
G(5,5) = 2*c*d-2*a*b;
G(6,3) = 2*b*d-2*a*c;
G(6,4) = 2*c*d+2*a*b;
G(6,5) = dd-cc-bb+aa;
