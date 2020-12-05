%% LoadFrames
vidReader2 = vision.VideoFileReader('sample3.mp4');
vidFrame2 = step(vidReader2);
% ---Setup for vidFrame3
vidReader = vision.VideoFileReader('sample3.mp4');
vidReader.VideoOutputDataType = 'double';
vidPlayer = vision.DeployableVideoPlayer;
% ---Loop for vidFrame3
for tr = 1:55
     vidFrame3 = step(vidReader);
     step(vidPlayer,vidFrame3);
end
% ---Cleanup for vidFrame3
release(vidReader)
release(vidPlayer)
%
subplot(2,2,1)
imshow(vidFrame2)
title('Original Frame2')
subplot(2,2,2)
imshow(vidFrame3)
title('Original Frame3')

grayFrame2 = rgb2gray(vidFrame2);
subplot(2,2,3)
imshow(grayFrame2)
title('Grayscale Frame2')

grayFrame3 = rgb2gray(vidFrame3);
subplot(2,2,4)
imshow(grayFrame3)
title('Grayscale Frame3')
%% Detect Corner Using corner Algorithm
mserRegions2 = detectMinEigenFeatures(grayFrame2); % CAN USE ANY MATCHING IMAGE FEATURE
mserRegions3 = detectMinEigenFeatures(grayFrame3); % CAN USE ANY MATCHING IMAGE FEATURE
%% Visualise
figure
subplot(1,2,1)
imshow(vidFrame2)
title('Frame 2')
hold on
plot(mserRegions2)

subplot(1,2,2)
imshow(vidFrame3)
title('Frame 3')
hold on
plot(mserRegions3)
%% Extract features descriptors and their corresponding locations
[features2,points2] = extractFeatures(grayFrame2,mserRegions2);
[features3,points3] = extractFeatures(grayFrame3,mserRegions3);
%% Visualise
figure
subplot(1,2,1)
imshow(vidFrame2)
title('Frame 2')
hold on
plot(points2)

subplot(1,2,2)
imshow(vidFrame3)
title('Frame 3')
hold on
plot(points3)
%% Get the matched features
idxPairs = matchFeatures(features2,features3);
%% Get points that MATCH by indicing into all points
matchedPoints2 = points2(idxPairs(:,1));
matchedPoints3 = points3(idxPairs(:,2));
%% Show matched features
figure
showMatchedFeatures(vidFrame2,vidFrame3,matchedPoints2,matchedPoints3,'montage');