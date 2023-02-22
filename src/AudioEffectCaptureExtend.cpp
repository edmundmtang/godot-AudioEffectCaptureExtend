#include "AudioEffectCaptureExtend.h"

using namespace godot;

void AudioEffectCaptureExtend::_register_methods() {

	register_method("print_me", &AudioEffectCaptureExtend::print_me);
	
}

void AudioEffectCaptureExtend::_init() {
}

AudioEffectCaptureExtend::AudioEffectCaptureExtend() {
}

AudioEffectCaptureExtend::~AudioEffectCaptureExtend() {
}

int AudioEffectCaptureExtend::print_me() {
	test_val = 17;
	return test_val;
}