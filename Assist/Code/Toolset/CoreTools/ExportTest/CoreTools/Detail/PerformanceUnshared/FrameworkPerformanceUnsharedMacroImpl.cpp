/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:13)

#include "Framework/FrameworkExport.h"

#include "FrameworkPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FrameworkPerformanceUnsharedMacroImpl::FrameworkPerformanceUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkPerformanceUnsharedMacroImpl)

int Framework::FrameworkPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return count;
}
