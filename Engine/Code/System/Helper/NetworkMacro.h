// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:12)

#ifndef SYSTEM_HELPER_NETWORK_MACRO_H
#define SYSTEM_HELPER_NETWORK_MACRO_H 

// 下面宏仅在System库内部调用，如果外部需要使用，WIN32需要链接Ws2_32.lib。

#ifdef BUILDING_SYSTEM_EXPORT

	#define SYSTEM_FD_CLRER(fd, set) FD_CLR(fd, set) 
	#define SYSTEM_FD_IS_SET(fd, set) FD_ISSET(fd, set) 
	#define SYSTEM_FD_SET(fd, set) FD_SET(fd, set) 
	#define SYSTEM_FD_ZERO(set) FD_ZERO(set) 

#endif // BUILDING_SYSTEM_EXPORT

#endif // SYSTEM_HELPER_NETWORK_MACRO_H
