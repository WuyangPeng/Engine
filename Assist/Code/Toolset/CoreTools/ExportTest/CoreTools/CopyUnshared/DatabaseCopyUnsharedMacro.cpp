///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 09:14)

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