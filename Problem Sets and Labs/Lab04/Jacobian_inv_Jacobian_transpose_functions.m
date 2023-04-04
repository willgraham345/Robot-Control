%% Jacobian Transpose and Inverse Function Write-out
%% Jacobian Transpose
% function tau = fcn(phi, F)

a1=0.15;
a2=0.15;

J =[-a1*sin(phi(1)) - a2*sin(phi(2)), -a2*sin(phi(2)) ; a1*cos(phi(1)) + a2*cos(phi(2)), a2*cos(phi(2))] *[1, 0 ; -1, 1];

Jtrans = J';

tau = Jtrans * F;

%% Jacobian Inverse
% function phi_err = fcn(phi, x_err)

a1=0.15;
a2=0.15;

J =[-a1*sin(phi(1)) - a2*sin(phi(2)), -a2*sin(phi(2)) ; a1*cos(phi(1)) + a2*cos(phi(2)), a2*cos(phi(2))] *[1, 0 ; -1, 1];

Jinv = inv(J);

phi_err = Jinv * x_err;
