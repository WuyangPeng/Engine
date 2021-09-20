///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/09 16:49)

#ifndef SYSTEM_HELPER_NETWORK_MACRO_H
#define SYSTEM_HELPER_NETWORK_MACRO_H

// ��������System���ڲ����ã�����ⲿ��Ҫʹ�ã�WIN32��Ҫ����Ws2_32.lib��

#ifdef BUILDING_SYSTEM_EXPORT

    #define SYSTEM_FD_CLRER(fd, set) FD_CLR(fd, set)
    #define SYSTEM_FD_IS_SET(fd, set) FD_ISSET(fd, set)
    #define SYSTEM_FD_SET(fd, set) FD_SET(fd, set)
    #define SYSTEM_FD_ZERO(set) FD_ZERO(set)

#endif  // BUILDING_SYSTEM_EXPORT

#endif  // SYSTEM_HELPER_NETWORK_MACRO_H
