///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 23:05)

#include "Framework/FrameworkExport.h"

#include "FrameworkMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/FrameworkMacroSharedImpl.h"

Framework::FrameworkMacroShared::FrameworkMacroShared(int count)
    : impl{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkMacroShared)

int Framework::FrameworkMacroShared::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Framework::FrameworkMacroShared::SetCount(int count) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
