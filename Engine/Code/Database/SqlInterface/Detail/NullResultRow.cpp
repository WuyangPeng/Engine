///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 17:05)

#include "Database/DatabaseExport.h"

#include "NullResultRow.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::NullResultRow::NullResultRow(const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, NullResultRow)

int Database::NullResultRow::GetColCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return 0;
}

void Database::NullResultRow::Print(MAYBE_UNUSED std::ostream& os) const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;
}
