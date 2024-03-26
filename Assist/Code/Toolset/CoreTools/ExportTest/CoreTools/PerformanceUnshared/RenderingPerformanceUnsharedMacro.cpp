/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 10:25)

#include "Rendering/RenderingExport.h"

#include "RenderingPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/RenderingPerformanceUnsharedMacroImpl.h"

Rendering::RenderingPerformanceUnsharedMacro::RenderingPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingPerformanceUnsharedMacro)

int Rendering::RenderingPerformanceUnsharedMacro::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* Rendering::RenderingPerformanceUnsharedMacro::GetAddress() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}