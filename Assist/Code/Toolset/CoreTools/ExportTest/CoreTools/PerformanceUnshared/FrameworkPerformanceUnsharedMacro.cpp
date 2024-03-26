/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:24)

#include "Framework/FrameworkExport.h"

#include "FrameworkPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/FrameworkPerformanceUnsharedMacroImpl.h"

Framework::FrameworkPerformanceUnsharedMacro::FrameworkPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkPerformanceUnsharedMacro)

int Framework::FrameworkPerformanceUnsharedMacro::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* Framework::FrameworkPerformanceUnsharedMacro::GetAddress() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}