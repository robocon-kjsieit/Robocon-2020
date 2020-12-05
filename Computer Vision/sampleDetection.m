vidReader1 = vision.VideoFileReader('sample2.mp4');
vidFrame1 = step(vidReader1);
subplot(1,3,1)
imshow(vidFrame1)
% Convert RGB image to chosen color space
I = rgb2hsv(vidFrame1);

% Define thresholds for channel 1 based on histogram settings
channel1Min = 0.947;
channel1Max = 0.020;

% Define thresholds for channel 2 based on histogram settings
channel2Min = 0.641;
channel2Max = 1.000;

% Define thresholds for channel 3 based on histogram settings
channel3Min = 0.000;
channel3Max = 1.000;

% Create mask based on chosen histogram thresholds
sliderBW = ( (I(:,:,1) >= channel1Min) | (I(:,:,1) <= channel1Max) ) & ...
    (I(:,:,2) >= channel2Min ) & (I(:,:,2) <= channel2Max) & ...
    (I(:,:,3) >= channel3Min ) & (I(:,:,3) <= channel3Max);
BW = sliderBW;
subplot(1,3,2)
imshow(BW)
octaelement = strel('octagon',3);
octaimg = imopen(BW,octaelement);
subplot(1,3,3)
imshow(octaimg)
hBlobAnalysis = vision.BlobAnalysis('MinimumBlobArea',200,'MaximumBlobArea',5000);
[objArea,ObjectCentroid,bboxOut] = step(hBlobAnalysis,octaimg);
Ishape = insertShape(vidFrame1,'rectangle',bboxOut,'Linewidth',4);
subplot(1,2,1)
imshow(Ishape)
release(hBlobAnalysis)