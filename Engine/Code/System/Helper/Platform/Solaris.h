///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/11 23:20)

#ifndef SYSTEM_HELPER_SOLARIS_H
#define SYSTEM_HELPER_SOLARIS_H

#if defined(sun) || defined(__sun)

    //  sun ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Sun Solaris"
    #define SYSTEM_PLATFORM_SOLARIS static_cast<void>(0)

#endif  // defined(sun) || defined(__sun)

#endif  // SYSTEM_HELPER_SOLARIS_H
