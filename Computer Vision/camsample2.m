myCam = imaq.VideoDevice('winvideo');
myCam.VideoFormat = 'YUY2_640x480';
myCam.ReturnedColorSpace =  'rgb';
vidPlayer = vision.DeployableVideoPlayer;
for idx = 1: 100
    videoFrame = step(myCam);
    step(vidPlayer,videoFrame);
end
release(myCam);
release(vidPlayer);