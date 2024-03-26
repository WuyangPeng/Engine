/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:43)

#ifndef SYSTEM_HELPER_MSL_H
#define SYSTEM_HELPER_MSL_H

#if defined(__MSL_CPP__)

    ///  Metrowerks ��׼��

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION __MSL_CPP__

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef TCRE_SYSTEM_STD_LIB

        #define TCRE_SYSTEM_STD_LIB "Metrowerks ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #endif  // !TCRE_SYSTEM_STD_LIB

    #define TCRE_USE_MSL static_cast<void>(0)

#endif  // __MSL_CPP__

#endif  // SYSTEM_HELPER_MSL_H
