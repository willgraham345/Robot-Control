%% PS5
%% 1.1 Controller
clear; close all; clc; format compact
sprintf("1.1")
% Load PD Control values from last homework
Kd = 0.2699;
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
OS_des = .1;
ts_des = .2;
zeta = -log(OS_des) / (sqrt(pi^2 +(log(OS_des))^2))

omegaN_des = 4 / (zeta*ts_des)

omegaD_des = omegaN_des*sqrt(1-zeta^2)