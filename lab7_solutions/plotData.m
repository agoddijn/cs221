Data = readtable('Q3data.csv');
linear = Data(strcmp(Data.Type, 'l'), {'load' 'probeRate'});
quadratic = Data(strcmp(Data.Type, 'q'), {'load' 'probeRate'});
double1 = Data(strcmp(Data.Type, 'd1'), {'load' 'probeRate'});
double2 = Data(strcmp(Data.Type, 'd2'), {'load' 'probeRate'});
double3 = Data(strcmp(Data.Type, 'd3'), {'load' 'probeRate'});

plot(linear.load, linear.probeRate, 'r',...
    quadratic.load, quadratic.probeRate, 'g',...
    double1.load, double1.probeRate, 'b',...
    double2.load, double2.probeRate, 'c',...
    double3.load, double3.probeRate, 'm');

legend('linear', 'quadratic', 'double1', 'double2', 'double3');
xlabel('load');
ylabel('probe rate');
title('Graph of load vs probe rate');