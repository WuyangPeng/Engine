///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 18:40)

#include "Database/DatabaseExport.h"

#include "DatabaseTestExportMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Module/DatabaseTestExportMacroImpl.h"

Database::DatabaseTestExportMacro::DatabaseTestExportMacro(int count)
    : impl{ count }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseTestExportMacro)

int Database::DatabaseTestExportMacro::GetCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}
