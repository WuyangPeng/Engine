// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:06)

#ifndef SYSTEM_HELPER_CYGWIN_H
#define SYSTEM_HELPER_CYGWIN_H

#if defined(__CYGWIN__)

	//  cygwin ��������ѡ�

	#define TCRE_SYSTEM_PLATFORM "Cygwin" 
	#define SYSTEM_PLATFORM_CYGWIN

	#include <unistd.h>
	#include <sys/types.h> 

#endif // defined(__CYGWIN__)
 
#endif // SYSTEM_HELPER_CYGWIN_H



