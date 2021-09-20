///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 21:39)

#include "Database/DatabaseExport.h"

#include "DatabasePerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::DatabasePerformanceUnsharedMacroImpl::DatabasePerformanceUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabasePerformanceUnsharedMacroImpl)

int Database::DatabasePerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Database::DatabasePerformanceUnsharedMacroImpl::SetCount(int count) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    m_Count = count;
}
