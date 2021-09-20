// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.2.1 (2020/01/12 1:23)

#ifndef EDITOR_MACRO_USER_MACRO_H
#define EDITOR_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_EDITOR_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_EDITOR_CLOSE 0x00

static_assert(0 <= COMPILE_EDITOR_CLOSE, "COMPILE_EDITOR_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_EDITOR_CLOSE <= CLOSE_EDITOR_MAX, "COMPILE_EDITOR_CLOSE Must be less than or equal CLOSE_EDITOR_MAX.");

// 是否编译为静态库
#ifdef BUILDING_STATIC
	#define  BUILDING_EDITOR_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_EDITOR_CLOSE) || (COMPILE_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_EDITOR_CLOSE) || (COMPILE_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 

#endif // EDITOR_MACRO_USER_MACRO_H
