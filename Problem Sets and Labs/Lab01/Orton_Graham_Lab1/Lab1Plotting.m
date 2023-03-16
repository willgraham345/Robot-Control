%% Q1 - Open Loop Control

figure()
plot(theta.time,theta.signals.values, 'b')
xlabel('Time (sec)')
ylabel('Theta (deg)')
title('Open-Loop Control')

%% Q2
close all; format compact;
figure()
hold on
plot(theta.time,theta.signals.values, 'b')
plot(theta.time,(rad2deg(.4))*ones(length(theta.time)),'r--')
xlabel('Time (sec)')
ylabel('Theta (deg)')
title('Closed Loop Porportional Control: Gain of Kp = 0.75')
legend("Response","Desired Angle")
hold off

stepinfo(theta.signals.values,theta.time)

%% Q3
close all; format compact;
figure()
hold on
plot(theta.time,theta.signals.values, 'b')
plot(theta.time,(rad2deg(.2))*ones(length(theta.time)),'r--')
xlabel('Time (sec)')
ylabel('Theta (deg)')
title('PV Control with Tuned Gains: Kp-Gain = 8.5, V-Gain = 0.3')
legend("Step Response","Desired Angle")
hold off

stepinfo(theta.signals.values,theta.time)

%% Q4
close all; format compact

figure()
hold on
plot(theta.time,theta.signals.values, 'b')
plot(theta.time,(rad2deg(.2))*ones(length(theta.time)),'r--')
xlabel('Time (sec)')
ylabel('Theta (deg)')

title('PIV with Experimental Gains: Kp-Gain = 8.5, V-Gain = 0.3, Ki-Gain = 50')
legend("Response","Desired Angle")
hold off

stepinfo(theta.signals.values,theta.time)