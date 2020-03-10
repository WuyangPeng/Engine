// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:06)

#ifndef SYSTEM_HELPER_CYGWIN_H
#define SYSTEM_HELPER_CYGWIN_H

#if defined(__CYGWIN__)

	//  cygwin 具体配置选项：

	#define TCRE_SYSTEM_PLATFORM "Cygwin" 
	#define SYSTEM_PLATFORM_CYGWIN

	#include <unistd.h>
	#include <sys/types.h> 

#endif // defined(__CYGWIN__)
 
#endif // SYSTEM_HELPER_CYGWIN_H



