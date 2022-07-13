///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/11 13:49)

#ifndef TEXTURE_EDITOR_MACRO_USER_MACRO_H
#define TEXTURE_EDITOR_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_TEXTURE_EDITOR_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_TEXTURE_EDITOR_CLOSE 0x00

static_assert(0 <= COMPILE_TEXTURE_EDITOR_CLOSE, "COMPILE_TEXTURE_EDITOR_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_TEXTURE_EDITOR_CLOSE <= CLOSE_TEXTURE_EDITOR_MAX, "COMPILE_TEXTURE_EDITOR_CLOSE Must be less than or equal CLOSE_TEXTURE_EDITOR_MAX.");

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_TEXTURE_EDITOR_STATIC
#endif  // BUILDING_STATIC

#if !defined(COMPILE_TEXTURE_EDITOR_CLOSE) || (COMPILE_TEXTURE_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_TEXTURE_EDITOR_CLOSE) || (COMPILE_TEXTURE_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // TEXTURE_EDITOR_MACRO_USER_MACRO_H
