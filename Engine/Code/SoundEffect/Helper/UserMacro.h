///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 19:16)

#ifndef SOUND_EFFECT_MACRO_USER_MACRO_H
#define SOUND_EFFECT_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_OPENAL (0x01)
#define CLOSE_SOUND_EFFECT_MAX (((CLOSE_USE_OPENAL) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_SOUND_EFFECT_CLOSE 0x00

static_assert(0 <= COMPILE_SOUND_EFFECT_CLOSE, "COMPILE_SOUND_EFFECT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SOUND_EFFECT_CLOSE <= CLOSE_SOUND_EFFECT_MAX, "COMPILE_SOUND_EFFECT_CLOSE Must be less than or equal CLOSE_SOUND_EFFECT_MAX.");

#if !defined(COMPILE_SOUND_EFFECT_CLOSE) || (COMPILE_SOUND_EFFECT_CLOSE & CLOSE_USE_OPENAL) != CLOSE_USE_OPENAL
    #define SOUND_EFFECT_USE_OPENAL
#endif  // !defined(COMPILE_SOUND_EFFECT_CLOSE) || (COMPILE_SOUND_EFFECT_CLOSE & CLOSE_USE_OPENAL) != CLOSE_USE_OPENAL

#ifdef BUILDING_STATIC

    #define BUILDING_SOUND_EFFECT_STATIC

#endif  // BUILDING_STATIC

#endif  // SOUND_EFFECT_MACRO_USER_MACRO_H
