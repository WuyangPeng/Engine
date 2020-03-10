// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:10)

#ifndef SYSTEM_HELPER_SGI_H
#define SYSTEM_HELPER_SGI_H 

#if defined(__STL_CONFIG_H)

	//  ͨ�� SGI STL:
 
	#ifndef TCRE_CPPLIB_VERSION
		#define TCRE_CPPLIB_VERSION 1
	#endif // TCRE_CPPLIB_VERSION

	#ifndef TCRE_STDLIB
		#define TCRE_SYSTEM_STDLIB "SGI ��׼��汾 "
	#endif // !TCRE_STDLIB 

	#if !defined(CYGWIN) && \
		(defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))
		#include <unistd.h>
	#endif // !defined(CYGWIN) && (  defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

	#define TCRE_USE_SGI

#endif // __STL_CONFIG_H

#endif // SYSTEM_HELPER_SGI_H
