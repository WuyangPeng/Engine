/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:21)

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
