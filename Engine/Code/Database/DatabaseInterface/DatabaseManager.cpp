///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:49)

#include "Database/DatabaseExport.h"

#include "DatabaseManager.h"
#include "Detail/DatabaseManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, DatabaseManager)

Database::DatabaseManager::DatabaseManager(const std::string& fileName)
    : impl{ fileName }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseManager)

void Database::DatabaseManager::ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseManager& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->ChangeDatabase(databaseIndex, userId, basisDatabaseContainer);
}

Database::BasisDatabaseManager Database::DatabaseManager::SelectOne(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->SelectOne(databaseIndex, basisDatabaseContainer, fieldNameContainer);
}

Database::DatabaseManager::ResultContainer Database::DatabaseManager::SelectAll(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->SelectAll(databaseIndex, basisDatabaseContainer, fieldNameContainer);
}
