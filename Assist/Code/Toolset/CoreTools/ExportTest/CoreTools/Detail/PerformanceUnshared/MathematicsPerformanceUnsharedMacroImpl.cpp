///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 19:05)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::MathematicsPerformanceUnsharedMacroImpl::MathematicsPerformanceUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsPerformanceUnsharedMacroImpl)

int Mathematics::MathematicsPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Mathematics::MathematicsPerformanceUnsharedMacroImpl::SetCount(int count) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    mCount = count;
}
