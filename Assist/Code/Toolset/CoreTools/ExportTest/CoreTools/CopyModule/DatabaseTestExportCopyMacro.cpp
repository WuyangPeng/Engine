///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 16:24)

#include "Database/DatabaseExport.h"

#include "DatabaseTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/DatabaseTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, DatabaseTestExportCopyMacro)

Database::DatabaseTestExportCopyMacro::DatabaseTestExportCopyMacro(int count)
    : impl{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseTestExportCopyMacro)

int Database::DatabaseTestExportCopyMacro::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Database::DatabaseTestExportCopyMacro::SetCount(int count)
{
    DATABASE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
