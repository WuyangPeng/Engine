/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:49)

#include "Database/DatabaseExport.h"

#include "DatabaseEnvironment.h"
#include "Detail/DatabaseEnvironmentImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

SINGLETON_GET_PTR_DEFINE(Database, DatabaseEnvironment);

Database::DatabaseEnvironment::DatabaseEnvironmentUniquePtr Database::DatabaseEnvironment::databaseEnvironment{};

void Database::DatabaseEnvironment::Create()
{
    databaseEnvironment = std::make_unique<DatabaseEnvironment>(DatabaseEnvironmentCreate::Init);
}

void Database::DatabaseEnvironment::Destroy() noexcept
{
    databaseEnvironment.reset();
}

Database::DatabaseEnvironment::DatabaseEnvironment(DatabaseEnvironmentCreate databaseEnvironmentCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(databaseEnvironmentCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseEnvironment)

void Database::DatabaseEnvironment::InitEnvironment(const ConfigurationStrategy& configurationStrategy)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->InitEnvironment(configurationStrategy);
}
