///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 20:57)

#include "Rendering/RenderingExport.h"

#include "RenderingTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingTestExportMacroImpl::RenderingTestExportMacroImpl(int count) noexcept
    : m_Count{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingTestExportMacroImpl)

int Rendering::RenderingTestExportMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Rendering::RenderingTestExportMacroImpl::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_Count = count;
}