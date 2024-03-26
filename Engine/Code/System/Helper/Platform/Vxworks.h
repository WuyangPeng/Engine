/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 19:55)

#ifndef SYSTEM_HELPER_VXWORKS_H
#define SYSTEM_HELPER_VXWORKS_H

#if defined(__VXWORKS__)

    #include <version.h>

    #if !defined(_WRS_VXWORKS_MAJOR) || (_WRS_VXWORKS_MAJOR < 6)

        #error "��ʹ�õ�vxWorks�汾�Ƿǳ���ʱ�ġ�"

    #endif  // !defined(_WRS_VXWORKS_MAJOR) || (_WRS_VXWORKS_MAJOR < 6)

    /// vxWorks ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "vxWorks"
    #define SYSTEM_PLATFORM_VXWORKS static_cast<void>(0)

    #if (_WRS_VXWORKS_MAJOR < 7)

        #ifdef __RTP__

            #include <sysLib.h>
            #include <time.h>

        #endif  // __RTP__

        #include <cstdint>

        #undef INT32_C
        #undef UINT32_C
        #undef INT64_C
        #undef UINT64_C
        #define INT32_C(x) SYSTEM_CONCATENATOR(x, L)
        #define UINT32_C(x) SYSTEM_CONCATENATOR(x, UL)
        #define INT64_C(x) SYSTEM_CONCATENATOR(x, LL)
        #define UINT64_C(x) SYSTEM_CONCATENATOR(x, ULL)

        #include <sys/time.h>

    #endif  // _WRS_VXWORKS_MAJOR < 7

    #include <ioLib.h>
    #include <tickLib.h>

#endif  // defined(__VXWORKS__)

#endif  // SYSTEM_HELPER_VXWORKS_H
