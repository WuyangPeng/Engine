///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:41)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportSharedImplMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportSharedImplMacroSharedImpl.h"

ExportTest::ExportSharedImplMacroShared::ExportSharedImplMacroShared(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, ExportSharedImplMacroShared)

int ExportTest::ExportSharedImplMacroShared::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ExportTest::ExportSharedImplMacroShared::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
