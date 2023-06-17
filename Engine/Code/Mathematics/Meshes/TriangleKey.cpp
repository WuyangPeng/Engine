///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:21)

#include "Mathematics/MathematicsExport.h"

#include "TriangleKey.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Mathematics::TriangleKey ::TriangleKey(int first, int second, int third) noexcept
    : vertex{ Init(first, second, third) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

std::array<int, Mathematics::TriangleKey::vertexSize> Mathematics::TriangleKey::Init(int first, int second, int third) noexcept
{
    if (first < second)
    {
        if (first < third)
        {
            // first是最小
            return std::array<int, Mathematics::TriangleKey::vertexSize>{ first, second, third };
        }
        else
        {
            // third是最小
            return std::array<int, Mathematics::TriangleKey::vertexSize>{ third, first, second };
        }
    }
    else
    {
        if (second < third)
        {
            // second是最小
            return std::array<int, Mathematics::TriangleKey::vertexSize>{ second, third, first };
        }
        else
        {
            // third是最小
            return std::array<int, Mathematics::TriangleKey::vertexSize>{ third, first, second };
        }
    }
}

Mathematics::TriangleKey::TriangleKey() noexcept
    : vertex{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, TriangleKey)

int Mathematics::TriangleKey::GetKey(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex.at(index);
}

int Mathematics::TriangleKey::GetKeyIndex(int key) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto index = 0; index < vertexSize; ++index)
    {
        if (vertex.at(index) == key)
        {
            return index;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的值。"s));
}

void Mathematics::TriangleKey::SetKey(int index, int value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    vertex.at(index) = value;
}

void Mathematics::TriangleKey::Swap(int lhsIndex, int rhsIndex)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= lhsIndex && lhsIndex < 3 && 0 <= rhsIndex && rhsIndex < 3)
    {
        std::swap(vertex.at(lhsIndex), vertex.at(rhsIndex));
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
    }
}

bool Mathematics::operator<(const TriangleKey& lhs, const TriangleKey& rhs)
{
    if (lhs.GetKey(2) < rhs.GetKey(2))
        return true;
    else if (rhs.GetKey(2) < lhs.GetKey(2))
        return false;
    else if (lhs.GetKey(1) < rhs.GetKey(1))
        return true;
    else if (rhs.GetKey(1) < lhs.GetKey(1))
        return false;
    else
        return lhs.GetKey(0) < rhs.GetKey(0);
}
