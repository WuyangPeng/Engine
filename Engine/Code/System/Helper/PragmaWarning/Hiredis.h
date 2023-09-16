///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 10:29)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_HIREDIS_H
#define SYSTEM_HELPER_PRAGMA_WARNING_HIREDIS_H

#include "System/Helper/PragmaWarning.h"

#ifdef DATABASE_USE_REDIS

    #include SYSTEM_WARNING_PUSH

    #include SYSTEM_WARNING_DISABLE(4200)
    #include SYSTEM_WARNING_DISABLE(4244)
    #include SYSTEM_WARNING_DISABLE(26429)
    #include SYSTEM_WARNING_DISABLE(26440)
    #include SYSTEM_WARNING_DISABLE(26461)
    #include SYSTEM_WARNING_DISABLE(26462)
    #include SYSTEM_WARNING_DISABLE(26481)
    #include SYSTEM_WARNING_DISABLE(26485)
    #include SYSTEM_WARNING_DISABLE(26493)
    #include SYSTEM_WARNING_DISABLE(26496)
    #include SYSTEM_WARNING_DISABLE(26818)

    #include <hiredis.h>

    #include SYSTEM_WARNING_POP

#endif  // DATABASE_USE_REDIS

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_HIREDIS_H