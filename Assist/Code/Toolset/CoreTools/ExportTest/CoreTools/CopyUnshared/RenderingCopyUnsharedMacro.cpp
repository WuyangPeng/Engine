///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 09:13)

#include "Rendering/RenderingExport.h"

#include "RenderingCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/RenderingCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RenderingCopyUnsharedMacro)

Rendering::RenderingCopyUnsharedMacro::RenderingCopyUnsharedMacro(int count)
    : impl{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingCopyUnsharedMacro)

int Rendering::RenderingCopyUnsharedMacro::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Rendering::RenderingCopyUnsharedMacro::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Rendering::RenderingCopyUnsharedMacro::GetAddress() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}