// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 17:58)

#ifndef SYSTEM_HELPER_MSL_H
#define SYSTEM_HELPER_MSL_H 

#if defined(__MSL_CPP__)

	//  Metrowerks 标准库

	#ifndef TCRE_CPPLIB_VERSION
		#define TCRE_CPPLIB_VERSION __MSL_CPP__
	#endif // TCRE_CPPLIB_VERSION

	#ifndef TCRE_STDLIB
		#define TCRE_SYSTEM_STDLIB "Metrowerks 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
	#endif // !TCRE_STDLIB 

	#define TCRE_USE_MSL

#endif // __MSL_CPP__

#endif // SYSTEM_HELPER_MSL_H
