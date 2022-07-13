///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:40)

#include "Database/DatabaseExport.h"

#include "DatabaseTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::DatabaseTestExportCopyMacroImpl::DatabaseTestExportCopyMacroImpl(int count) noexcept
    : mCount{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseTestExportCopyMacroImpl)

int Database::DatabaseTestExportCopyMacroImpl::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Database::DatabaseTestExportCopyMacroImpl::SetCount(int count) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    mCount = count;
}
