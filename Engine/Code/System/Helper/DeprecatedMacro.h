//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 15:05)

#ifndef SYSTEM_HELPER_DEPRECATE_MACRO_H
#define SYSTEM_HELPER_DEPRECATE_MACRO_H

// 跨平台的宏来标记一个函数或类为过时

#include "UserMacro.h"

#ifdef TCRE_USE_GCC
    #define SYSTEM_DEPRECATED __attribute__((deprecated))
#elif defined(TCRE_USE_MSVC)
    #define SYSTEM_DEPRECATED __declspec(deprecated)
#else  // !defined(TCRE_USE_MSVC) && !defined(TCRE_USE_GCC)
    #define SYSTEM_DEPRECATED
    #pragma message("编译器未定义SYSTEM_DEPRECATED")
#endif  // TCRE_USE_GCC

#endif  // SYSTEM_HELPER_DEPRECATE_MACRO_H
