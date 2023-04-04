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
title({"Admittance Control", "End Effector Trajectory", "kw = 10 N/mm"});
legend("Actual", "Desired")
origin = [0.2, -0.025];
offset = .1;
axis([origin(1)-offset, origin(1)+offset, origin(2)-offset, origin(2)+offset])

%Add the circle speed to the plot
% text(.02,0.02, sprintf("Speed: %.1f", speed))

%%
% Get errors 
err = xy_d - xy;
x_err = err(:,1);
y_err = err(:,2);
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
figure(2)
%plot joint errors vs time 
plot(t, x_err, 'b')
grid on
grid minor
hold on 
plot(t, y_err, '--r')

ylabel("Error [m]")
xlabel("Time [s]")
title({"Admittance Control", "XY Errors vs Time", "kw = 10 N/mm"})
legend("X", "Y")
dim = [0.65, 0.15, 0.1, 0.1];
t = annotation('textbox', dim, 'String', error_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)


%%

% Get Forces
f = Forces.signals.values;
t = Forces.time;
fx = f(:,1);
fy = f(:,2);


%
figure(3)
plot(t, fx, 'b')
grid on
grid minor
hold on 
plot(t, fy, '--r');
ylabel("Force [N]")
xlabel("Time [s]")
title({"Admittance Control", "Force vs Time", "kw = 10 N/mm"});
legend("X", "Y")
RMSF1 = sqrt(mean((fx).^2))
RMSF2 = sqrt(mean((fy).^2)) 
% RMSE = [RMSE1 , RMSE2];
MaxForce1 = max(abs(fx));
MaxForce2 = max(abs(fy));
MaxForce = [MaxError1, MaxError2];
force_str = sprintf("                   X       Y \nMax Force: %.3f, %.3f \nRMS Force: %.3f %.3f", [MaxForce1, MaxForce2, RMSF1, RMSF2])
dim = [0.65, 0.15, 0.1, 0.1];

t = annotation('textbox', dim, 'String', force_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)
