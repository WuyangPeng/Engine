///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/30 21:54)

#ifndef THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_USER_MACRO_H
#define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ClOSE_BEGIN (0x01)

#define CLOSE_USE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD (THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ClOSE_BEGIN)

#define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ClOSE_END CLOSE_USE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD

#define CLOSE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_MAX ((THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE 0x00

static_assert(0 <= COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE, "COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE <= CLOSE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_MAX, "COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE Must be less than or equal CLOSE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_MAX.");

#if !defined(COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE) || (COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE & CLOSE_USE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD) != CLOSE_USE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD

#endif  // !defined(COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE) || (COMPILE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLOSE & CLOSE_USE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD) != CLOSE_USE_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC
#endif  // BUILDING_STATIC

#endif  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_USER_MACRO_H
