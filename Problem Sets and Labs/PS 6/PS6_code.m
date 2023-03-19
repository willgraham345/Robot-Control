%% PS5
%% 1.1 Controller
clear; close all; clc; format compact
sprintf("1.1")
% Load PD Control values from last homework
Kd = 0.27;
Kp = 8.4049;
%% 1.2 Controller
clear; close all; clc; format compact
Problem = sprintf("1.2")
Kd = 0.2699;
Kp = 8.4049;

%% 1.3 Controller
clear; close all; clc; format compact
Problem = sprintf("1.3")    
Kd = 0.2699;
Kp = 8.4049;

%% 2.1
clear; close all; clc;  format compact;
OS_des = .1;
ts_des = .2;
zeta = -log(OS_des) / (sqrt(pi^2 +(log(OS_des))^2));

omegaN = 4 / (zeta*ts_des)

omegaD = omegaN*sqrt(1-zeta^2)

Kp = omegaN^2
Kd = 2*zeta*omegaN

% Satisfying the angle conditon
theta1 = atan2d(omegaD, -zeta*omegaN)
theta2 = -180 + 2*theta1

x = omegaD / (tand(theta2)) + zeta*omegaN