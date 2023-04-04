%Zachary Orton Plotting Script
close all
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
text(.02,0.02, sprintf("Speed: %.1f", speed(1)))

%%
%Get joint errors in degrees
% jerrDeg = rad2deg(errors.signals.values);
% Jointerror1 = jerrDeg(:,1);
% Jointerror2 = jerrDeg(:,2);
% 
% % Root Mean Squared Errors & Max Errors
% RMSE1 = sqrt(mean((Jointerror1).^2));  
% RMSE2 = sqrt(mean((Jointerror2).^2)); 
% RMSE = [RMSE1 , RMSE2];
% MaxError1 = max(abs(Jointerror1));
% MaxError2 = max(abs(Jointerror2));
% MaxError = [MaxError1, MaxError2];
% 
% figure(2)
% %plot joint errors vs time 
% plot(errors.time , Jointerror1, 'b')
% grid on
% grid minor
% hold on 
% plot(errors.time , Jointerror2, '--r')
% ylabel("Error [Deg]")
% xlabel("Time [s]")
% title("Joint Errors vs Time")
% legend("Joint 1", "Joint 2")
% %add text about speed 
% text(0.09, -MaxError(1)*.95, sprintf("Speed: %.1f", speed(1)))
% text(1, -MaxError(1)*.75 , sprintf("RMS Error = [%.3f°,%.3f°]", RMSE(1), RMSE(2)))
% text(1, -MaxError(1)*.85, sprintf("Max Error = [%.3f°,%.3f°]", MaxError(1), MaxError(2)))

%%
%OpS Error

Opserror1 = OpsError.signals.values(:,1);
Opserror2 = OpsError.signals.values(:,2);

% Root Mean Squared Errors & Max Errors
ORMSE1 = sqrt(mean((Opserror1).^2));  
ORMSE2 = sqrt(mean((Opserror2).^2)); 
ORMSE = [ORMSE1 , ORMSE2];
MaxOpsError1 = max(abs(Opserror1));
MaxOpsError2 = max(abs(Opserror2));
MaxOpsError = [MaxOpsError1, MaxOpsError2];

figure(3)
plot(OpsError.time, Opserror1, 'b')
grid on 
grid minor
hold on 
plot(OpsError.time, Opserror2, '--r')
ylabel("Op-Space Error [Deg]")
xlabel("Time [s]")
title("Op-Space Errors vs Time")
legend("OpS Error 1", "Ops Error 2")

text(0.09, MaxOpsError(1)*.95, sprintf("Speed: %.1f", speed(1)))
text(1, MaxOpsError(1)*.85 , sprintf("RMS Error = [%.3f,%.3f]", ORMSE(1), ORMSE(2)))
text(1, MaxOpsError(1)*.75, sprintf("Max Error = [%.3f,%.3f]", MaxOpsError(1), MaxOpsError(2)))