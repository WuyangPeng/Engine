///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:36)

#include "Database/DatabaseExport.h"

#include "DatabaseMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::DatabaseMacroSharedImpl::DatabaseMacroSharedImpl(int count) noexcept
    : count{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseMacroSharedImpl)

int Database::DatabaseMacroSharedImpl::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return count;
}

void Database::DatabaseMacroSharedImpl::SetCount(int aCount) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    count = aCount;
}
