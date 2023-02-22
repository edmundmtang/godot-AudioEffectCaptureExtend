#ifndef AudioEffectCaptureExtend_H
#define AudioEffectCaptureExtend_H

#include <Godot.hpp>
#include <AudioEffectCapture.hpp>

namespace godot {

class AudioEffectCaptureExtend : public AudioEffectCapture {
	GODOT_CLASS(AudioEffectCaptureExtend, AudioEffectCapture)
	
private:
	int test_val;
	
public:
	static void _register_methods();
	
	void _init();
	AudioEffectCaptureExtend();
	~AudioEffectCaptureExtend();

	int print_me();

};
	
}

#endif