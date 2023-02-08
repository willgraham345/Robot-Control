syms t1 a1 t2 a2


T_01 = DH_matrix(a1, 0, 0, t1)
T_12 = DH_matrix(a2, 0, 0, t2)

T_02 = T_01*T_12

xy = T_02(1:2, 4)

J = jacobian(xy, [t1, t2])
function T = DH_matrix(a, d, alpha, theta)
    T = [cos(theta) -sin(theta)*cos(alpha) sin(theta)*sin(alpha) a*cos(theta);
         sin(theta) cos(theta)*cos(alpha) -cos(theta)*sin(alpha) a*sin(theta);
         0 sin(alpha) cos(alpha) d;
         0 0 0 1];
end
