///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:37)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::MathematicsMacroSharedImpl::MathematicsMacroSharedImpl(int count) noexcept
    : count{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsMacroSharedImpl)

int Mathematics::MathematicsMacroSharedImpl::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Mathematics::MathematicsMacroSharedImpl::SetCount(int aCount) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    count = aCount;
}
