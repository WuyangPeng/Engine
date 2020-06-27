// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 17:58)

#ifndef SYSTEM_HELPER_ROGUEWAVE_H
#define SYSTEM_HELPER_ROGUEWAVE_H 

#if defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)

	//  Rogue Wave 标准库

	#define TCRE_RW_STDLIB 1  

	#ifndef _RWSTD_VER
		#define TCRE_RWSTD_VERSION 0x010000
	#elif _RWSTD_VER < 0x010000
		#define TCRE_RWSTD_VERSION (_RWSTD_VER << 8)
	#else // 0x010000 <= _RWSTD_VER
		#define TCRE_RWSTD_VERSION _RWSTD_VER
	#endif // _RWSTD_VER

	#ifndef TCRE_CPPLIB_VERSION
		#define TCRE_CPPLIB_VERSION TCRE_RWSTD_VERSION
	#endif // TCRE_CPPLIB_VERSION

	#ifndef _RWSTD_VER
		#define TCRE_SYSTEM_STDLIB "Rogue Wave 标准库版本 (未知版本)"
	#elif _RWSTD_VER < 0x04010200
		#define TCRE_SYSTEM_STDLIB "Rogue Wave 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
	#else // 0x04010200 <= _RWSTD_VER
		#ifdef _RWSTD_VER_STR
			#define TCRE_SYSTEM_STDLIB "Apache STDCXX 标准库版本 " _RWSTD_VER_STR
		#else // !_RWSTD_VER_STR
			#define TCRE_SYSTEM_STDLIB "Apache STDCXX 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
		#endif // _RWSTD_VER_STR
	#endif // _RWSTD_VER

	#define TCRE_USE_ROGUEWAVE

#endif // defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)

#endif // SYSTEM_HELPER_ROGUEWAVE_H
