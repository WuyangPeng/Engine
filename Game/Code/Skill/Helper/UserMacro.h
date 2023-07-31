///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:25)

#ifndef SKILL_HELPER_USER_HELPER_H
#define SKILL_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define SKILL_CLOSE_BEGIN (0x01)

#define CLOSE_USE_SKILL (SKILL_CLOSE_BEGIN)

#define SKILL_CLOSE_END CLOSE_USE_SKILL

#define CLOSE_SKILL_MAX (((SKILL_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_SKILL_CLOSE 0x00

static_assert(0 <= COMPILE_SKILL_CLOSE, "COMPILE_SKILL_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SKILL_CLOSE <= CLOSE_SKILL_MAX, "COMPILE_SKILL_CLOSE Must be less than or equal CLOSE_SKILL_MAX.");

#if !defined(COMPILE_SKILL_CLOSE) || (COMPILE_SKILL_CLOSE & CLOSE_USE_SKILL) != CLOSE_USE_SKILL

#endif  // !defined(COMPILE_SKILL_CLOSE) || (COMPILE_SKILL_CLOSE & CLOSE_USE_SKILL) != CLOSE_USE_SKILL

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_SKILL_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // SKILL_HELPER_USER_HELPER_H
