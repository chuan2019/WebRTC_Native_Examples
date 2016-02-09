/*
 *  Copyright 2012 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include <gtk/gtk.h>

#include "webrtc/examples/videocapture/videocapture_ex00.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) 
{
	gtk_init(&argc, &argv);

	MainWnd main_wnd;
	main_wnd.Create();

	return 0;
}
