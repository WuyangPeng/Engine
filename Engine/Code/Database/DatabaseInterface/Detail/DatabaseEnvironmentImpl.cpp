///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 20:42)

#include "Database/DatabaseExport.h"

#include "DatabaseEnvironmentImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseEnvironmentImpl)

Database::DatabaseEnvironmentImpl::DatabaseEnvironmentImpl() noexcept
    : mongoEnvironment{}
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

void Database::DatabaseEnvironmentImpl::InitEnvironment(const ConfigurationStrategy& configurationStrategy)
{
    DATABASE_CLASS_IS_VALID_9;

    using System::operator&;
    if ((configurationStrategy.GetWrappersStrategy() & WrappersStrategy::Mongo) != WrappersStrategy::Null)
    {
        mongoEnvironment.InitEnvironment();
    }
}
