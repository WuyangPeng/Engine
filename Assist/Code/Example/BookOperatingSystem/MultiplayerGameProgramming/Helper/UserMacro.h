///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.0 (2021/07/18 18:44)

#ifndef MULTIPLAYER_GAME_PROGRAMMING_HELPER_USER_MACRO_H
#define MULTIPLAYER_GAME_PROGRAMMING_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define MULTIPLAYER_GAME_PROGRAMMING_ClOSE_BEGIN (0x01)

#define CLOSE_USE_MULTIPLAYER_GAME_PROGRAMMING (MULTIPLAYER_GAME_PROGRAMMING_ClOSE_BEGIN)

#define MULTIPLAYER_GAME_PROGRAMMING_ClOSE_END CLOSE_USE_MULTIPLAYER_GAME_PROGRAMMING

#define CLOSE_MULTIPLAYER_GAME_PROGRAMMING_MAX ((MULTIPLAYER_GAME_PROGRAMMING_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE 0x00

static_assert(0 <= COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE, "COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE <= CLOSE_MULTIPLAYER_GAME_PROGRAMMING_MAX, "COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE Must be less than or equal CLOSE_MULTIPLAYER_GAME_PROGRAMMING_MAX.");

#if !defined(COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE) || (COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE & CLOSE_USE_MULTIPLAYER_GAME_PROGRAMMING) != CLOSE_USE_MULTIPLAYER_GAME_PROGRAMMING

#endif  // !defined(COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE) || (COMPILE_MULTIPLAYER_GAME_PROGRAMMING_CLOSE & CLOSE_USE_MULTIPLAYER_GAME_PROGRAMMING) != CLOSE_USE_MULTIPLAYER_GAME_PROGRAMMING

#ifdef BUILDING_STATIC
    #define BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC
#endif  // BUILDING_STATIC

#endif  // MULTIPLAYER_GAME_PROGRAMMING_HELPER_USER_MACRO_H