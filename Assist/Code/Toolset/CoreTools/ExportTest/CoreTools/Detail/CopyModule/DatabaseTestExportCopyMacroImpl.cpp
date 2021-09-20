///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 22:21)

#include "Database/DatabaseExport.h"

#include "DatabaseTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::DatabaseTestExportCopyMacroImpl::DatabaseTestExportCopyMacroImpl(int count) noexcept
    : m_Count{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseTestExportCopyMacroImpl)

int Database::DatabaseTestExportCopyMacroImpl::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Database::DatabaseTestExportCopyMacroImpl::SetCount(int count) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    m_Count = count;
}
