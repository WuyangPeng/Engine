///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:23)

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