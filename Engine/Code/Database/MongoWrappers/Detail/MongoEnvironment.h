﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:43)

#ifndef DATABASE_MONGO_WRAPPERS_MONGO_CONNECTION_H
#define DATABASE_MONGO_WRAPPERS_MONGO_CONNECTION_H

#include "Database/DatabaseDll.h"

#include <atomic>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MongoEnvironment final
    {
    public:
        using ClassType = MongoEnvironment;

    public:
        MongoEnvironment() noexcept;

        CLASS_INVARIANT_DECLARE;

        void InitEnvironment();

    private:
        static std::atomic_bool isInit;
    };
}

#endif  // DATABASE_MONGO_WRAPPERS_MONGO_CONNECTION_H