/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:52)

#ifndef ASSIST_TOOLS_MACRO_USER_MACRO_H
#define ASSIST_TOOLS_MACRO_USER_MACRO_H

#include "System/Helper/UserMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Database/Helper/UserMacro.h"
#include "Script/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"
#include "SoundEffect/Helper/UserMacro.h"
#include "InputOutput/Helper/UserMacro.h"
#include "ResourceManager/Helper/UserMacro.h"
#include "Rendering/Helper/UserMacro.h"
#include "Physics/Helper/UserMacro.h"
#include "Imagics/Helper/UserMacro.h"
#include "Animation/Helper/UserMacro.h"
#include "ArtificialIntelligence/Helper/UserMacro.h"
#include "UserInterface/Helper/UserMacro.h"

#define ASSIST_TOOLS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CUSTOM_REPLACE (ASSIST_TOOLS_ClOSE_BEGIN << 0)
#define CLOSE_USE_CUSTOM_ARRAY_REPLACE (ASSIST_TOOLS_ClOSE_BEGIN << 1)

#define ASSIST_TOOLS_ClOSE_END CLOSE_USE_CUSTOM_ARRAY_REPLACE

#define CLOSE_ASSIST_TOOLS_MAX (((ASSIST_TOOLS_ClOSE_END) << 1) - 1)

// 编译测试（默认为0B0000，最大值为0B0011）
#define COMPILE_ASSIST_TOOLS_CLOSE 0B0000

static_assert(0 <= COMPILE_ASSIST_TOOLS_CLOSE, "COMPILE_ASSIST_TOOLS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ASSIST_TOOLS_CLOSE <= CLOSE_ASSIST_TOOLS_MAX, "COMPILE_ASSIST_TOOLS_CLOSE Must be less than or equal CLOSE_ASSIST_TOOLS_MAX.");

#if !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_CUSTOM_REPLACE) != CLOSE_USE_CUSTOM_REPLACE

    // 是否使用自定义的字符串替换算法
    #define ASSIST_TOOLS_USE_CUSTOM_REPLACE (static_cast<void>(0))

#endif  // !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_CUSTOM_REPLACE) != CLOSE_USE_CUSTOM_REPLACE

#if !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_CUSTOM_ARRAY_REPLACE) != CLOSE_USE_CUSTOM_ARRAY_REPLACE

    // 是否使用自定义的字符串数组替换算法
    #define ASSIST_TOOLS_USE_CUSTOM_ARRAY_REPLACE (static_cast<void>(0))

#endif  // !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_CUSTOM_ARRAY_REPLACE) != CLOSE_USE_CUSTOM_ARRAY_REPLACE

#ifdef BUILDING_STATIC

    #define BUILDING_ASSIST_TOOLS_STATIC (static_cast<void>(0))

#endif  // BUILDING_STATIC

#endif  // ASSIST_TOOLS_MACRO_USER_MACRO_H
