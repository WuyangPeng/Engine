///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/09 17:47)

#ifndef SHADER_EDITOR_MACRO_USER_MACRO_H
#define SHADER_EDITOR_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_SHADER_EDITOR_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_SHADER_EDITOR_CLOSE 0x00

static_assert(0 <= COMPILE_SHADER_EDITOR_CLOSE, "COMPILE_SHADER_EDITOR_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SHADER_EDITOR_CLOSE <= CLOSE_SHADER_EDITOR_MAX, "COMPILE_SHADER_EDITOR_CLOSE Must be less than or equal CLOSE_SHADER_EDITOR_MAX.");

#if !defined(COMPILE_SHADER_EDITOR_CLOSE) || (COMPILE_SHADER_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_SHADER_EDITOR_CLOSE) || (COMPILE_SHADER_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_SHADER_EDITOR_STATIC
#endif  // BUILDING_STATIC

#endif  // SHADER_EDITOR_MACRO_USER_MACRO_H
