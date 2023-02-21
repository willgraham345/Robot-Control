%% Graphing for MOS %%
close all;
% XY Actual vs Desired
fig1 = figure;
plot(xy(:,1), xy(:,2), 'b')
hold on
plot(xy_d(:,1), xy(:,2), '--r')
str = sprintf("XY\n Acutal vs Desired");
title(str)
xlabel("X [m]")
ylabel("Y [m]")
legend("Actual Positoin", "Desired Position")


%% Analyze Error
x_err = errors.signals.values(:,1);
y_err = errors.signals.values(:,2);
max_err = max([x_err, y_err]);
min_err = min([x_err, y_err]);
avg_err = mean([x_err, y_err]);
rms_err = rms([x_err, y_err]);
data = cat(1, max_err, min_err, avg_err, rms_err);
error_str = sprintf("                          X   Y\nMax Error: %.3f%% %.3f %%\nMin Error: %.3f%% %.3f%%\nAvg Error: %.3f%% %.3f%%\nRMS Error: %.3f%% %.3f%%", data);
fig2 = figure;
plot(errors.time, x_err, 'b')
hold on
plot(errors.time, y_err, 'r')

str = sprintf("Errors vs Time");
title(str)
xlabel("X [m]")
ylabel("Y [m]")
legend("X Error", "Y Error", 'Location','Northeast')
dim = [0.65, 0.2, 0.1, 0.1];
t = annotation('textbox', dim, 'String', error_str, 'FitBoxToText','on', 'BackgroundColor', "w", "FontSize", 7)
