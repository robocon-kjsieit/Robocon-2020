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
features = detectMinEigenFeatures(grayFrame1);
figure
subplot(1,2,1)
imshow(vidFrame2)
hold on
plot(features)
title('All Features')
%% FindSpecificFeatures
specFeatures = selectStrongest(features,75);
subplot(1,2,2)
imshow(vidFrame2)
hold on
plot(specFeatures)
title('Strongest 75 Features')