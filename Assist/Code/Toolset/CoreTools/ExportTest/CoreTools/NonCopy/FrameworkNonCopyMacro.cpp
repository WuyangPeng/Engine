///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/14 15:53)

#include "Framework/FrameworkExport.h"

#include "FrameworkNonCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/NonCopy/FrameworkNonCopyMacroImpl.h"

Framework::FrameworkNonCopyMacro::FrameworkNonCopyMacro(int count)
    : impl{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkNonCopyMacro)

int Framework::FrameworkNonCopyMacro::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Framework::FrameworkNonCopyMacro::SetCount(int count) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
