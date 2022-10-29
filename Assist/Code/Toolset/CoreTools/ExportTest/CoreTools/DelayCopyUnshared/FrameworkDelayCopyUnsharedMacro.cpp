///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:11)

#include "Framework/FrameworkExport.h"

#include "FrameworkDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/FrameworkDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, FrameworkDelayCopyUnsharedMacro)

Framework::FrameworkDelayCopyUnsharedMacro::FrameworkDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkDelayCopyUnsharedMacro)

int Framework::FrameworkDelayCopyUnsharedMacro::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Framework::FrameworkDelayCopyUnsharedMacro::SetCount(int count)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
