%% Loading Template
STOP = imread('imgSTOP2.jpeg');
grayStop = rgb2gray(STOP);
%% Loading imput image and converting it into grayscal image
Image = imread('img2.jpeg');
grayImage = rgb2gray(Image);
%% Setup and perform Template Matching
H = vision.TemplateMatcher;
H.SearchMethod = 'Three-step';
loc = step(H,grayImage,grayStop);
%% Visualise Results
J = insertMarker(Image,loc,'*','Size',15,'Color','red');
imshow(J)