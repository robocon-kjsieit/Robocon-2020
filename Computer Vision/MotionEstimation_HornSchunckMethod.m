%% Set up video reader
videoReader = vision.VideoFileReader('rightleft.mp4','ImageColorSpace','Intensity');
%% Set up optical flow
of = opticalFlowHS;
of.Smoothness = 0.1;
%% Set up optical flow
while ~isDone(videoReader)
    videoFrame = step(videoReader);
    flowField = estimateFlow(of,videoFrame);
    subplot(2,2,1)
    plot(flowField,'DecimationFactor',[10 10],'ScaleFactor',50);
    title('Optical Flow');
    drawnow;
    horizontalMotion = flowField.Vx;
    objectsToRight = horizontalMotion > 1;
    objectToLeft = horizontalMotion < -1;
    subplot(2,2,3)
    imshow(objectsToRight);
    title('Object moving to right');
    subplot(2,2,4)
    imshow(objectToLeft);
    title('Object moving to left');
    robotLeftMotion = nnz(objectsToRight);
    robotRightMotion = nnz(objectToLeft);
    if robotLeftMotion > robotRightMotion
        movString = 'Moving to LEFT';
    else
        movString = 'Moving to Right';
    end
    frameMov = insertText(videoFrame,[1 1],movString,'FontSize',36);
    subplot(2,2,2)
    imshow(frameMov)
    title('Robot Motion');
    
  
    
end
%% clear
release(videoReader)
release(ob)