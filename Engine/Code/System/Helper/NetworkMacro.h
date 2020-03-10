// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:12)

#ifndef SYSTEM_HELPER_NETWORK_MACRO_H
#define SYSTEM_HELPER_NETWORK_MACRO_H 

// ��������System���ڲ����ã�����ⲿ��Ҫʹ�ã�WIN32��Ҫ����Ws2_32.lib��

#ifdef BUILDING_SYSTEM_EXPORT

	#define SYSTEM_FD_CLRER(fd, set) FD_CLR(fd, set) 
	#define SYSTEM_FD_IS_SET(fd, set) FD_ISSET(fd, set) 
	#define SYSTEM_FD_SET(fd, set) FD_SET(fd, set) 
	#define SYSTEM_FD_ZERO(set) FD_ZERO(set) 

#endif // BUILDING_SYSTEM_EXPORT

#endif // SYSTEM_HELPER_NETWORK_MACRO_H
