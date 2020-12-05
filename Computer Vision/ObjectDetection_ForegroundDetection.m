%% Create foreground detector object
detector = vision.ForegroundDetector('NumTrainingFrames',10,'InitialVariance',100*100);

%% Read in video File
reader = vision.VideoFileReader('stop_move_back_still3.mp4','VideoOutputDataType','uint8');
%% Create object for blob analysis
blob = vision.BlobAnalysis('MinimumBlobArea',2000);
%% Set up video player
player = vision.DeployableVideoPlayer;
%% Foreground detection
while ~isDone(reader)
    %load next frame
    frame = step(reader);
    %create foreground mask
    fgMask = step(detector,frame);
    %find bounding box
    image
    imshow(fgMask);
    [~,~,bbox] = step(blob,fgMask);
    %insert bounding box in frame
    J = insertShape(frame,'rectangle',bbox,'Linewidth',5);
    %update video player
    step(player,J);
end
%%
release(detector);
release(reader);
release(blob);
release(player);