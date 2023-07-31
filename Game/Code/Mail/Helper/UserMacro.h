///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:06)

#ifndef MAIL_HELPER_USER_HELPER_H
#define MAIL_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define MAIL_CLOSE_BEGIN (0x01)

#define CLOSE_USE_MAIL (MAIL_CLOSE_BEGIN)

#define MAIL_CLOSE_END CLOSE_USE_MAIL

#define CLOSE_MAIL_MAX (((MAIL_CLOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_MAIL_CLOSE 0x00

static_assert(0 <= COMPILE_MAIL_CLOSE, "COMPILE_MAIL_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_MAIL_CLOSE <= CLOSE_MAIL_MAX, "COMPILE_MAIL_CLOSE Must be less than or equal CLOSE_MAIL_MAX.");

#if !defined(COMPILE_MAIL_CLOSE) || (COMPILE_MAIL_CLOSE & CLOSE_USE_MAIL) != CLOSE_USE_MAIL

#endif  // !defined(COMPILE_MAIL_CLOSE) || (COMPILE_MAIL_CLOSE & CLOSE_USE_MAIL) != CLOSE_USE_MAIL

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_MAIL_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // MAIL_HELPER_USER_HELPER_H
