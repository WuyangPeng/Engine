// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/07 15:35)

#ifndef SYSTEM_HELPER_PGI_H
#define SYSTEM_HELPER_PGI_H

#if defined(__PGI)

	//  PGI C++ ���������ã�

	#ifndef SYSTEM_CPP_STANDARD
		#define SYSTEM_CPP_STANDARD 3
	#endif // SYSTEM_CPP_STANDARD

	#ifndef TCRE_USE_PGI
		#define TCRE_USE_PGI 1
	#endif // TCRE_USE_PGI

	#ifndef TCRE_COMPILER_VERSION
		#define TCRE_COMPILER_VERSION SYSTEM_CONCATENATOR(_PGIC__,__PGIC_MINOR__)
	#endif // TCRE_COMPILER_VERSION

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "PGI �������汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
	#endif // TCRE_SYSTEM_COMPILER 

#endif // defined(__PGI)

#endif // SYSTEM_HELPER_PGI_H
