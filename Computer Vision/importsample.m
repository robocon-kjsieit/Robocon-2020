%% Setup
vidReader = vision.VideoFileReader('sample.mp4');
vidReader.VideoOutputDataType = 'double';
vidPlayer = vision.DeployableVideoPlayer;
%% Loop
while ~isDone(vidReader)
     vidFrame = step(vidReader);
     step(vidPlayer,vidFrame);
end
%% Cleanup
release(vidReader)
release(vidPlayer)