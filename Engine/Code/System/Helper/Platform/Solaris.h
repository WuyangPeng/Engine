///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:36)

#ifndef SYSTEM_HELPER_SOLARIS_H
#define SYSTEM_HELPER_SOLARIS_H

#if defined(sun) || defined(__sun)

    //  sun ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Sun Solaris"
    #define SYSTEM_PLATFORM_SOLARIS static_cast<void>(0)

#endif  // defined(sun) || defined(__sun)

#endif  // SYSTEM_HELPER_SOLARIS_H
