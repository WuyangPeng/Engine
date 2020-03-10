// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:01)

#ifndef SYSTEM_HELPER_COMEAU_H
#define SYSTEM_HELPER_COMEAU_H

#ifdef __COMO__

	// Comeau C++ 编译器设置：

	// 版本检查：我们不知道版本4245之前的Comeau：
	#if __COMO_VERSION__ < 4245
		#error "编译器未配置"
	#endif // __COMO_VERSION__ < 4245

	// 最后已知的版本是4245：
	#if (4245 < __COMO_VERSION__)
		#error "未知的编译器版本"
	#endif // 4245 < __COMO_VERSION__

	#ifndef SYSTEM_CPP_STANDARD
		#define SYSTEM_CPP_STANDARD 3
	#endif // SYSTEM_CPP_STANDARD

	#ifndef TCRE_USE_COMEAU
		#define TCRE_USE_COMEAU 1
	#endif // TCRE_USE_COMEAU

	#ifndef TCRE_COMPILER_VERSION
		#define TCRE_COMPILER_VERSION __COMO_VERSION__
	#endif // TCRE_COMPILER_VERSION

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "Comeau C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER

#endif // __COMO__ 

#endif // SYSTEM_HELPER_COMEAU_H


