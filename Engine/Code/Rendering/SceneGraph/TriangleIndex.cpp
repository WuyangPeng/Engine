///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:18)

#include "Rendering/RenderingExport.h"

#include "TriangleIndex.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::TriangleIndex::TriangleIndex(int firstIndex, int secondIndex, int thirdIndex) noexcept
    : index0{ firstIndex }, index1{ secondIndex }, index2{ thirdIndex }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::TriangleIndex::IsValid() const noexcept
{
    if (0 <= index0 && 0 <= index1 && 0 <= index2)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::TriangleIndex::GetFirstIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return index0;
}

int Rendering::TriangleIndex::GetSecondIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return index1;
}

int Rendering::TriangleIndex::GetThirdIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return index2;
}

int Rendering::TriangleIndex::operator[](int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < 3, "索引越界！");

    switch (index)
    {
        case 0:
            return index0;
        case 1:
            return index1;
        default:
            return index2;
    }
}
