#!/bin/bash/
cp ./videocapture_ex00.gyp ../../
cd ../../

python ./build/gyp_webrtc.py

cd ..
ninja -C out/Debug/


