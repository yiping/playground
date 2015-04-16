clc
clear all
close all
%%
% define human block 
w = 18;
h = 32;
sigma_x = 1.0*sqrt(w);
sigma_y = 1.0*sqrt(h);
 
%% manually place the human block on the first image (i==0)
image_name = strcat(pwd,'\images\image0.bmp');
I = imread(image_name);
IMG = rgb2gray(I); 
imshow(IMG);
title(strcat('image0'));

x_center = 218; % initial position picked by hand
y_center = 158;

v_x = -0.2*w; % initial velocity guess
v_y = -0.2*h; 
    
% draw block
rectangle('Position',[x_center-0.5*w  y_center-0.5*h w h],'EdgeColor','r'); 
    
% generate random samples 
    
prior_next_x_center = x_center + v_x;
prior_next_y_center = y_center + v_y;
    
N =100; % 100 samples
X = prior_next_x_center + sigma_x*randn(N,1);
Y = prior_next_y_center + sigma_y*randn(N,1);
    
    
% calculate the histogram in the hand-picked human block
B = IMG(round(y_center)-round(0.5*h) : round(y_center)+round(0.5*h),...
     round(x_center)-round( 0.5*w) : round(x_center)+round(0.5*w) );
bin_centers = 7.5: 16: 247.5;
H0 = hist( double(sort(reshape(B,[],1))), bin_centers);
H0 = H0/sum(H0);

pause(1);

  
%% tracking
for i = 1:12
    image_name = strcat(pwd,'\images\image',num2str(i),'.bmp');
    I = imread(image_name);
    IMG = rgb2gray(I); 
    imshow(IMG);
    title(strcat('image-', num2str(i)));
    
    
    % calculate histogram for each sample
    HH=[];
    for i = 1:100
        % rectangle('Position',[X(i) - 0.5*w ...
        %                       Y(i) - 0.5*h ...
        %                       w h],'EdgeColor','g');
        B = IMG(round(Y(i))-round(0.5*h): round(Y(i))+round(0.5*h),...
                 round(X(i))-round(0.5*w): round(X(i))+round(0.5*w) );
        bin_centers = 7.5: 16: 247.5;
        H = hist( double(sort(reshape(B,[],1))), bin_centers );
        HH = [HH; H/sum(H)];                 
    end
    
    % compare histogram & calculate weight for each particle
    lambda = 40;
    W = [];
    for i = 1:100
        D = sqrt( 1 - sum( sqrt(HH(i,:).*H0) ));
        W = [W; exp(-lambda*D*D)];
    end
    W = W/sum(W);

    % low variance resampling
    XNew = []; YNew = [];

    r = rand(1)/N;
    k = 1;
    c = W(1);
    for j = 1:N
        U = r + (j-1)/N;
        while U > c
           k = k + 1;
           c = c + W(k);
        end
        XNew(j) = X(k);
        YNew(j) = Y(k);
    end

    % resampled particles
    XNew = XNew'; YNew = YNew';
    
    % update posiition (weighted sum)
    new_x_center = sum(XNew.*W);
    new_y_center = sum(YNew.*W);
    
    % update velocity 
    new_v_x = new_x_center - x_center;
    new_v_y = new_y_center - y_center;
    
    % perturb resampled particles
    X = XNew + new_v_x + sigma_x*randn(N,1);
    Y = YNew + new_v_y + sigma_y*randn(N,1);
    
    rectangle('Position',[new_x_center - 0.5*w ...
                        new_y_center-0.5*h w h],'EdgeColor','b');
                                    
    % update the reference histogram 
    x_center = new_x_center;
    y_center = new_y_center;
    B = IMG(round(y_center)-round(0.5*h) : round(y_center)+round(0.5*h),...
         round(x_center)-round( 0.5*w) : round(x_center)+round(0.5*w) );
    bin_centers = 7.5: 16: 247.5;
    H0 = hist(  double(sort(reshape(B,[],1))), bin_centers);
    H0 = H0/sum(H0);
    
    pause(1);
end




