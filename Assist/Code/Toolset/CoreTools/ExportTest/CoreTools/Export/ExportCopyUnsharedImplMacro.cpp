///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 18:59)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportCopyUnsharedImplMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportCopyUnsharedImplMacroImpl.h"

ExportTest::ExportCopyUnsharedImplMacro::ExportCopyUnsharedImplMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, ExportCopyUnsharedImplMacro)
COPY_UNSHARED_CLONE_SELF_DEFINE(ExportTest, ExportCopyUnsharedImplMacro)

int ExportTest::ExportCopyUnsharedImplMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ExportTest::ExportCopyUnsharedImplMacro::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
