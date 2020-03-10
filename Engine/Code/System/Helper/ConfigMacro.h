// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:10)

#ifndef SYSTEM_HELPER_CONFIG_MACRO_H
#define SYSTEM_HELPER_CONFIG_MACRO_H

#define SYSTEM_STRINGIZE(x) SYSTEM_DO_STRINGIZE(x)
#define SYSTEM_DO_STRINGIZE(x) #x

#define SYSTEM_CONCATENATOR(lhs,rhs) SYSTEM_DO_CONCATENATOR(lhs,rhs)
#define SYSTEM_DO_CONCATENATOR(lhs,rhs) SYSTEM_DO_CONCATENATOR_DETAIL(lhs,rhs)
#define SYSTEM_DO_CONCATENATOR_DETAIL(lhs,rhs) lhs##rhs

#define SYSTEM_MULTIPLE_CONCATENATOR(lhs,mhs,rhs) SYSTEM_CONCATENATOR(lhs,SYSTEM_CONCATENATOR(mhs,rhs))

// 特定于平台的信息。
#include "SelectPlatformConfig.h"

// 特定于编译器的信息。
#include "SelectCompilerConfig.h"

// 特定于标准库的信息。
#include "SelectStdlibConfig.h"

#if !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)
	#define SYSTEM_LITTLE_ENDIAN
#endif // !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)

#ifndef SYSTEM_CPP_STANDARD
	#define SYSTEM_CPP_STANDARD 11
#endif // SYSTEM_CPP_STANDARD 

#if SYSTEM_CPP_STANDARD < 11
	#error "使用C++11标准，不再兼容C++98、C++03编译器。"
#endif // SYSTEM_CPP_STANDARD < 11

#ifndef SYSTEM_ATTRIBUTE_UNUSED
	#define SYSTEM_ATTRIBUTE_UNUSED  
#endif // SYSTEM_ATTRIBUTE_UNUSED 

#ifndef TCRE_SYSTEM_PLATFORM
	#error "没有定义平台。"
#endif // TCRE_SYSTEM_PLATFORM

#ifndef TCRE_COMPILER_VERSION
	#error "没有定义编译器版本。"
#endif // TCRE_COMPILER_VERSION

#ifndef TCRE_SYSTEM_COMPILER
	#error "没有定义编译器。"
#endif // TCRE_SYSTEM_COMPILER

#ifndef TCRE_CPPLIB_VERSION
	#error "没有定义标准库版本。"
#endif // TCRE_CPPLIB_VERSION

#ifndef TCRE_SYSTEM_STDLIB
	#error "没有定义标准库。"
#endif // TCRE_SYSTEM_STDLIB

#include "UserMacro.h"
	  
#endif // SYSTEM_HELPER_CONFIG_MACRO_H
