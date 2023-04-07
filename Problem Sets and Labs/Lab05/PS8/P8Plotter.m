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
axis equal
axis([0.12 0.28 -0.105 0.055])

%Add the circle speed to the plot
text(.175,0.035, sprintf("Wall Stiffness: %.1f", stiffness))

%%
x = F.signals.values(:,1);
y = F.signals.values(:,2);
maxy = max(y);

figure(2)
%plot joint errors vs time 
plot(F.time , x, 'b')
grid on
grid minor
hold on 
plot(F.time , y, 'r')
ylabel("Force [N]")
xlabel("Time [s]")
title("Force vs Time")
legend("X Force", "Y Force")

%Add the circle speed to the plot
text(.175,0.035, sprintf("Max Force in Y: %.1f", maxy))