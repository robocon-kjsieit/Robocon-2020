%% Set up video and player
videoReader = vision.VideoFileReader('yellowBall.mp4','VideoOutputDataType','double');
vidPlayer = vision.DeployableVideoPlayer;
%% Initialize tracking
img = step(videoReader);
figure;
imshow(img)
h = drawrectangle;
wait(h);
[~,centLoc] = getLocation(h)