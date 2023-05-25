///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 15:34)

#include "Database/DatabaseExport.h"

#include "MongoEnvironment.h"
#include "System/Helper/PragmaWarning/Mongocxx.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::MongoEnvironment::MongoEnvironment() noexcept
    : isInit{ false }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, MongoEnvironment)

void Database::MongoEnvironment::InitEnvironment()
{
    DATABASE_CLASS_IS_VALID_9;

#ifdef DATABASE_USE_MONGO

    if (!isInit)
    {
        mongocxx::instance instance{};
    }

#endif  // DATABASE_USE_MONGO

    isInit = true;
}
