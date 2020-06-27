// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/07 15:58)

#ifndef SYSTEM_HELPER_MACOS_H
#define SYSTEM_HELPER_MACOS_H

#if defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

	//  Mac OS ��������ѡ�

	#define TCRE_SYSTEM_PLATFORM "Mac OS"
	#define SYSTEM_PLATFORM_MACOS

	#if defined(__BIG_ENDIAN__)
		#define SYSTEM_BIG_ENDIAN
	#else // !defined(__BIG_ENDIAN__)
		#define SYSTEM_LITTLE_ENDIAN
	#endif // defined(__BIG_ENDIAN__)

#endif // defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

#endif // SYSTEM_HELPER_MACOS_H
