/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:05)

#include "Database/DatabaseExport.h"

#include "DatabaseCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::DatabaseCopyUnsharedMacroImpl::DatabaseCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseCopyUnsharedMacroImpl)

int Database::DatabaseCopyUnsharedMacroImpl::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return count;
}

void Database::DatabaseCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    count = aCount;
}
