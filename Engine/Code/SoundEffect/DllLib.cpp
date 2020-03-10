// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/16 14:31)

// 音效库（SoundEffect）封装了引擎的音效功能。
// 音效库位于引擎的第三层，只允许调用引擎中的CoreTools库、System库，
// 并使用boost、stlsoft工具库。

// 音效库包含以下模块：
// 1.	Macro（宏）
// 2.	Configuration （配置）
// 3.	Interface（接口）
// 4.	CsynUtil（CsynUtil）
// 5.	DirectSound（DirectSound）
// 6.	ogg（ogg）
// 7.	OpenAL（OpenAL）
// 8.	vorbis（vorbis）
// 9.	FreeAlut（FreeAlut）

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

