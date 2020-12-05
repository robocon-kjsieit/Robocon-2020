%% LoadFrames
vidReader2 = vision.VideoFileReader('sample3.mp4');
vidFrame2 = step(vidReader2);
subplot(1,2,1)
imshow(vidFrame2)
title('Original Frame')
%% ConverToGray
grayFrame1 = rgb2gray(vidFrame2);
subplot(1,2,2)
imshow(grayFrame1)
title('Grayscale Frame')
%% FindFeatures
features = detectMSERFeatures(grayFrame1);
figure
subplot(1,2,1)
imshow(vidFrame2)
hold on
plot(features)
title('All Features ThresholdDelta:2')
%% FindSpecificFeatures
specFeatures = detectMSERFeatures(grayFrame1,'ThresholdDelta',4);
subplot(1,2,2)
imshow(vidFrame2)
hold on
plot(specFeatures)
title('ThresholdDelta:4')