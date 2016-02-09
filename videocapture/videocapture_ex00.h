#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include <deque>
#include <map>
#include <set>
#include <string>

#include "talk/app/webrtc/mediastreaminterface.h"
#include "talk/app/webrtc/videosourceinterface.h"
#include "talk/app/webrtc/peerconnectioninterface.h"
#include "talk/app/webrtc/test/fakeconstraints.h"
#include "talk/media/base/mediachannel.h"
#include "talk/media/base/videocommon.h"
#include "talk/media/base/videoframe.h"
#include "talk/media/base/videorenderer.h"
#include "talk/media/devices/devicemanager.h"
#include "webrtc/base/scoped_ptr.h"
#include "webrtc/base/common.h"
#include "webrtc/base/logging.h"
#include "webrtc/base/basictypes.h"

class MainWnd
{
protected:
	class VideoRenderer: public webrtc::VideoRendererInterface
	{
	public:
		VideoRenderer(MainWnd *main_wnd, webrtc::VideoTrackInterface *track_to_render);
		virtual ~VideoRenderer();
	// Implementing VideoRendererInterface
		virtual void SetSize(int width, int height) override;
		virtual void RenderFrame(const cricket::VideoFrame* frame) override;
		const uint8_t* image() const {return image_.get();}
		int width() const {return width_;}
		int height() const {return height_;}
	protected:
		rtc::scoped_ptr<uint8_t[]> image_;
		int width_;
		int height_;
		MainWnd *main_wnd_;
		rtc::scoped_refptr<webrtc::VideoTrackInterface> m_video_track;
	};

protected:
	GtkWidget                                           *m_window;
	GtkWidget                                           *m_canvas;
	GtkWidget                                           *m_button;
	rtc::scoped_ptr<uint8_t[]>                          m_image_buffer;
	int													m_image_buffer_size;
	
	cricket::VideoCapturer*                             OpenVideoCaptureDevice();
	
	cricket::VideoCapturer 								*m_video_capturer;

	rtc::scoped_ptr<VideoRenderer>                      m_renderer;

	rtc::scoped_refptr<webrtc::VideoSourceInterface>	m_video_source;
	rtc::scoped_refptr<webrtc::VideoTrackInterface> 	m_video_track;
public:
	MainWnd();
	~MainWnd();
	
	bool Create();
	bool IsWindow();
	
	void OnDestroyed(GtkWidget *widget, GdkEvent *event);
	void OnClicked(GtkWidget *widget);
	
	void AddStreams();
	void OnUpdate();

	rtc::scoped_refptr<webrtc::PeerConnectionFactoryInterface> pc_factory;
};




