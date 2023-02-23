#include "AudioEffectCaptureExtend.h"

using namespace godot;

void AudioEffectCaptureExtend::_register_methods() {

	register_method("get_buffer_uint8", &AudioEffectCaptureExtend::get_buffer_uint8);
	register_method("get_buffer_uint16", &AudioEffectCaptureExtend::get_buffer_uint16);
	
}

void AudioEffectCaptureExtend::_init() {
}

AudioEffectCaptureExtend::AudioEffectCaptureExtend() {
}

AudioEffectCaptureExtend::~AudioEffectCaptureExtend() {
}

PoolByteArray AudioEffectCaptureExtend::get_buffer_uint8(int p_frames) {
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

PoolByteArray AudioEffectCaptureExtend::get_buffer_uint16(int p_frames) {
	PoolVector2Array vdata = get_buffer(p_frames);
	PoolByteArray data;
	data.resize(p_frames * 2);
	
	PoolByteArray::Write dataw = data.write();
	for (int i = 0 ; i < p_frames ; i++) {
		int16_t u = CLAMP((vdata[i].x + vdata[i].y)*16384, -32768, 32767);
		encode_uint16(u, &dataw[i * 2]);
	}
	return data;
}

inline unsigned int AudioEffectCaptureExtend::encode_uint16(uint16_t p_uint, uint8_t *p_arr) {
	for (int i = 0; i < 2; i++) {
		*p_arr = p_uint & 0xFF;
		p_arr++;
		p_uint >>= 8;
	}

	return sizeof(uint16_t);
}