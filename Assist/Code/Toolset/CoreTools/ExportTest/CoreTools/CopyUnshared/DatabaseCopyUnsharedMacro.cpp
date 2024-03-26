/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:59)

#include "Database/DatabaseExport.h"

#include "DatabaseCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/DatabaseCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, DatabaseCopyUnsharedMacro)

Database::DatabaseCopyUnsharedMacro::DatabaseCopyUnsharedMacro(int count)
    : impl{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseCopyUnsharedMacro)

int Database::DatabaseCopyUnsharedMacro::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Database::DatabaseCopyUnsharedMacro::SetCount(int count) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Database::DatabaseCopyUnsharedMacro::GetAddress() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}