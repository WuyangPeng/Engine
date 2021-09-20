// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.1.0.3 (2020/04/28 0:00)

#ifndef BOOK_CODE_MACRO_USER_MACRO_H
#define BOOK_CODE_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CLOSE_USE_BOOK_CODE (0x01) 
#define CLOSE_BOOK_CODE_MAX ((CLOSE_USE_BOOK_CODE << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_BOOK_CODE_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_CODE_CLOSE, "COMPILE_BOOK_CODE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_CODE_CLOSE <= CLOSE_BOOK_CODE_MAX, "COMPILE_BOOK_CODE_CLOSE Must be less than or equal CLOSE_BOOK_CODE_MAX.");

// 是否编译为静态库
#ifdef BUILDING_STATIC
	#define  BUILDING_BOOK_CODE_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_BOOK_CODE_CLOSE) || (COMPILE_BOOK_CODE_CLOSE & CLOSE_USE_BOOK_CODE) != CLOSE_USE_BOOK_CODE

#endif // !defined(COMPILE_BOOK_CODE_CLOSE) || (COMPILE_BOOK_CODE_CLOSE & CLOSE_USE_BOOK_CODE) != CLOSE_USE_BOOK_CODE 
 
#endif // BOOK_CODE_MACRO_USER_MACRO_H
