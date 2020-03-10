// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:02)

#ifndef SYSTEM_HELPER_PATH_SCALE_H
#define SYSTEM_HELPER_PATH_SCALE_H

#if defined(__PATHSCALE__) && (4 <= __PATHCC__)

	// PathScale EKOPath C++ ���������ã�

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
		#define TCRE_SYSTEM_COMPILER "PathScale EKOPath C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER

#endif // defined(__PATHSCALE__) && (4 <= __PATHCC__)

#endif // SYSTEM_HELPER_PATH_SCALE_H
