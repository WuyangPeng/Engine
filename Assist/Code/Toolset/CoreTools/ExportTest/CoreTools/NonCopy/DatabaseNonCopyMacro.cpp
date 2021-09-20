///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/14 15:52)

#include "Database/DatabaseExport.h"

#include "DatabaseNonCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/NonCopy/DatabaseNonCopyMacroImpl.h"

Database::DatabaseNonCopyMacro::DatabaseNonCopyMacro(int count)
    : impl{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseNonCopyMacro)

int Database::DatabaseNonCopyMacro::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Database::DatabaseNonCopyMacro::SetCount(int count) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
