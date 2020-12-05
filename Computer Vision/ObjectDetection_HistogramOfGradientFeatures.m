%% Load input and view image
stop = imread('img1.jpeg');
imshow(stop)
%% Extract HOG Features
[hog16, vis16] = extractHOGFeatures(stop,'CellSize',[16 16]);
%% Visualize results
hold on
plot(vis16)