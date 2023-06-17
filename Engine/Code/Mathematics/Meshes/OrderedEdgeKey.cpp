///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:21)

#include "Mathematics/MathematicsExport.h"

#include "OrderedEdgeKey.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Mathematics::OrderedEdgeKey ::OrderedEdgeKey(int first, int second) noexcept
    : first{ first }, second{ second }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, OrderedEdgeKey)

int Mathematics::OrderedEdgeKey ::GetKey(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (index)
    {
        case 0:
            return first;
        case 1:
            return second;
        default:
            THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
    }
}

bool Mathematics ::operator<(const OrderedEdgeKey& lhs, const OrderedEdgeKey& rhs)
{
    if (lhs.GetKey(1) < rhs.GetKey(1))
    {
        return true;
    }
    else if (rhs.GetKey(1) < lhs.GetKey(1))
    {
        return false;
    }
    else
    {
        return lhs.GetKey(0) < rhs.GetKey(0);
    }
}
