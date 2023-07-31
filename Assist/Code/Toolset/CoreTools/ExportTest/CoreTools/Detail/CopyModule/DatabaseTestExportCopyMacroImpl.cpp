///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:46)

#include "Database/DatabaseExport.h"

#include "DatabaseTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::DatabaseTestExportCopyMacroImpl::DatabaseTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseTestExportCopyMacroImpl)

int Database::DatabaseTestExportCopyMacroImpl::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return count;
}

void Database::DatabaseTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    count = aCount;
}
