///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 19:02)

#include "Database/DatabaseExport.h"

#include "DatabaseMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::DatabaseMacroSharedImpl::DatabaseMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseMacroSharedImpl)

int Database::DatabaseMacroSharedImpl::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Database::DatabaseMacroSharedImpl::SetCount(int count) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    mCount = count;
}
