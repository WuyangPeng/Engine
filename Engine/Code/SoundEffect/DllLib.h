// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 14:30)

#ifndef SOUND_EFFECT_DLL_LIB_H
#define SOUND_EFFECT_DLL_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifdef SOUND_EFFECT_USE_OPENAL
		#pragma comment(lib,"OpenAL32.lib")
	#endif // SOUND_EFFECT_USE_OPENAL
	
#endif // TCRE_USE_MSVC

#endif // SOUND_EFFECT_DLL_LIB_H