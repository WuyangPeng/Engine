///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 22:37)

#include "Rendering/RenderingExport.h"

#include "RenderingCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingCopyUnsharedMacroImpl::RenderingCopyUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingCopyUnsharedMacroImpl)

int Rendering::RenderingCopyUnsharedMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Rendering::RenderingCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_Count = count;
}