%% Q1 - Open Loop Control

figure()
plot(theta.time,theta.signals.values, 'b')
xlabel('Time [sec]')
ylabel('Theta [deg]')
title('Open-Loop Control')

%% Q2

figure()
hold on
plot(theta.time,theta.signals.values, 'b')
plot(theta.time,(rad2deg(.4))*ones(length(theta.time)),'r--')
xlabel('Time [sec]')
ylabel('Theta [deg]')
title('Closed Loop Porportional Control: Gain of P = 2')
legend("Response","Desired Angle")
hold off

stepinfo(theta.signals.values,theta.time)

%% Q3

figure()
hold on
plot(theta.time,theta.signals.values, 'b')
plot(theta.time,(rad2deg(.2))*ones(length(theta.time)),'r--')
xlabel('Time [sec]')
ylabel('Theta [deg]')
title('PV Control with HW Gains: P-Gain = 8.2, V-Gain = 0.27')
legend("Step Response","Desired Angle")
hold off

stepinfo(theta.signals.values,theta.time)

%% Q4

figure()
hold on
plot(theta.time,theta.signals.values, 'b')
plot(theta.time,(rad2deg(.2))*ones(length(theta.time)),'r--')
xlabel('Time [sec]')
ylabel('Theta [deg]')

title('PIV with HW Gains: P-Gain = 11.75, I-Gain = 97, V-Gain = 0.356')
legend("Response","Desired Angle")
hold off

stepinfo(theta.signals.values,theta.time)