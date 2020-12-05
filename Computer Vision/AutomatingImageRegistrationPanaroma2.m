% First Run MatchingImageFeaturesOf2Frames.mat
%% Estimating the geometric transform between 'fixed' and 'moving'
rand(1)
[tform,inlierPoints3,inlierPoints2] = estimateGeometricTransform(matchedPoints3,matchedPoints2,'projective');
rng('default')
%% Visualise the features that are used for the estimarion
figure
showMatchedFeatures(vidFrame2,vidFrame3,inlierPoints2,inlierPoints3,'montage');
%% Trnsform moving image with fixed image reference
rFixed = imref2d(size(vidFrame2));
moving2 = imwarp(vidFrame3,tform,'OutputView',rFixed);
%% Visualize images
figure
subplot(2,2,1)
imshow(vidFrame2)
title('Fixed Image')
subplot(2,2,2)
imshow(vidFrame3)
title('Moving Image')
subplot(2,2,3)
imshow(moving1)
title('Transformed Moving Image')
subplot(2,2,4)
imshowpair(vidFrame2,moving1,'blend')
title('Transformed And Fixed Images Overlaid')