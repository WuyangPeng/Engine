///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:50)

#ifndef SCRIPT_EDITOR_HELPER_USER_MACRO_H
#define SCRIPT_EDITOR_HELPER_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define SCRIPT_EDITOR_ClOSE_BEGIN (0x01)

#define CLOSE_USE_SCRIPT_EDITOR (SCRIPT_EDITOR_ClOSE_BEGIN)

#define SCRIPT_EDITOR_ClOSE_END CLOSE_USE_SCRIPT_EDITOR

#define CLOSE_SCRIPT_EDITOR_MAX (((SCRIPT_EDITOR_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_SCRIPT_EDITOR_CLOSE 0x00

static_assert(0 <= COMPILE_SCRIPT_EDITOR_CLOSE, "COMPILE_SCRIPT_EDITOR_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SCRIPT_EDITOR_CLOSE <= CLOSE_SCRIPT_EDITOR_MAX, "COMPILE_SCRIPT_EDITOR_CLOSE Must be less than or equal CLOSE_SCRIPT_EDITOR_MAX.");

#if !defined(COMPILE_SCRIPT_EDITOR_CLOSE) || (COMPILE_SCRIPT_EDITOR_CLOSE & CLOSE_USE_SCRIPT_EDITOR) != CLOSE_USE_SCRIPT_EDITOR

#endif  // !defined(COMPILE_SCRIPT_EDITOR_CLOSE) || (COMPILE_SCRIPT_EDITOR_CLOSE & CLOSE_USE_SCRIPT_EDITOR) != CLOSE_USE_SCRIPT_EDITOR

#ifdef BUILDING_STATIC

    #define BUILDING_SCRIPT_EDITOR_STATIC

#endif  // BUILDING_STATIC

#endif  // SCRIPT_EDITOR_HELPER_USER_MACRO_H
