/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/17 20:09)

#ifndef PLAYER_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H
#define PLAYER_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define PLAYER_SERVER_MIDDLE_LAYER_ClOSE_BEGIN (0x01)

#define CLOSE_USE_PLAYER_SERVER_MIDDLE_LAYER (PLAYER_SERVER_MIDDLE_LAYER_ClOSE_BEGIN)

#define PLAYER_SERVER_MIDDLE_LAYER_ClOSE_END CLOSE_USE_PLAYER_SERVER_MIDDLE_LAYER

#define CLOSE_PLAYER_SERVER_MIDDLE_LAYER_MAX (((PLAYER_SERVER_MIDDLE_LAYER_ClOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0B0000�����ֵΪ0B0001��
#define COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE 0B0000

static_assert(0 <= COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE, "COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE <= CLOSE_PLAYER_SERVER_MIDDLE_LAYER_MAX, "COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE Must be less than or equal CLOSE_PLAYER_SERVER_MIDDLE_LAYER_MAX.");

#if !defined(COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE) || (COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE & CLOSE_USE_PLAYER_SERVER_MIDDLE_LAYER) != CLOSE_USE_PLAYER_SERVER_MIDDLE_LAYER

#endif  // !defined(COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE) || (COMPILE_PLAYER_SERVER_MIDDLE_LAYER_CLOSE & CLOSE_USE_PLAYER_SERVER_MIDDLE_LAYER) != CLOSE_USE_PLAYER_SERVER_MIDDLE_LAYER

#ifdef BUILDING_STATIC

    #define BUILDING_PLAYER_SERVER_MIDDLE_LAYER_STATIC

#endif  // BUILDING_STATIC

#endif  // PLAYER_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H