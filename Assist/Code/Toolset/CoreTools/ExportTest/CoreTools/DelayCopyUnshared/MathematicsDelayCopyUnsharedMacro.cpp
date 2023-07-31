///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:40)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/MathematicsDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Mathematics, MathematicsDelayCopyUnsharedMacro)

Mathematics::MathematicsDelayCopyUnsharedMacro::MathematicsDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsDelayCopyUnsharedMacro)

int Mathematics::MathematicsDelayCopyUnsharedMacro::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Mathematics::MathematicsDelayCopyUnsharedMacro::SetCount(int count)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Mathematics::MathematicsDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}