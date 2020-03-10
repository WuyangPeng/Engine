// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:10)

#ifndef SYSTEM_HELPER_DEPRECATE_MACRO_H
#define SYSTEM_HELPER_DEPRECATE_MACRO_H

// 跨平台的宏来标记一个函数或类为过时

#include "UserMacro.h"

#ifdef TCRE_USE_GCC
	#define SYSTEM_DEPRECATED __attribute__ ((deprecated))
#elif defined(TCRE_USE_MSVC)
	#define SYSTEM_DEPRECATED __declspec(deprecated)
#else // !defined(TCRE_USE_MSVC) && !defined(TCRE_USE_GCC)
	#define SYSTEM_DEPRECATED
	#pragma message("编译器未定义SYSTEM_DEPRECATED")
#endif // TCRE_USE_GCC

#endif // SYSTEM_HELPER_DEPRECATE_MACRO_H
