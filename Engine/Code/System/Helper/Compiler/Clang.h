// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 13:41)

#ifndef SYSTEM_HELPER_CLANG_H
#define SYSTEM_HELPER_CLANG_H

// Clang编译器设置：

#if defined(__clang__) && !defined(__CUDACC__) && !defined(__ibmxl__)

	#if defined(__CUDACC__)	
		#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)
			#define SYSTEM_CPP_STANDARD 11
		#else // !defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus < 201103L)
			#define SYSTEM_CPP_STANDARD 3
		#endif // defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)
	#endif // __CUDACC__

	#ifndef TCRE_USE_CLANG
		#define TCRE_USE_CLANG 1
	#endif // TCRE_USE_CLANG

	#ifndef TCRE_COMPILER_VERSION
		#define TCRE_COMPILER_VERSION __clang_version__
	#endif // TCRE_COMPILER_VERSION

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "Clang 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER

	// 在定义__has_extension之前使用clang进行编译时，即使编写了“defined(__has_extension) && __has_extension(xxx)”，
	// clang也会报告编译器错误。 所以唯一的解决方法是：
	#ifndef __has_extension
		#define __has_extension __has_feature
	#endif // __has_extension

	#ifndef __has_attribute
		#define __has_attribute(x) 0
	#endif // __has_attribute

	#ifndef __has_cpp_attribute
		#define __has_cpp_attribute(x) 0
	#endif // __has_cpp_attribute

	// 自第一个版本以来，Clang一直支持“unused”属性。
	#define SYSTEM_ATTRIBUTE_UNUSED __attribute__((__unused__))

#endif // defined(__clang__) && !defined(__CUDACC__) && !defined(__ibmxl__)

#endif // SYSTEM_HELPER_CLANG_H
