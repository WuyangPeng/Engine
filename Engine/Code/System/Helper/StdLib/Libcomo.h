// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 17:52)

#ifndef SYSTEM_HELPER_LIBCOMO_H
#define SYSTEM_HELPER_LIBCOMO_H 

#if defined(__LIBCOMO__)

	//  Comeau STL:

	#ifndef TCRE_CPPLIB_VERSION
		#define TCRE_CPPLIB_VERSION __LIBCOMO_VERSION__
	#endif // TCRE_CPPLIB_VERSION

	#ifndef TCRE_STDLIB
		#define TCRE_SYSTEM_STDLIB "Comeau 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
	#endif // !TCRE_STDLIB 

	#define TCRE_USE_LIBCOMO

#endif // __LIBCOMO__

#endif // SYSTEM_HELPER_LIBCOMO_H
