%Zachary Orton Plotting Script

%Plot actual end effector trajectory 
figure(1)
plot(xy(:,1) , xy(:,2), 'b')
grid on
grid minor
hold on 

%Plot desired end effector trajectory
plot(xy_d(:,1) , xy_d(:,2), '--r')
ylabel("Y [m]")
xlabel("X [m]")
title("End Effector Trajectory")
legend("Actual", "Desired")
axis([0 0.25 0 0.2])

%Add the circle speed to the plot
text(.02,0.02, sprintf("Speed: %.1f", speed))

%%
%Get joint errors in degrees
jerrDeg = rad2deg(errors.signals.values);
Jointerror1 = jerrDeg(:,1);
Jointerror2 = jerrDeg(:,2);

% Root Mean Squared Errors & Max Errors
RMSE1 = sqrt(mean((Jointerror1).^2));  
RMSE2 = sqrt(mean((Jointerror2).^2)); 
RMSE = [RMSE1 , RMSE2];
MaxError1 = max(abs(Jointerror1));
MaxError2 = max(abs(Jointerror2));
MaxError = [MaxError1, MaxError2];

figure(2)
%plot joint errors vs time 
plot(errors.time , Jointerror1, 'b')
grid on
grid minor
hold on 
plot(errors.time , Jointerror2, '--r')
ylabel("Error [Deg]")
xlabel("Time [s]")
title("Joint Errors vs Time")
legend("Joint 1", "Joint 2")
%add text about speed 
text(0.09, -MaxError(1)*.95, sprintf("Speed: %.1f", speed))
text(1, -MaxError(1)*.75 , sprintf("RMS Error = [%.3f°,%.3f°]", RMSE(1), RMSE(2)))
text(1, -MaxError(1)*.85, sprintf("Max Error = [%.3f°,%.3f°]", MaxError(1), MaxError(2)))


%%

a1 = 0.15;  % link 1 length
a2 = 0.15;  % link 2 length
m1 = 0.092;  % link 1 mass  
m2 = 0.077; % link 2 mas
r01 = 0.062; % link 1 center of mass
r12 = 0.036; % link 2 COM
I1 = 0.64e-3;  % link 1 inertia
I2 = 0.30e-3;  % link 2 inertia
Jm1 = 0.65e-6; % motor inertias
Jm2 = 0.65e-6;
b1 = 3.1e-6; % viscous damping constants
b2 = 3.1e-6;
c1 = 0.0001; % coulomb friction constants
c2 = 0.0001;
g = 9.8; % gravitational constant
N1 = 70; % gear ratios
N2 = 70;


aa1 = (N1^2)*Jm1 + I1 + m2*(a1^2); %Yellow
a2 = r12*m2; %Blue
a3 = r01*m1 +a1*m2; %Orange
a4 = (N2^2)*Jm2 +I2; %Green

figure(3)
yline(aa1, '--', 'color', [0.9290 0.6940 0.1250])
hold on 
yline(a2, '--', 'color', [0 0.4470 0.7410])
yline(a3, '--', 'color', [0.8500 0.3250 0.0980]) %orange
yline(a4, '--', 'color', [0.4660 0.6740 0.1880])
plot(params.time, params.signals.values(:,1), 'color', [0.9290 0.6940 0.1250])
plot(params.time, params.signals.values(:,2), 'color', [0 0.4470 0.7410])
plot(params.time, params.signals.values(:,3), 'color', [0.8500 0.3250 0.0980])
plot(params.time, params.signals.values(:,4), 'color', [0.4660 0.6740 0.1880])
grid on
grid minor
ylabel("Parameter Estimates")
xlabel("Time [s]")
title("Parameter Estimates vs Time")
legend("alpha1", "alpha2","alpha3","alpha4","alphahat1","alphahat2","alphahat3","alphahat4")
