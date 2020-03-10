// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:10)

#ifndef SYSTEM_HELPER_STL_PORT_H
#define SYSTEM_HELPER_STL_PORT_H 

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

	//  STLPort ��׼������

	#ifndef TCRE_CPPLIB_VERSION
		#define TCRE_CPPLIB_VERSION __SGI_STL_PORT
	#endif // TCRE_CPPLIB_VERSION

	#ifndef TCRE_STDLIB
		#define TCRE_SYSTEM_STDLIB "STLPort ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
	#endif // !TCRE_STDLIB 

	#if !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
		#include <cstddef>
		#if !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
			#error "�ⲻ��STLPort!"
		#endif // !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
	#endif // !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)

	#if !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))
		#include <unistd.h>
	#endif // !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

	#define TCRE_USE_STLPORT

#endif // defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

#endif // SYSTEM_HELPER_STL_PORT_H
