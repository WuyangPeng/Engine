///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:12)

#include "Rendering/RenderingExport.h"

#include "RenderingDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/RenderingDelayCopyUnsharedMacroImpl.h"

Rendering::RenderingDelayCopyUnsharedMacro::RenderingDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingDelayCopyUnsharedMacro)

int Rendering::RenderingDelayCopyUnsharedMacro::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Rendering::RenderingDelayCopyUnsharedMacro::SetCount(int count)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RenderingDelayCopyUnsharedMacro)
