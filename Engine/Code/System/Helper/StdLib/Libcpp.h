// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:09)

#ifndef SYSTEM_HELPER_LIBCPP_H
#define SYSTEM_HELPER_LIBCPP_H 
  
#if defined(_LIBCPP_VERSION)

	#ifndef TCRE_CPPLIB_VERSION
		#define TCRE_CPPLIB_VERSION _LIBCPP_VERSION
	#endif // TCRE_CPPLIB_VERSION

	#ifndef TCRE_STDLIB
		#define TCRE_SYSTEM_STDLIB "libc++ 版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
	#endif // !TCRE_STDLIB 

	#define TCRE_USE_LIBCPP

#endif // _LIBCPP_VERSION 

#endif // SYSTEM_HELPER_LIBCPP_H
