///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 14:43)

#define FUNCTION_DESCRIBED_NO_EXPORT

#include "CoreTools/CoreToolsExport.h"

#include "CoreToolsTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/CoreToolsTestExportCopyMacroImpl.h"

CoreTools::CoreToolsTestExportCopyMacro::CoreToolsTestExportCopyMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CoreToolsTestExportCopyMacro)

int CoreTools::CoreToolsTestExportCopyMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void CoreTools::CoreToolsTestExportCopyMacro::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, CoreToolsTestExportCopyMacro)