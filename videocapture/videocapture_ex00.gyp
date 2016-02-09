{
	'includes': 
	[
		'../talk/build/common.gypi',
	],
	'targets': 
	[
		{
			'target_name': 'video_capturer',
			'type': 'executable',
			'variables': {
				'QT_WEBRTC_PATH': 'examples/videocapture',
			},
			'sources':
			[
				'<(QT_WEBRTC_PATH)/videocapture_ex00.h',
				'<(QT_WEBRTC_PATH)/videocapture_ex00.cc',
				'<(QT_WEBRTC_PATH)/main.cc',
			],
			'dependencies':
			[
				'../talk/libjingle.gyp:libjingle_peerconnection',
				'<(webrtc_root)/system_wrappers/system_wrappers.gyp:field_trial_default',
				'<@(libjingle_tests_additional_deps)',
			],
			'cflags':
			[
				'<!@(pkg-config --cflags glib-2.0 gobject-2.0 gtk+-2.0)',
			],
			'link_settings':
			{
				'ldflags':
				[
					'<!@(pkg-config --libs-only-L --libs-only-other glib-2.0'
					' gobject-2.0 gthread-2.0 gtk+-2.0)',
				],
				'libraries':
				[
					'<!@(pkg-config --libs-only-l glib-2.0 gobject-2.0'
					' gthread-2.0 gtk+-2.0)',
					'-lX11',
					'-lXcomposite',
					'-lXext',
					'-lXrender',
				],
			},
		},  # target video_capturer
	],
}
