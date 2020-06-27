// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/17 10:56)

#ifndef SCRIPT_MACRO_USER_MACRO_H
#define SCRIPT_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_LUA (0x01) 
#define CLOSE_SCRIPT_MAX (((CLOSE_USE_LUA) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_SCRIPT_CLOSE 0x00

static_assert(0 <= COMPILE_SCRIPT_CLOSE, "COMPILE_SCRIPT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SCRIPT_CLOSE <= CLOSE_SCRIPT_MAX, "COMPILE_SCRIPT_CLOSE Must be less than or equal CLOSE_SCRIPT_MAX.");

// 是否编译为静态库
#ifdef BUILDING_STATIC
	#define  BUILDING_SCRIPT_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_LUA) != CLOSE_USE_LUA
	#define SCRIPT_USE_LUA
#endif // !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_LUA) != CLOSE_USE_LUA  
 
#endif // SCRIPT_MACRO_USER_MACRO_H
