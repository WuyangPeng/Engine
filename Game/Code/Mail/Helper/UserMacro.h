// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 23:03)

#ifndef MAIL_MACRO_USER_MACRO_H
#define MAIL_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h" 

#define CLOSE_USE_XXX (0x01) 
#define CLOSE_MAIL_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_MAIL_CLOSE 0x00

static_assert(0 <= COMPILE_MAIL_CLOSE, "COMPILE_MAIL_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_MAIL_CLOSE <= CLOSE_MAIL_MAX, "COMPILE_MAIL_CLOSE Must be less than or equal CLOSE_MAIL_MAX.");

// 是否编译为静态库
#ifdef BUILDING_GAME_STATIC
	#define  BUILDING_MAIL_STATIC
#endif // BUILDING_GAME_STATIC

#if !defined(COMPILE_MAIL_CLOSE) || (COMPILE_MAIL_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif // !defined(COMPILE_MAIL_CLOSE) || (COMPILE_MAIL_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX 
 
#endif // MAIL_MACRO_USER_MACRO_H
