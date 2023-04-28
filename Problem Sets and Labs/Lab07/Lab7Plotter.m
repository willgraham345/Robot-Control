%Zachary Orton Plotting Script
close all


%% Joint space Errors
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

XYserror1 = poserror.signals.values(:,1)*1000; %mm
XYserror2 = poserror.signals.values(:,2)*1000; %mm

% Root Mean Squared Errors & Max Errors
ORMSE1 = sqrt(mean((XYserror1).^2));  
ORMSE2 = sqrt(mean((XYserror2).^2)); 
ORMSE = [ORMSE1 , ORMSE2]; %mm
MaxOpsError1 = max(abs(XYserror1));
MaxOpsError2 = max(abs(XYserror2));
MaxOpsError = [MaxOpsError1, MaxOpsError2]; %mm

figure(1)

hold on
plot(poserror.time, XYserror1, 'b')
grid on 
grid minor 
plot(poserror.time, XYserror2, '--r')
ylabel("Error [mm]")
xlabel("Time [s]")
legend("X", "Y")

kw_string = "kw = " + num2str(kw) + " N/mm"
title({"Bilateral Servo in Joint Space", "Op-Space Error", kw_string});
error_str = sprintf("                   X       Y \nMax Error: %.3f, %.3f \nRMS Error: %.3f %.3f", [MaxOpsError1, MaxOpsError2, ORMSE1, ORMSE2])

dim = [0.65, 0.15, 0.1, 0.1];
t = annotation('textbox', dim, 'String', error_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)


%text(1,0, sprintf("Wall Stiffness: %.1f", stiffness))
% text(4, 0 , sprintf("RMS Error = [%.3f] mm", ORMSE(1)))
% text(4, -2, sprintf("Max Error = [%.3f] mm", MaxOpsError(1)))
%text(4, 10, sprintf("Speed: %.1f", speed(1,1)))
%%
fx = Force.signals.values(:,1);
fy = Force.signals.values(:,2);
Fmax = max(abs(fy));
RMSF1 = sqrt(mean((fx).^2))
RMSF2 = sqrt(mean((fy).^2)) 
% RMSE = [RMSE1 , RMSE2];
MaxForce1 = max(abs(fx));
MaxForce2 = max(abs(fy));
MaxForce = [MaxForce1, MaxForce2];

figure(2)
%plot joint errors vs time 
plot(Force.time , fx, 'b')
grid on
grid minor
hold on 
plot(Force.time , fy, 'r')
ylabel("Force [N]")
xlabel("Time [s]")
title("Force vs Time")
legend("Fx", "Fy")
title({"Bilateral Servo in Joint Space", "Force Feedback", kw_string});
force_str = sprintf("                   X       Y \nMax Force: %.3f, %.3f \nRMS Force: %.3f %.3f", [MaxForce1, MaxForce2, RMSF1, RMSF2])
dim = [0.65, 0.15, 0.1, 0.1];

t = annotation('textbox', dim, 'String', force_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 8)
%%
