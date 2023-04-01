%% PS7
%% Define Jacobian for all problems 
clear; close all; clc; format compact
sprintf("1.1")
% Define the jacobian symbolic and numeric parameters
syms theta1(t) theta2(t) t
a1=0.15;
a2=0.15;
% Define parameters within jacobian to define. Note, theta != phi so
% additional conversions must be performed within the block. 
x = a1*cos(theta1) + a2*cos(theta1+theta2);
y = a1*sin(theta1) + a2*sin(theta1+theta2);

X_vec = [x; y];

J = jacobian(X_vec, [theta1; theta2])


J_dot = diff(J, t)

%%

% Find equal PD gains for Jacobian Transpose
% syms theta1 theta22
J_inv_t = inv(J')
J_inv = inv(J)
Kp_theta = diag([8.4049, 8.4049]);
% inv(J)
a = size(Kp_theta*J_inv)
b = size(Kp_theta*J_inv_t)

Kp_x = (J_inv_t*Kp_theta)*J_inv
size(Kp_x)
% Kp_x_eval = subs(Kp_x, [theta1, theta2], [0.0 0.0])
Kd_theta = diag([0.27, 0.27]);
Kd_x = (J_inv_t*Kd_theta)*J_inv
size(Kd_x)