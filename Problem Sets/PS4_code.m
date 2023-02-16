%%% Constants
clear; clc; format compact; close all;
k_t = 0.0077; % Motor Torque Constant, N*m/A
R_a = 2.6; %Armature resistance, Ohms
N = 70; %Gear ratio
I_1 = .83e-3; % Inertia, link 1 kg*m^2
J_m = .65e-6; % Motor Inertia, 2 kg*m^2
b = 3.1e-6; % mechanical damping, N*m*s/rad
gravity_torque = 0.067; % gravitational torque constant (m1*g*r01) N*m/rad

%% Problem 1 Work
N_maximize_torque = sqrt(I_1/J_m);

fprintf('Maximize Torque Gear Ratio: %i\n', round(N_maximize_torque));


%% Problem 2.1
disp("")
disp("Problem 2a")
disp("")
% syms I_1, J_m, N, b, k_t, R_a, gravity_torque
inertial_terms = (I_1 + J_m*N^2);
num = [0, 0, (N*k_t)/(R_a*inertial_terms)]; % numerator Open loop
den = [1, (N^2*(b + k_t^2/R_a)) / inertial_terms, gravity_torque/inertial_terms]; % Denominator open loop

% G = tf(num, den); % transfer function
omega_n = sqrt(den(3));
zeta = den(2) / (2*omega_n);
% P = pole(G);
% tau = 1 / -P(2);
% G_steady_state = num(3)/ den(3);
% 0.63*G_steady_state;

%% Problem 2.2
disp("")
disp("Problem 2b")
disp("")
num = [0, 0, N*k_t/inertial_terms];
den = [1, N^2*b/inertial_terms, gravity_torque/inertial_terms];
% H = tf(num, den);
% omega_n = sqrt(den(3));
% zeta = den(2) / (2*omega_n);
% rlocus(H); %works, just commented to avoid seeing it
% stepinfo(H);
% 
% ts = 4 / (zeta*omega_n);
% tp = pi / (omega_n*sqrt(1-zeta^2));
% os = exp(-pi*zeta/(sqrt(1-zeta^2)));

% H_steady_state = num(3) / den(3);
% step(H); %works, just commented to avoid seeing it + speed up script
%% Problem 3.1
disp("")
disp("Problem 3.1")
disp("")
% G_p = H

% P = pole(G_p)

num = [0, 0, N*k_t/inertial_terms];
den = [1, N^2*b/inertial_terms, gravity_torque/inertial_terms];


% Determine desired characteristic eqn and poles
overshoot_des = .1
zeta_des = -log(overshoot_des) / sqrt(pi^2 + (log(overshoot_des))^2)
ts_des = 0.2
omega_n_des = 4/ (ts_des*zeta_des)
omega_d_des = omega_n_des*sqrt(1-zeta_des^2)
den_des = [1, 2*zeta_des*omega_n_des, omega_n_des^2]
real_des = zeta_des*omega_n_des
img_des = omega_d_des

% Factor poles for testing RL equations


% Angle Condition Checks
p = [1.89, 3.62]
p_x = 1.89
p_y = 3.62


theta1 = 180- atand((img_des-p_y)/(real_des - p_x) )
theta2 = 180 - atand((img_des+p_y)/(real_des - p_x) )
l1 = sqrt((img_des-p_y)^2 + (real_des - p_x)^2 )
l2 = sqrt((img_des+p_y)^2 + (real_des - p_x)^2 )

phi = theta1 + theta2 - 180

kp_over_kd = img_des/tand(phi) + real_des

l3 = sqrt(img_des^2 + (kp_over_kd-real_des)^2)

kd = (l1*l2 / l3)/134.2 
kp = kd* kp_over_kd

%% 3.2
% We need a new l3
l3 = sqrt(real_des^2 + img_des^2)
theta3 = atan2d(27.278, -20)
theta_remaining = -180 + theta1 + theta2 + theta3
phi = theta_remaining/2
z = img_des/tand(phi) + 20
Kd_PID = ( (l1*l2*l3) / (2*sqrt((z-real_des)^2 + img_des^2)) ) / 134.2

Kp_PID = 2*z * Kd_PID
Ki_PID = z^2*Kd_PID

%% 3.3
out = sim("PS4_sim.slx", 5);
fig1 = figure(1)
fig1 = out.PD_controller.plot()
xlabel("Time (sec)")
ylabel("Theta (rad)")
title("3.3 PD Controller Step Response")
S = stepinfo(out.PD_controller.Data, out.tout, 1)
% Unpack S for values
values = [S.Overshoot, S.SettlingTime, (1-out.PD_controller.Data(end))]
str = sprintf("Overshoot: %f%%\nSettling time: %f\nSteady State Error: %f%%", values) 
text(2.5, .6, str)

fig2 = figure(2)
fig2 = out.PID_controller.plot()
xlabel("Time (sec)")
ylabel("Theta (rad)")
title("3.3 PID Controller Step Response")
S = stepinfo(out.PID_controller.Data, out.tout, 1)
% Unpack S for values
values = [S.Overshoot, S.SettlingTime, (1-out.PID_controller.Data(end))]
str = sprintf("Overshoot: %f%%\nSettling time: %f\nSteady State Error: %f%%", values) 
text(2.5, .6, str)

%% 3.4
out = sim("PS4_sim2.slx", 5);
fig3 = figure(3)
fig3 = out.PV_controller.plot()
xlabel("Time (sec)")
ylabel("Theta (rad)")
title("3.4 PV Controller Step Response")
S = stepinfo(out.PV_controller.Data, out.tout, 1)
% Unpack S for values
values = [S.Overshoot, S.SettlingTime, (1-out.PV_controller.Data(end))]
str = sprintf("Overshoot: %f%%\nSettling time: %f\nSteady State Error: %f%%", values) 
text(2.5, .6, str)

fig4 = figure(4)
fig4 = out.PIV_controller.plot()
xlabel("Time (sec)")
ylabel("Theta (rad)")
title("3.4 PIV Controller Step Response")
S = stepinfo(out.PIV_controller.Data, out.tout, 1)
% Unpack S for values
values = [S.Overshoot, S.SettlingTime, (1-out.PIV_controller.Data(end))]
str = sprintf("Overshoot: %f%%\nSettling time: %f\nSteady State Error: %f%%", values) 
text(2.5, .6, str)
%% 3.5
disturbance_amplitude = .3

out = sim("PS4_sim3.slx", 5);
fig5 = figure(5)
fig5 = out.PV_controller.plot()
xlabel("Time (sec)")
ylabel("Theta (rad)")
title("3.5 PV Controller Step Response")
S = stepinfo(out.PV_controller.Data, out.tout, 1)
% Unpack S for values
values = [S.Overshoot, S.SettlingTime, (1-out.PV_controller.Data(end))]
str = sprintf("Overshoot: %f%%\nSettling time: %f\nSteady State Error: %f%%", values) 
text(2.5, .6, str)

fig6 = figure(6)
fig6 = out.PIV_controller.plot()
xlabel("Time (sec)")
ylabel("Theta (rad)")
title("3.5 PIV Controller Step Response")
S = stepinfo(out.PIV_controller.Data, out.tout, 1)
% Unpack S for values
values = [S.Overshoot, S.SettlingTime, (1-out.PIV_controller.Data(end))]
str = sprintf("Overshoot: %f%%\nSettling time: %f\nSteady State Error: %f%%", values) 
text(2.5, .6, str)