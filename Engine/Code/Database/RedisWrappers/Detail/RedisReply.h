/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:38)

#ifndef DATABASE_REDIS_WRAPPERS_REDIS_REPLY_H
#define DATABASE_REDIS_WRAPPERS_REDIS_REPLY_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/Hiredis.h"

#ifdef DATABASE_USE_REDIS

namespace Database
{
    class DATABASE_HIDDEN_DECLARE RedisReply final
    {
    public:
        using ClassType = RedisReply;

    public:
        explicit RedisReply(RedisContext& redisContext, const std::string& command);
        ~RedisReply() noexcept;
        RedisReply(const RedisReply& rhs) = delete;
        RedisReply& operator=(const RedisReply& rhs) = delete;
        RedisReply(RedisReply&& rhs) noexcept = delete;
        RedisReply& operator=(RedisReply&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD ::redisReply* GetRedisReply() noexcept;

    private:
        ::redisReply* redisReply;
    };
}

#endif  // DATABASE_USE_REDIS

#endif  // DATABASE_REDIS_WRAPPERS_REDIS_REPLY_H