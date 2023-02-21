///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 19:39)

#include "Rendering/RenderingExport.h"

#include "RenderingMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/RenderingMacroSharedImpl.h"

Rendering::RenderingMacroShared::RenderingMacroShared(int count)
    : impl{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingMacroShared)

int Rendering::RenderingMacroShared::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Rendering::RenderingMacroShared::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Rendering::RenderingMacroShared::GetAddress() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}