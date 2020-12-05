%% Set video reader and player
videoReader = vision.VideoFileReader('yellowBall.mp4','VideoOutputDataType','double');
vidPlayer = vision.DeployableVideoPlayer;
%% Create tracker object
tracker = vision.HistogramBasedTracker;
%% Initialise tracker
img = step(videoReader);
figure
imshow(img);
h = drawrectangle('Position',[1 78 50 50]);
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
    
    if score(idx)>0.5
        %Output trackig result
        out = insertShape(img,'Rectangle',bbox);
    else
        %Find ball
        boxLoc = segmentBall(img,5000);
        if (~isempty(boxLoc))
            %If bal found,reinitialize and track again
            initializeSearchWindow(tracker,boxLoc);
            [bbox,~,score(idx)] = step(tracker,imgYcbcr(:,:,3));
            out = insertShape(img,'Rectangle',bbox);
        else
            %if ball not found, output unaltered frame
            out =img;
        end
    end
    
    
    %out = insertShape(img,'Rectangle',bbox);
    step(vidPlayer,out);
    %pause(0.1);
    idx = idx+1;
end
figure;
plot(score);
xlabel('Frame #')
ylabel('Confidence Score(0,1)')
