///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 17:14)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::MathematicsDelayCopyUnsharedMacroImpl::MathematicsDelayCopyUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsDelayCopyUnsharedMacroImpl)

int Mathematics::MathematicsDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Mathematics::MathematicsDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Count = count;
}