///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/25 13:52)

#ifndef SOUND_EFFECT_MACRO_USER_MACRO_H
#define SOUND_EFFECT_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_OPENAL (0x01)
#define CLOSE_SOUND_EFFECT_MAX (((CLOSE_USE_OPENAL) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_SOUND_EFFECT_CLOSE 0x00

static_assert(0 <= COMPILE_SOUND_EFFECT_CLOSE, "COMPILE_SOUND_EFFECT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SOUND_EFFECT_CLOSE <= CLOSE_SOUND_EFFECT_MAX, "COMPILE_SOUND_EFFECT_CLOSE Must be less than or equal CLOSE_SOUND_EFFECT_MAX.");

#if !defined(COMPILE_SOUND_EFFECT_CLOSE) || (COMPILE_SOUND_EFFECT_CLOSE & CLOSE_USE_OPENAL) != CLOSE_USE_OPENAL
    #define SOUND_EFFECT_USE_OPENAL
#endif  // !defined(COMPILE_SOUND_EFFECT_CLOSE) || (COMPILE_SOUND_EFFECT_CLOSE & CLOSE_USE_OPENAL) != CLOSE_USE_OPENAL

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_SOUND_EFFECT_STATIC
#endif  // BUILDING_STATIC

#endif  // SOUND_EFFECT_MACRO_USER_MACRO_H
