#ifndef AudioEffectCaptureExtend_H
#define AudioEffectCaptureExtend_H

#include <Godot.hpp>
#include <AudioEffectCapture.hpp>

#ifndef CLAMP
#define CLAMP(m_a, m_min, m_max) (((m_a) < (m_min)) ? (m_min) : (((m_a) > (m_max)) ? m_max : m_a))
#endif

namespace godot {

class AudioEffectCaptureExtend : public AudioEffectCapture {
	GODOT_CLASS(AudioEffectCaptureExtend, AudioEffectCapture)
	
private:
	int test_val;
	inline unsigned int encode_uint16(uint16_t p_uint, uint8_t *p_arr);
	
public:
	static void _register_methods();
	
	void _init();
	AudioEffectCaptureExtend();
	~AudioEffectCaptureExtend();

	PoolByteArray get_buffer_uint8(int p_len);
	PoolByteArray get_buffer_uint16(int p_len);

};
	
}

#endif