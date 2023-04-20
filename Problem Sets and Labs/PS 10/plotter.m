%% Desired and actual end effector x traj

close all
%Plot desired and actual end effector trajectory 

figure(1)
x = xy.signals.values(:,1);
y = xy.signals.values(:,2);
t = xy.time;
grid on
grid minor
plot(x, y, 'b')
grid on
grid minor
hold on
x_des = xy_d.signals.values(:,1)
y_des = xy_d.signals.values(:,2)
plot(x_des, y_des, '--r')

ylabel("X Position [m]")
xlabel("Y Position [sec]")
stiffness_str = "kw = " + num2str(kw) + " N/mm";
fd_str = "f_{des} = " + num2str(f_desired) + " N" ;
y_rel_val = double(y_rel(1))
yrel_str = "y_{rel} = "+ num2str(y_rel_val) + " m"
title({"Coordinated Motion", "Position of Block", yrel_str});
legend({'Actual Position', 'Desired Position'})


%% Orientation vs Time

figure(2)
plot(alpha.time, alpha.signals.values(:))
grid on
grid minor
xlabel("Time [sec]")
ylabel("Alpha [rad]")
title({"Coordinated Motion", "Orientation of Block", yrel_str});




%% X Errors vs time 
figure(3)
x_err = xy_errors.signals.values(:,1)
y_err = xy_errors.signals.values(:,2)
t = xy_errors.time;


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

%plot joint errors vs time 
plot(t, x_err, 'b')
grid on
grid minor
hold on 
plot(t, y_err, '--r')

ylabel("Error [m]")
xlabel("Time [s]")
title({"Coordinated Motion", "XY Errors vs Time", yrel_str})
legend("X", "Y")
dim = [0.65, 0.15, 0.1, 0.1];
t = annotation('textbox', dim, 'String', error_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)


%% Internal Forces vs Time
figure(4)
% Get Forces
f = ForceErrors.signals.values;
t = ForceErrors.time;
fx = f(:,1);
fy = f(:,2);


%

plot(t, fx, 'b')
grid on
grid minor
hold on 
plot(t, fy, 'r');
ylabel("Force [N]")
xlabel("Time [s]")
title({"Coordinated Motion", "Internal Force Errors", yrel_str});
legend("X", "Y")
RMSF1 = sqrt(mean((fx).^2))
RMSF2 = sqrt(mean((fy).^2)) 
% RMSE = [RMSE1 , RMSE2];
MaxForce1 = max(abs(fx));
MaxForce2 = max(abs(fy));
MaxForce = [MaxForce1, MaxForce2];
% force_str = sprintf("Force Performance     \nMax Force: -%.3f N \nRMS Force: -%.3f N", [MaxForce1, MaxForce2, RMSF1, RMSF2]);
force_str = sprintf("                   X       Y \nMax Force: %.3f, %.3f \nRMS Force: %.3f %.3f", [MaxForce1, MaxForce2, RMSF1, RMSF2])
dim = [0.65, 0.15, 0.1, 0.1];

t = annotation('textbox', dim, 'String', force_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)

