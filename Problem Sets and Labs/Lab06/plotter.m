%% Desired and actual end effector x traj

close all
%Plot desired and actual end effector trajectory 
speed = speed(1);
figure(1)
plot(xy.time , xy.signals.values(:,1), 'b')
hold on
grid on
grid minor
grid minor
plot(xy_d.time , xy_d.signals.values(:,1), '--r')

ylabel("X Position [m]")
xlabel("time [sec]")
speed_str = "f = " + num2str(speed) + ' circles/sec'
title({"Hybrid PI Control", "Trajectory & Desired Trajectory vs Time", speed_str});
legend({'Actual Position', 'Desired Position'})
hold off

%% X Errors vs time 
x_err = XYErrors.signals.values(:,1)
y_err = XYErrors.signals.values(:,2)
% t = xy_errors.time;


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
error_str = sprintf("Error Performance     \nMax Error: %.3f \nRMS Error: %.3f", [MaxError1, RMSE1])
figure(2)
%plot joint errors vs time 
plot(XYErrors.time, x_err, 'b')
grid on
grid minor
hold on 

ylabel("Error [m]")
xlabel("Time [s]")
title({"Hybrid PI Control", "X Errors vs Time", speed_str})
dim = [0.65, 0.15, 0.1, 0.1];
annotation_val = annotation('textbox', dim, 'String', error_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)
hold off


%%

% Get Forces
f = F.signals.values;
t = F.time;
fx = F.signals.values(:,1);
fy = F.signals.values(:,2);


%
figure(3)
% plot(t, fx, 'b')
grid on
grid minor
hold on 
plot(t, fy);
ylabel("Force [N]")
xlabel("Time [s]")
title({"Hybrid PI Control", "Y Force vs Time", speed_str});
% legend("X", "Y")
RMSF1 = sqrt(mean((fx).^2))
RMSF2 = sqrt(mean((fy).^2)) 
% RMSE = [RMSE1 , RMSE2];
MaxForce1 = max(abs(fx));
MaxForce2 = max(abs(fy));
MaxForce = [MaxForce1, MaxForce2];
force_str = sprintf("Force Performance     \nMax Force: -%.3f N \nRMS Force: -%.3f N", [MaxForce2, RMSF2]);
% force_str = sprintf("                   X       Y \nMax Force: %.3f, %.3f \nRMS Force: %.3f %.3f", [MaxForce1, MaxForce2, RMSF1, RMSF2])
dim = [0.65, 0.15, 0.1, 0.1];

t = annotation('textbox', dim, 'String', force_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)


