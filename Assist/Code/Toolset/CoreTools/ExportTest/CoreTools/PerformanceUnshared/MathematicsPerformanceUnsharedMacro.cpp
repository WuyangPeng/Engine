/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:25)

#include "Mathematics/MathematicsExport.h"

#include "MathematicsPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/MathematicsPerformanceUnsharedMacroImpl.h"

Mathematics::MathematicsPerformanceUnsharedMacro::MathematicsPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, MathematicsPerformanceUnsharedMacro)

int Mathematics::MathematicsPerformanceUnsharedMacro::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* Mathematics::MathematicsPerformanceUnsharedMacro::GetAddress() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}