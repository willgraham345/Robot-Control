%% Adaptive Control Functions
%% Inverse dynamics
% function tauhat = fcn(alphahat, phidotdotr, phidotr, phi, phidot)

a1 = 0.15;  % link 1 length
b1 = 3.1e-6; % viscous damping constants
b2 = 3.1e-6;
c1 = 0.0001; % coulomb friction constants
c2 = 0.0001;
g = 9.8; % gravitational constant
N1 = 70; % gear ratios
N2 = 70;

Y11 = phidotdotr(1);
Y12 = a1*cos(phi(2)-phi(1))*phidotdotr(2) - a1*sin(phi(2)-phi(1))*phidot(2)*phidotr(2);
Y13 = g*cos(phi(1));
Y14 = 0;
Y21 = 0;
Y22 = a1*cos(phi(2)-phi(1))*phidotdotr(1) - a1*sin(phi(2)-phi(1))*phidot(1)*phidotr(1) + g*cos(phi(2));
Y23 = 0;
Y24 = phidotdotr(2);

Y = [Y11, Y12, Y13 Y14; Y21, Y22, Y23, Y24];

F1 = N1^2*b1*phidot(1) + N1*c1*sign(phidot(1));
F2 = N2^2*b2*phidot(2) + N2*c2*sign(phidot(2));

F = [F1; F2];

tauhat = Y*alphahat +F; 
%% Mass Parameter Adaptation
% function alphahatdot = fcn(phidotdotr, phidotr, phi, phidot, sigma)

a1 = 0.15;  % link 1 length
g = 9.8; % gravitational constant

Y11 = phidotdotr(1);
Y12 = a1*cos(phi(2)-phi(1))*phidotdotr(2) - a1*sin(phi(2)-phi(1))*phidot(2)*phidotr(2);
Y13 = g*cos(phi(1));
Y14 = 0;
Y21 = 0;
Y22 = a1*cos(phi(2)-phi(1))*phidotdotr(1) - a1*sin(phi(2)-phi(1))*phidot(1)*phidotr(1) + g*cos(phi(2));
Y23 = 0;
Y24 = phidotdotr(2);

Y = [Y11, Y12, Y13 Y14; Y21, Y22, Y23, Y24];

a1 = 10000; %Yellow
a2 = 800; %Blue
a3 = 400; %Orange
a4 = 5000; %Green

gamma = [a1 0 0 0;
         0 a2 0 0;
         0 0 a3 0;
         0 0 0 a4];

alphahatdot = inv(gamma)*Y'*sigma; 
%alphahatdot = 0;