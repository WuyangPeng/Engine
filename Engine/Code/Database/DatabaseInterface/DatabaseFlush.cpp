///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 22:21)

#include "Database/DatabaseExport.h"

#include "DatabaseFlush.h"
#include "Detail/DatabaseFlushFactory.h"
#include "Detail/DatabaseFlushImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseManagerDetail.h"

Database::DatabaseFlush::DatabaseFlush(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseFlush)

void Database::DatabaseFlush::ChangeDatabase(int64_t userId, const BasisDatabaseManager& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->ChangeDatabase(userId, basisDatabaseContainer);
}

Database::BasisDatabaseManager Database::DatabaseFlush::SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->SelectOne(basisDatabaseContainer, fieldNameContainer);
}

Database::DatabaseFlush::ResultContainer Database::DatabaseFlush::SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->SelectAll(basisDatabaseContainer, fieldNameContainer);
}
