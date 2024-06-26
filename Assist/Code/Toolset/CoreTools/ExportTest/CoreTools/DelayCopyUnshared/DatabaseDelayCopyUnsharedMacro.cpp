/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:01)

#include "Database/DatabaseExport.h"

#include "DatabaseDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/DatabaseDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, DatabaseDelayCopyUnsharedMacro)

Database::DatabaseDelayCopyUnsharedMacro::DatabaseDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseDelayCopyUnsharedMacro)

int Database::DatabaseDelayCopyUnsharedMacro::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Database::DatabaseDelayCopyUnsharedMacro::SetCount(int count)
{
    DATABASE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Database::DatabaseDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}