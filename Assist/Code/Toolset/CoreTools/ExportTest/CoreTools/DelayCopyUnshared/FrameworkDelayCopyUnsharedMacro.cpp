///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 09:12)

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

const void* Framework::FrameworkDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}