// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:01)

#ifndef SYSTEM_HELPER_COMPAQ_CXX_H
#define SYSTEM_HELPER_COMPAQ_CXX_H

#ifdef __DECCXX

	// Tru64 C++ ���������ã���Ϊ HP����

	#ifndef SYSTEM_CPP_STANDARD
		#define SYSTEM_CPP_STANDARD 3
	#endif // SYSTEM_CPP_STANDARD

	#ifndef TCRE_USE_COMPAQ_CXX
		#define TCRE_USE_COMPAQ_CXX 1
	#endif // TCRE_USE_COMPAQ_CXX

	#ifndef TCRE_COMPILER_VERSION
		#define TCRE_COMPILER_VERSION __DECCXX_VER
	#endif // TCRE_COMPILER_VERSION

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "HP Tru64 C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER

#endif // __DECCXX 

#endif // SYSTEM_HELPER_COMPAQ_CXX_H






