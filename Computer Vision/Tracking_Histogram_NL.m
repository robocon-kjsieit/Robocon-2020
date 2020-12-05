%% Set video reader and player
videoReader = vision.VideoFileReader('yellowBall.mp4','VideoOutputDataType','double');
vidPlayer = vision.DeployableVideoPlayer;
%% Create tracker object
tracker = vision.HistogramBasedTracker;
%% Initialise tracker
img = step(videoReader);
figure
imshow(img);
h = drawrectangle('Position',[100 100 50 50]);
wait(h);
boxLoc = h.Position;
imgYcbcr = rgb2ycbcr(img);
initializeObject(tracker,imgYcbcr(:,:,3),boxLoc);

 %% Track object
idx = 1;
while ~isDone(videoReader)
    
    img = step(videoReader);
    imgYcbcr = rgb2ycbcr(img);
    [bbox,~,score(idx)] = step(tracker,imgYcbcr(:,:,3));
    
    out = insertShape(img,'Rectangle',bbox);
    step(vidPlayer,out);
    %pause(0.1);
    idx = idx+1;
end
figure;
plot(score);
xlabel('Frame #')
ylabel('Confidence Score(0,1)')
