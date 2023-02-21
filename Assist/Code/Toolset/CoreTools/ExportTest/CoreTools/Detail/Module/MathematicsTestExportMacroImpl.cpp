///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:18)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::MathematicsTestExportMacroImpl::MathematicsTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsTestExportMacroImpl)

int Mathematics::MathematicsTestExportMacroImpl::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Mathematics::MathematicsTestExportMacroImpl::SetCount(int aCount) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    count = aCount;
}
