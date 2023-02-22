#include "AudioEffectCaptureExtend.h"

using namespace godot;

void AudioEffectCaptureExtend::_register_methods() {

	register_method("get_buffer_alt", &AudioEffectCaptureExtend::get_buffer_alt);
	
}

void AudioEffectCaptureExtend::_init() {
}

AudioEffectCaptureExtend::AudioEffectCaptureExtend() {
}

AudioEffectCaptureExtend::~AudioEffectCaptureExtend() {
}

PoolByteArray AudioEffectCaptureExtend::get_buffer_alt(int p_frames) {
	PoolVector2Array vdata = get_buffer(p_frames);
	PoolByteArray data;
	data.resize(p_frames);
	
	PoolByteArray::Write dataw = data.write();
	for (int i = 0 ; i < p_frames ; i++) {
		int8_t u = CLAMP((vdata[i].x+vdata[i].y)*64, -128, 127);
		dataw[i] = u;	
	}
	return data;
}