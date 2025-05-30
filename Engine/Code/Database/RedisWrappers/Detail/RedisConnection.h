﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:38)

#ifndef DATABASE_REDIS_WRAPPERS_REDIS_CONNECTION_H
#define DATABASE_REDIS_WRAPPERS_REDIS_CONNECTION_H

#include "Database/DatabaseDll.h"

#include "RedisContext.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>

#ifdef DATABASE_USE_REDIS

namespace Database
{
    class DATABASE_HIDDEN_DECLARE RedisConnection final
    {
    public:
        using ClassType = RedisConnection;

        using ResultContainer = std::vector<BasisDatabaseManager>;
        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        explicit RedisConnection(const ConfigurationStrategy& configurationStrategy);
        ~RedisConnection() noexcept;
        RedisConnection(const RedisConnection& rhs) = delete;
        RedisConnection& operator=(const RedisConnection& rhs) = delete;
        RedisConnection(RedisConnection&& rhs) noexcept = delete;
        RedisConnection& operator=(RedisConnection&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        void ChangeDatabase(const BasisDatabaseManager& basisDatabaseContainer);

        NODISCARD BasisDatabaseManager SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer);
        NODISCARD ResultContainer SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer);

        void Wait();

    private:
        using Container = std::deque<BasisDatabaseManager>;

    private:
        NODISCARD BasisDatabaseManager ExtractNext() noexcept;

        void WaitThread();
        void Execution();

        void SetThread();
        void Stop();
        void Join();

        NODISCARD static BasisDatabase GetBasisDatabase(const DatabaseField& fieldName, const ::redisReply* redisReply);

    private:
        ConfigurationStrategy configurationStrategy;
        RedisContext redisContext;

        Container container;
        std::thread thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        volatile bool isStop;
    };
}

#endif  // DATABASE_USE_REDIS

#endif  // DATABASE_REDIS_WRAPPERS_REDIS_CONNECTION_H