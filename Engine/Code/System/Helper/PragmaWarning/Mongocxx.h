/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 19:58)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_MONGO_CXX_H
#define SYSTEM_HELPER_PRAGMA_WARNING_MONGO_CXX_H

#include "System/Helper/PragmaWarning.h"

#ifdef DATABASE_USE_MONGO

    #include SYSTEM_WARNING_PUSH

    #include SYSTEM_WARNING_DISABLE(26400)
    #include SYSTEM_WARNING_DISABLE(26409)
    #include SYSTEM_WARNING_DISABLE(26429)
    #include SYSTEM_WARNING_DISABLE(26432)
    #include SYSTEM_WARNING_DISABLE(26434)
    #include SYSTEM_WARNING_DISABLE(26435)
    #include SYSTEM_WARNING_DISABLE(26436)
    #include SYSTEM_WARNING_DISABLE(26440)
    #include SYSTEM_WARNING_DISABLE(26447)
    #include SYSTEM_WARNING_DISABLE(26455)
    #include SYSTEM_WARNING_DISABLE(26457)
    #include SYSTEM_WARNING_DISABLE(26462)
    #include SYSTEM_WARNING_DISABLE(26471)
    #include SYSTEM_WARNING_DISABLE(26473)
    #include SYSTEM_WARNING_DISABLE(26481)
    #include SYSTEM_WARNING_DISABLE(26485)
    #include SYSTEM_WARNING_DISABLE(26495)
    #include SYSTEM_WARNING_DISABLE(26496)

    #include <mongocxx/client.hpp>
    #include <mongocxx/instance.hpp>

    #include SYSTEM_WARNING_POP

#endif  // DATABASE_USE_MONGO

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_MONGO_CXX_H