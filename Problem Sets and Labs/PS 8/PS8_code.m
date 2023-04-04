%% PS8 CODE

% Solve for Kp 

%Max force is 3N


% import jacobian
J11 = -a1*sin(phi(1));
J12 = -a2*sin(phi(2));
J21 = a1*cos(phi(1));
J22 = a2*cos(phi(2));

J = [J11 J12; J21 J22];

inv(J')

Kp = []
%%
