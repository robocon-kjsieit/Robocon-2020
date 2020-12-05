%% Set video reader and player
videoReader1 = vision.VideoFileReader('yellowBall_Door.mp4','VideoOutputDataType','double');
vidPlayer = vision.DeployableVideoPlayer;
%% Create tracker object
tracker = vision.HistogramBasedTracker;
%% Initialise tracker
img = step(videoReader1);
figure
imshow(img);
h = drawrectangle('Position',[1 78 50 50]);
wait(h);
boxLoc = h.Position;
imgYcbcr = rgb2ycbcr(img);
initializeObject(tracker,imgYcbcr(:,:,3),boxLoc);

 %% Track object
idx = 1;
oldcentroids =[];
S = info(videoReader1);
frameRate = S.VideoFrameRate;
scale = 1/320;
while ~isDone(videoReader1)
    
    img = step(videoReader1);
    imgYcbcr = rgb2ycbcr(img);
    [bbox,~,score(idx)] = step(tracker,imgYcbcr(:,:,3));
    bw = im2bw(img);
    
    %bw = bwareaopen(BW,50);
    point = regionprops(bw,'centroid');
    centroids = cat(1,point.Centroid);

    if score(idx)>0.5
         %Output trackig result
         out = insertShape(img,'Rectangle',bbox);

         if ~isempty(oldcentroids)
             vel_pix = sqrt(sum((centroids(end,:)-oldcentroids(end,:)).^2));
             vel = vel_pix * frameRate * scale;
         else
             vel_pix = 0;
             vel = 0;
         end
   % else
   %     %Find ball
   %     boxLoc = segmentBall(img,6000);
   %     if (~isempty(boxLoc))
   %         %If bal found,reinitialize and track again
   %         initializeSearchWindow(tracker,boxLoc);
   %         [bbox,~,score(idx)] = step(tracker,imgYcbcr(:,:,3));
   %         out = insertShape(img,'Rectangle',bbox);
   %     else
   %         %if ball not found, output unaltered frame
   %         out =img;
    %    end
    end
    
    
     %     % Visualize the velocity
     videoFrameOut = insertObjectAnnotation(img, 'circle', ...
          [centroids 10*ones(size(centroids,1),1)], ...
         cellstr(num2str(vel,'%2.2f')));
      step(vidPlayer, videoFrameOut);
      oldcentroids = centroids;
    
    
    
    
   % out = insertShape(img,'Rectangle',bbox);
  %  step(vidPlayer,out);
    %figure
    %imshow(bw)

    %hold on
   % plot(centroids(:,1),centroids(:,2),'b*')
   % hold off
    
    %pause(0.1);
    idx = idx+1;

end
figure;
plot(score);
xlabel('Frame #')
ylabel('Confidence Score(0,1)')
%% Clear
release(tracker)
release(vidPlayer)
release(videoReader1)
