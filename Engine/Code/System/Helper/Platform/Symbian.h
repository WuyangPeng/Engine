// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 15:58)

#ifndef SYSTEM_HELPER_SYMBIAN_H
#define SYSTEM_HELPER_SYMBIAN_H

#if defined(__SYMBIAN32__) 

	//  symbian 具体配置选项：

	#define TCRE_SYSTEM_PLATFORM "Symbian"
	#define SYSTEM_PLATFORM_SYMBIAN

	#include <cstdlib> 
	#include <sys/endian.h>

	#if defined(__LITTLE_ENDIAN)
		#define SYSTEM_LITTLE_ENDIAN
	#else // !defined(__LITTLE_ENDIAN)
		#define SYSTEM_BIG_ENDIAN
	#endif // defined(__LITTLE_ENDIAN)

	#if !defined(__S60_3X__)
		#error "不支持 Symbian SDK"
	#endif // !defined(__S60_3X__)

#endif // defined(__SYMBIAN32__) 

#endif // SYSTEM_HELPER_SYMBIAN_H
