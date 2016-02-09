# WebRTC_Native_Examples
Examples for WebRTC native (C/C++) Development under GTK+ framework

## 1. Video Capture:
      install instruction: 
            <b>step 1:</b> copy the whole directory into <code>/webrtc-checkout/src/webrtc/examples</code>; 
            
            <b>step 2:</b> find the script <code>all.gyp</code> under the directory: <code>webrtc-checkout/src/</code>, and add the following line into the <code>'dependencies'</code> list under the "path": <code>'targets':[{'conditions':['include_examples==1',{</code> 
                  
                  <code>'webrtc/video_capture_ex00.gyp:*',</code>
                  
            <b>step 3:</b> run the script <code>build.sh</code> in the <code>/webrtc-checkout/src/webrtc/examples/videocapture</code> you copied in <b>step 1</b>
      
            <b>step 4:</b> as long as building is done, goto <code>/webrtc-checkout/src/out/Debug</code> or 
      <code>/webrtc-checkout/src/out/Release</code> you can find <code>video_capturer</code> and run it.
      
