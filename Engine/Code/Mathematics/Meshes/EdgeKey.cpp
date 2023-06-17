///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:18)

#include "Mathematics/MathematicsExport.h"

#include "EdgeKey.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <ostream>

Mathematics::EdgeKey ::EdgeKey(int first, int second) noexcept
    : vertex{ Init(first, second) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

std::array<int, 2> Mathematics::EdgeKey::Init(int first, int second) noexcept
{
    return (first < second) ? std::array<int, 2>{ first, second } : std::array<int, 2>{ second, first };
}

Mathematics::EdgeKey::EdgeKey() noexcept
    : vertex{ -1, -1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, EdgeKey)

int Mathematics::EdgeKey::GetKey(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex.at(index);
}

void Mathematics::EdgeKey ::SetKey(int index, int value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    vertex.at(index) = value;
}

bool Mathematics::operator<(const EdgeKey& lhs, const EdgeKey& rhs)
{
    if (lhs.GetKey(1) < rhs.GetKey(1))
        return true;
    else if (rhs.GetKey(1) < lhs.GetKey(1))
        return false;
    else
        return lhs.GetKey(0) < rhs.GetKey(0);
}

System::OStream& Mathematics::operator<<(System::OStream& os, const EdgeKey& edgeKey)
{
    os << edgeKey.GetKey(0) << "-" << edgeKey.GetKey(1);

    return os;
}
