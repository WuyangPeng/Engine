///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:14)

#ifndef SCENE_HELPER_USER_HELPER_H
#define SCENE_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define SCENE_CLOSE_BEGIN (0x01)

#define CLOSE_USE_SCENE (SCENE_CLOSE_BEGIN)

#define SCENE_CLOSE_END CLOSE_USE_SCENE

#define CLOSE_SCENE_MAX (((SCENE_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_SCENE_CLOSE 0x00

static_assert(0 <= COMPILE_SCENE_CLOSE, "COMPILE_SCENE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SCENE_CLOSE <= CLOSE_SCENE_MAX, "COMPILE_SCENE_CLOSE Must be less than or equal CLOSE_SCENE_MAX.");

#if !defined(COMPILE_SCENE_CLOSE) || (COMPILE_SCENE_CLOSE & CLOSE_USE_SCENE) != CLOSE_USE_SCENE

#endif  // !defined(COMPILE_SCENE_CLOSE) || (COMPILE_SCENE_CLOSE & CLOSE_USE_SCENE) != CLOSE_USE_SCENE

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_SCENE_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // SCENE_HELPER_USER_HELPER_H
