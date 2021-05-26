clc;
clear all;
close all;
am=1;                        % amplitude of modulating signal
ac=1;                        % amplitude of carrier signal
fm=500;                      % modulating signal frequency
fc=5000;                     % carrier frequency
fs=100000;                   % sampling frequency
ts=1/fs;                     % sampling interval
N=10000;                     % number of samples
t=(-N/2:1:(N/2-1))*ts;       % time interval
m=am*cos(2*pi*fm*t);         % modulating signal
mh=am*sin(2*pi*fm*t);        % hilbert transformation for message signal
c=ac*cos(2*pi*fc*t);         % carrier signal
ch=ac*sin(2*pi*fc*t);        % hilbert transform for carrier signal
st=m.*c-mh.*ch;              % SSB-sc signal

% time domain of all signals
subplot(3,2,1);
plot(t,m,'red','linewidth',1.5);
axis([0 0.005 -2.5 2.5]);
xlabel('time');
ylabel('amplitude');
title('modulating signal');
grid on;

subplot(3,2,3);
plot(t,c,'black','linewidth',1.5);
axis([0 0.005 -2.5 2.5]);
xlabel('time');
ylabel('amplitude');
title('carrier signal');
grid on;

subplot(3,2,5);
plot(t,st,'blue','linewidth',1.5);
axis([0 0.005 -2.5 2.5]);
xlabel('time');
ylabel('amplitude');
title('modulated signal');
grid on;

% spectrums of all signals

f=(-N/2:1:(N/2-1))*fs/N;
M=abs((2/N)*fftshift(fft(m)));
C=abs((2/N)*fftshift(fft(c)));
SF=abs((2/N)*fftshift(fft(st)));
subplot(3,2,2);
plot(f,M/max(M),'red','linewidth',1.5);
axis([-2*fc 2*fc -0.1 1.1]);
xlabel('frequency');
ylabel('amplitude');
title('modulating signal');
grid on;

subplot(3,2,4);
plot(f,C/max(C),'black','linewidth',1.5);
axis([-2*fc 2*fc -0.1 1.1]);
xlabel('frequency');
ylabel('amplitude');
title('carrier signal');
grid on;

subplot(3,2,6);
plot(f,SF/max(SF),'blue','linewidth',1.5);
axis([-2*fc 2*fc -0.1 1.1]);
xlabel('frequency');
ylabel('amplitude');
title('modulating signal');
grid on;