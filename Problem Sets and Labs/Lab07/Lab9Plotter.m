%Zachary Orton Plotting Script
close all
% %Plot actual end effector trajectory 
% figure(1)
% plot(xy.time , xy.signals.values(:,1), 'b')
% grid on
% grid minor
% hold on 
% 
% %Plot desired end effector trajectory
% plot(xy_d.time , xy_d.signals.values(:,1), '--r')
% ylabel("X [m]")
% xlabel("Time [s]")
% title("X-Position vs Time")
% legend("X-Postion", "Desired")
% %axis equal
% %axis([0.12 0.28 -0.105 0.055])
% 
% %Add the stiffness to the plot
% text(4,.24, sprintf("Speed: %.1f", speed(1,1)))
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

figure(2)

hold on
plot(poserror.time, XYserror1, 'b')
grid on 
grid minor 
plot(poserror.time, XYserror2, '--r')
ylabel("Error [mm]")
xlabel("Time [s]")
title("Tracking Errors vs Time")
legend("X", "Y")

%text(1,0, sprintf("Wall Stiffness: %.1f", stiffness))
text(4, 0 , sprintf("RMS Error = [%.3f] mm", ORMSE(1)))
text(4, -2, sprintf("Max Error = [%.3f] mm", MaxOpsError(1)))
%text(4, 10, sprintf("Speed: %.1f", speed(1,1)))
%%
Fx = Force.signals.values(:,1);
Fy = Force.signals.values(:,2);
Fmax = max(abs(Fy));

figure(3)
%plot joint errors vs time 
plot(Force.time , Fx, 'b')
grid on
grid minor
hold on 
plot(Force.time , Fy, 'r')
ylabel("Force [N]")
xlabel("Time [s]")
title("Force vs Time")
legend("Fy")

%text(1,-1, sprintf("Wall Stiffness: %.1f", stiffness))
text(4, 0, sprintf("Max Force = [-%.1f]", Fmax))
%text(4, .15, sprintf("Speed: %.1f", speed(1,1)))
%%
%Force Error

% Ferror1 = ForceErrors.signals.values(:,1);
% Ferror2 = ForceErrors.signals.values(:,2);
% 
% % Root Mean Squared Errors & Max Errors
% ORMSE1 = sqrt(mean((Ferror1).^2));  
% ORMSE2 = sqrt(mean((Ferror2).^2)); 
% ORMSE = [ORMSE1 , ORMSE2];
% MaxFError1 = max(abs(Ferror1));
% MaxFError2 = max(abs(Ferror2));
% MaxFError = [MaxFError1, MaxFError2];
% 
% figure(4)
% plot(ForceErrors.time, Ferror1, 'b')
% grid on 
% grid minor
% hold on 
% plot(ForceErrors.time, Ferror2, 'r')
% ylabel("Force Error [Deg]")
% xlabel("Time [s]")
% title("Force Errors vs Time")
% legend("Force Error X" ,"Force Error Y")
% 
% %text(1,-1, sprintf("Wall Stiffness: %.1f", stiffness))
% %text(0.09, MaxFError(1)*.95, sprintf("Speed: %.1f", speed))
% %text(1, -MaxFError(2)*.85 , sprintf("RMS Error = [-%.3f]",ORMSE(2)))
% text(1, -MaxFError(2)*.75, sprintf("Max Y Error = -%.3f N", MaxFError(2)))
