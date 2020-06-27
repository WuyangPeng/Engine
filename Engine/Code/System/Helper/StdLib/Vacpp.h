// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 18:00)

#ifndef SYSTEM_HELPER_VACPP_H
#define SYSTEM_HELPER_VACPP_H 

#if defined(__IBMCPP__)

	#ifndef TCRE_CPPLIB_VERSION
		#define TCRE_CPPLIB_VERSION 1
	#endif // TCRE_CPPLIB_VERSION

	#ifndef TCRE_STDLIB
		#define TCRE_SYSTEM_STDLIB "Visual Age 默认 标准库版本 "  
	#endif // !TCRE_STDLIB 

	#if !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))
		#include <unistd.h>
	#endif // !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

	#define TCRE_USE_VACPP

#endif // __IBMCPP__

#endif // SYSTEM_HELPER_VACPP_H
