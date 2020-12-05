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
features = detectBRISKFeatures(grayFrame1);
figure
subplot(1,2,1)
imshow(vidFrame2)
hold on
plot(features)
title('NumOctave:4')
%% FindSpecificFeatures
specFeatures = detectBRISKFeatures(grayFrame1,'NumOctave',1);
subplot(1,2,2)
imshow(vidFrame2)
hold on
plot(specFeatures)
title('NumOctave:1')