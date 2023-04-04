%%Plotting Script

close all
%Plot desired and actual end effector trajectory 
figure(1)
plot(xy(:,1) , xy(:,2), 'b')
grid on
grid minor
hold on 
plot(xy_d(:,1) , xy_d(:,2), '--r')
ylabel("Y [m]")
xlabel("X [m]")
title({"RC in Op-Space", "End Effector Trajectory", "f = 1 circles/second"});
legend("Actual", "Desired")
axis([0 0.25 0 0.2])

%Add the circle speed to the plot
% text(.02,0.02, sprintf("Speed: %.1f", speed))

%% 

% Get joint errors in degrees
jerrDeg = rad2deg(errors.signals.values);
Jointerror1 = jerrDeg(:,1);
Jointerror2 = jerrDeg(:,2);

% % Root Mean Squared Errors & Max Errors
RMSE1 = sqrt(mean((Jointerror1).^2))
RMSE2 = sqrt(mean((Jointerror2).^2)) 
% RMSE = [RMSE1 , RMSE2];
MaxError1 = max(abs(Jointerror1));
MaxError2 = max(abs(Jointerror2));
MaxError = [MaxError1, MaxError2]
% MinError = min([Jointerror1, Jointerror2]);
% AvgError = mean([abs(Jointerror1), abs(Jointerror2)])
% data = cat(1, MaxError, AvgError)
error_str = sprintf("                 Joint1   Joint2 \nMax Error: %.3f°, %.3f° \nRMS Error: %.3f° %.3f°", [MaxError1, MaxError2, RMSE1, RMSE2])
figure(2)
%plot joint errors vs time 
plot(errors.time , Jointerror1, 'b')
grid on
grid minor
hold on 
plot(errors.time , Jointerror2, '--r')
ylabel("Error [deg]")
xlabel("Time [s]")
title({"RC in Op-Space", "Joint Errors vs Time", "f = 1 circles/second"})
legend("Joint 1", "Joint 2")
dim = [0.65, 0.15, 0.1, 0.1];
t = annotation('textbox', dim, 'String', error_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)

%%
% Get errors 

x_err = OpsError.signals.values(:,1);
y_err = OpsError.signals.values(:,2);



% % Root Mean Squared Errors & Max Errors
RMSE1 = sqrt(mean((x_err).^2))
RMSE2 = sqrt(mean((y_err).^2)) 
% RMSE = [RMSE1 , RMSE2];
MaxError1 = max(abs(x_err));
MaxError2 = max(abs(y_err));
MaxError = [MaxError1, MaxError2];
% MinError = min([x_err, y_err]);
% AvgError = mean([abs(x_err), abs(y_err)])
% data = cat(1, MaxError, AvgError)
error_str = sprintf("                   X       Y \nMax Error: %.3f, %.3f \nRMS Error: %.3f %.3f", [MaxError1, MaxError2, RMSE1, RMSE2])
figure(3)
%plot joint errors vs time 
plot(x_err, 'b')
grid on
grid minor
hold on 
plot(y_err, '--r')
ylabel("Error [m]")
xlabel("Time [s]")
title({"RC in Op-Space", "XY Errors vs Time", "f = 1 circles/second"})
legend("X", "Y")
dim = [0.65, 0.15, 0.1, 0.1];
t = annotation('textbox', dim, 'String', error_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)
