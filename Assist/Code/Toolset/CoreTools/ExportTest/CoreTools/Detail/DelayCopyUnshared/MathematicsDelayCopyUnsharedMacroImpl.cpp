///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/01 14:12)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::MathematicsDelayCopyUnsharedMacroImpl::MathematicsDelayCopyUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsDelayCopyUnsharedMacroImpl)

int Mathematics::MathematicsDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Mathematics::MathematicsDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    mCount = count;
}
