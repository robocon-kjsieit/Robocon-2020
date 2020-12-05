vidDevice = imaq.VideoDevice('winvideo');
vidDevice.VideoFormat = 'YUY2_640x480';
vidDevice.ReturnedColorSpace = 'rgb';
                        
opticFlow = opticalFlowHS;

% Set up for stream
nFrames = 0;
while (nFrames<100)     % Process for the first 100 frames.
    % Acquire single frame from imaging device.
    frameRGB = vidDevice();

    % Compute the optical flow for that particular frame.
    flow = estimateFlow(opticFlow,rgb2gray(frameRGB));

    imshow(frameRGB)
    hold on
    plot(flow,'DecimationFactor',[5 5],'ScaleFactor',100)
    hold off

    % Increment frame count
    nFrames = nFrames + 1;
end

release(vidDevice);