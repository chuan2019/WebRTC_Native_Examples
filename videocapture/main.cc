#include <gtk/gtk.h>
#include "webrtc/examples/videocapture/videocapture_ex00.h"

int main(int argc, char* argv[]) 
{
	gtk_init(&argc, &argv);

	MainWnd main_wnd;
	main_wnd.Create();

	return 0;
}
