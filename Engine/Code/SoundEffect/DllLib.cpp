// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 14:31)

// ��Ч�⣨SoundEffect����װ���������Ч���ܡ�
// ��Ч��λ������ĵ����㣬ֻ������������е�CoreTools�⡢System�⣬
// ��ʹ��boost��stlsoft���߿⡣

// ��Ч���������ģ�飺
// 1.	Macro���꣩
// 2.	Configuration �����ã�
// 3.	Interface���ӿڣ�
// 4.	CsynUtil��CsynUtil��
// 5.	DirectSound��DirectSound��
// 6.	ogg��ogg��
// 7.	OpenAL��OpenAL��
// 8.	vorbis��vorbis��
// 9.	FreeAlut��FreeAlut��

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffect/SoundEffect.h"

#include "CoreTools/CoreToolsLib.h"
#include "System/SystemLib.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

	#include "DllLib.h"

#else // BUILDING_SOUND_EFFECT_STATIC

	namespace SoundEffect
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SOUND_EFFECT_STATIC

