///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 20:32)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "CopyUnsharedUseCloneMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/CopyUnsharedUseCloneMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(ExportTest, CopyUnsharedUseCloneMacro)

ExportTest::CopyUnsharedUseCloneMacro::CopyUnsharedUseCloneMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, CopyUnsharedUseCloneMacro)

int ExportTest::CopyUnsharedUseCloneMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ExportTest::CopyUnsharedUseCloneMacro::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
