///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:29)

#ifndef RELATION_HELPER_USER_HELPER_H
#define RELATION_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define RELATION_CLOSE_BEGIN (0x01)

#define CLOSE_USE_RELATION (RELATION_CLOSE_BEGIN)

#define RELATION_CLOSE_END CLOSE_USE_RELATION

#define CLOSE_RELATION_MAX (((RELATION_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_RELATION_CLOSE 0x00

static_assert(0 <= COMPILE_RELATION_CLOSE, "COMPILE_RELATION_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_RELATION_CLOSE <= CLOSE_RELATION_MAX, "COMPILE_RELATION_CLOSE Must be less than or equal CLOSE_RELATION_MAX.");

#if !defined(COMPILE_RELATION_CLOSE) || (COMPILE_RELATION_CLOSE & CLOSE_USE_RELATION) != CLOSE_USE_RELATION

#endif  // !defined(COMPILE_RELATION_CLOSE) || (COMPILE_RELATION_CLOSE & CLOSE_USE_RELATION) != CLOSE_USE_RELATION

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_RELATION_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // RELATION_HELPER_USER_HELPER_H
