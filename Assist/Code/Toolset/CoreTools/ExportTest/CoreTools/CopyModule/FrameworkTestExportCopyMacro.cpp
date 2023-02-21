///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 18:50)

#include "Framework/FrameworkExport.h"

#include "FrameworkTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/FrameworkTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, FrameworkTestExportCopyMacro)

Framework::FrameworkTestExportCopyMacro::FrameworkTestExportCopyMacro(int count)
    : impl{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkTestExportCopyMacro)

int Framework::FrameworkTestExportCopyMacro::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Framework::FrameworkTestExportCopyMacro::SetCount(int count)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
