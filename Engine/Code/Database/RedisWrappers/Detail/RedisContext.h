﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:38)

#ifndef DATABASE_REDIS_WRAPPERS_REDIS_CONTEXT_H
#define DATABASE_REDIS_WRAPPERS_REDIS_CONTEXT_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/Hiredis.h"
#include "Database/Configuration/ConfigurationFwd.h"

#ifdef DATABASE_USE_REDIS

namespace Database
{
    class DATABASE_HIDDEN_DECLARE RedisContext final
    {
    public:
        using ClassType = RedisContext;

    public:
        explicit RedisContext(const ConfigurationStrategy& configurationStrategy);
        ~RedisContext() noexcept;
        RedisContext(const RedisContext& rhs) = delete;
        RedisContext& operator=(const RedisContext& rhs) = delete;
        RedisContext(RedisContext&& rhs) noexcept = delete;
        RedisContext& operator=(RedisContext&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD ::redisContext* GetRedisContext() noexcept;

    private:
        ::redisContext* redisContext;
    };
}

#endif  // DATABASE_USE_REDIS

#endif  // DATABASE_REDIS_WRAPPERS_REDIS_CONTEXT_H