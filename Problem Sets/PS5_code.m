%% Constants
a1 = .15; %m
a2 = .15; %m
m1 = 0.092; %kg
m2 = 0.077; %kg
r01 = 0.062; %m
r12 = .036; %m
I1 = .064e-3; %kg*m^2
I2 = .3e-3; %kg*m^2
Jm1 = .65e-6; %kg*m^2
Jm2 = .65e-6; %kg*m^2
b1 = 3.1e-6; %Nm*s/rad
b2 = 3.1e-6; %Nm*s/rad
c1 = .1e-3; %Nm
c2 = .1e-3; %Nm
Kt1 = .0077; %Nm/A
Kt2 = .0077; %Nm/A
N1 = 70
N2 = 70

%% Equations
H11 = N1^2*Jm1 + I1 + m2*a1^2
H12 = a1*r12*m2*cos(phi2-phi1)
H22 = N2^2*Jm2 + I2
h = a1*r12*m2*sin(phi2-phi1)
G1 = (r01*m1 + a1*m2)*g*cos(phi1)
G2 = r12*m2*g*cos(phi2)
F1 = N1^2*b1*phi1_dot + c1*sgn(phi1_dot)
F2 = N2^2*b2*phi2_dot + c2*sgn(phi2_dot)


%% Decentralized Controller
