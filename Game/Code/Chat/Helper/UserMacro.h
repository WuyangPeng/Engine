///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 17:00)

#ifndef CHAT_HELPER_USER_HELPER_H
#define CHAT_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CHAT_CLOSE_BEGIN (0x01)

#define CLOSE_USE_CHAT (CHAT_CLOSE_BEGIN)

#define CHAT_CLOSE_END CLOSE_USE_CHAT

#define CLOSE_CHAT_MAX (((CHAT_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_CHAT_CLOSE 0x00

static_assert(0 <= COMPILE_CHAT_CLOSE, "COMPILE_CHAT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CHAT_CLOSE <= CLOSE_CHAT_MAX, "COMPILE_CHAT_CLOSE Must be less than or equal CLOSE_CHAT_MAX.");

#if !defined(COMPILE_CHAT_CLOSE) || (COMPILE_CHAT_CLOSE & CLOSE_USE_CHAT) != CLOSE_USE_CHAT

#endif  // !defined(COMPILE_CHAT_CLOSE) || (COMPILE_CHAT_CLOSE & CLOSE_USE_CHAT) != CLOSE_USE_CHAT

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_CHAT_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // CHAT_HELPER_USER_HELPER_H
