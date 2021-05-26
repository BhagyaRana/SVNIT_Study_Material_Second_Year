clc;
close all                         %for closing all the window except command window
clear all                         %for deleting all the variables from the memory
fc1=input('Enter the freq of 1st Sine Wave carrier:');
fp=input('Enter the freq of Periodic Binary pulse (Message):');
amp=input('Enter the amplitude (For Both Carrier & Binary Pulse Message):');
amp=amp/2;
t=0:0.001:1;                       % For setting the sampling interval
c1=amp.*sin(2*pi*fc1*t);           % For Generating 1st Carrier Sine wave
subplot(3,1,1);                    %For Plotting The Carrier wave
plot(t,c1)
xlabel('Time')
ylabel('Amplitude')
title('Carrier 1 Wave')
grid on;
m=square(2*pi*fp*t);       %For Generating Square wave message
subplot(3,1,2)                      %For Plotting The Square Binary Pulse (Message)
plot(t,m)
xlabel('Time')
ylabel('Amplitude')
title('Binary Message Pulses')
grid on;
for i=0:1000                        %here we are generating the modulated wave
    if (m(i+1)==1)
        s(i+1)=c1(i+1);
        else
        s(i+1)=-c1(i+1);
    end
end
subplot(3,1,3) %For Plotting The Modulated wave
plot(t,s)
xlabel('Time')
ylabel('Amplitude')
title('Modulated Wave')
grid on;