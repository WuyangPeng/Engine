// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:06)

#ifndef SYSTEM_HELPER_BSD_H
#define SYSTEM_HELPER_BSD_H

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)

	//  通用 BSD 具体配置选项：

	#ifdef __FreeBSD__
		#define TCRE_SYSTEM_PLATFORM "FreeBSD " SYSTEM_STRINGIZE(__FreeBSD__)
	#elif defined(__NetBSD__)
		#define TCRE_SYSTEM_PLATFORM "NetBSD " SYSTEM_STRINGIZE(__NetBSD__)
	#elif defined(__OpenBSD__)
		#define TCRE_SYSTEM_PLATFORM "OpenBSD " SYSTEM_STRINGIZE(__OpenBSD__)
	#elif defined(__DragonFly__)
		#define TCRE_SYSTEM_PLATFORM "DragonFly " SYSTEM_STRINGIZE(__DragonFly__)
	#endif // __FreeBSD__ 

	#define SYSTEM_PLATFORM_BSD

#endif // defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)

#endif // SYSTEM_HELPER_BSD_H


