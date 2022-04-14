///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/23 16:37)

#include "Mathematics/MathematicsExport.h"

#include "UnorderedTriangleKey.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <algorithm>

Mathematics::UnorderedTriangleKey::UnorderedTriangleKey(int first, int second, int third) noexcept
    : vertex{}
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (first < second)
    {
        if (first < third)
        {
            // first是最小
            vertex[0] = first;
            vertex[1] = std::min(second, third);
            vertex[2] = std::max(second, third);
        }
        else
        {
            // third是最小
            vertex[0] = third;
            vertex[1] = std::min(first, second);
            vertex[2] = std::max(first, second);
        }
    }
    else
    {
        if (second < third)
        {
            // second是最小
            vertex[0] = second;
            vertex[1] = std::min(third, first);
            vertex[2] = std::max(third, first);
        }
        else
        {
            // third是最小
            vertex[0] = third;
            vertex[1] = std::min(first, second);
            vertex[2] = std::max(first, second);
        }
    }

#include STSTEM_WARNING_POP

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, UnorderedTriangleKey)

int Mathematics::UnorderedTriangleKey::GetKey(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex.at(index);
}

bool Mathematics::operator<(const UnorderedTriangleKey& lhs, const UnorderedTriangleKey& rhs)
{
    if (lhs.GetKey(2) < rhs.GetKey(2))
    {
        return true;
    }

    if (rhs.GetKey(2) < lhs.GetKey(2))
    {
        return false;
    }

    if (lhs.GetKey(1) < rhs.GetKey(1))
    {
        return true;
    }

    if (rhs.GetKey(1) < lhs.GetKey(1))
    {
        return false;
    }

    return lhs.GetKey(0) < rhs.GetKey(0);
}
