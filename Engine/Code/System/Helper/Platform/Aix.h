///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/16 22:06)

#ifndef SYSTEM_HELPER_AIX_H
#define SYSTEM_HELPER_AIX_H

#if defined(__IBMCPP__) || defined(_AIX)

    //  IBM/Aix ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "IBM Aix"
    #define SYSTEM_PLATFORM_AIX static_cast<void>(0)

#endif  // defined(__IBMCPP__) || defined(_AIX)

#endif  // SYSTEM_HELPER_AIX_H
