///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 22:03)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::MathematicsMacroSharedImpl::MathematicsMacroSharedImpl(int count) noexcept
    : m_Count{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsMacroSharedImpl)

int Mathematics::MathematicsMacroSharedImpl::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Mathematics::MathematicsMacroSharedImpl::SetCount(int count) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Count = count;
}
