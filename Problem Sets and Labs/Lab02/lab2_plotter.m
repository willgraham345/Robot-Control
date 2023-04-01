%% Lab 2 Code

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
title({"2.1", "End Effector Trajectory", "f = 1 circles/second"});
legend("Actual", "Desired")
axis([0 0.25 0 0.2])

%Add the circle speed to the plot
% text(.02,0.02, sprintf("Speed: %.1f", speed))

%%
%Get joint errors in degrees
jerrDeg = rad2deg(errors.signals.values);
Jointerror1 = squeeze(jerrDeg(1,:,:));
Jointerror2 = squeeze(jerrDeg(2,:,:));

% Root Mean Squared Errors & Max Errors
RMSE1 = sqrt(mean((Jointerror1).^2));  
RMSE2 = sqrt(mean((Jointerror2).^2)); 
RMSE = [RMSE1 , RMSE2];
MaxError1 = max(abs(Jointerror1));
MaxError2 = max(abs(Jointerror2));
MaxError = [MaxError1, MaxError2];
MinError = min([Jointerror1, Jointerror2]);
AvgError = mean([Jointerror1, Jointerror2])
data = cat(1, MaxError, RMSE);
error_str = sprintf("               Joint 1 Joint 2 \nMax Error: %.3f°, %.3f° \nRMS Error: %.3f° %.3f°", data)
figure(2)
%plot joint errors vs time 
plot(errors.time , Jointerror1, 'b')
grid on
grid minor
hold on 
plot(errors.time , Jointerror2, '--r')
ylabel("Error [Deg]")
xlabel("Time [s]")
title({"2.1", "Joint Errors vs Time", "f = 1 circles/second"})
legend("Joint 1", "Joint 2")
dim = [0.65, 0.15, 0.1, 0.1];
t = annotation('textbox', dim, 'String', error_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)


%add text about speed 
%text(0.09,-3, sprintf("Speed: %.1f", speed))
% text(1, -2, sprintf("RMS Error = [%.3f°,%.3f°]", RMSE(1), RMSE(2)))
% text(1, -2.5, sprintf("Max Error = [%.3f°,%.3f°]", MaxError(1), MaxError(2)))


