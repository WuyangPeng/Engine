// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:02)

#ifndef SYSTEM_HELPER_PATH_SCALE_H
#define SYSTEM_HELPER_PATH_SCALE_H

#if defined(__PATHSCALE__) && (4 <= __PATHCC__)

	// PathScale EKOPath C++ 编译器设置：

	#ifndef SYSTEM_CPP_STANDARD
		#define SYSTEM_CPP_STANDARD 3
	#endif // SYSTEM_CPP_STANDARD

	#ifndef TCRE_USE_PATH_SCALE
		#define TCRE_USE_PATH_SCALE 1
	#endif // TCRE_USE_PATH_SCALE

	#ifndef TCRE_COMPILER_VERSION
		#define TCRE_COMPILER_VERSION __PATHSCALE__
	#endif // TCRE_COMPILER_VERSION

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "PathScale EKOPath C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER

#endif // defined(__PATHSCALE__) && (4 <= __PATHCC__)

#endif // SYSTEM_HELPER_PATH_SCALE_H
