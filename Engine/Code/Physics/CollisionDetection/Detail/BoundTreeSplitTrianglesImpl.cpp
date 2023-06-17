///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 16:38)

#include "Physics/PhysicsExport.h"

#include "BoundTreeSplitTrianglesImpl.h"
#include "CoreTools/Helper/Assertion/PhysicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Physics/CollisionDetection/BoundTreeProjectionInfo.h"

#include <algorithm>

Physics::BoundTreeSplitTrianglesImpl::BoundTreeSplitTrianglesImpl(const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction)
    : outSplitIndex0{ 0 }, outSplitIndex1{ 0 }, outSplit(inSplit.size())
{
    SplitTriangles(centroids, beginIndex, endIndex, inSplit, origin, direction);

    PHYSICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Physics::BoundTreeSplitTrianglesImpl::IsValid() const noexcept
{
    if (0 <= outSplitIndex0 && outSplitIndex0 <= outSplitIndex1)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Physics::BoundTreeSplitTrianglesImpl::GetFirstOutSplitIndex() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return outSplitIndex0;
}

int Physics::BoundTreeSplitTrianglesImpl::GetSecondOutSplitIndex() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return outSplitIndex1;
}

Physics::BoundTreeSplitTrianglesImpl::Split Physics::BoundTreeSplitTrianglesImpl::GetOutSplit() const
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return outSplit;
}

void Physics::BoundTreeSplitTrianglesImpl::SplitTriangles(const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction)
{
    PHYSICS_ASSERTION_2(beginIndex <= endIndex && endIndex < boost::numeric_cast<int>(inSplit.size()), "beginIndex����endIndex");

    // Ͷ�䵽�ض���
    const auto quantity = endIndex - beginIndex + 1;
    std::vector<BoundTreeProjectionInfo> info;

    for (auto i = beginIndex; i <= endIndex; ++i)
    {
        const auto triangle = inSplit.at(i);
        const auto difference = centroids.at(triangle) - origin;
        info.emplace_back(triangle, Dot(direction, difference));
    }

    PHYSICS_ASSERTION_2(quantity == boost::numeric_cast<int>(info.size()), "BoundTreeProjectionInfo��С����");

    // ͨ���������ͶӰ����ֵ��
    std::sort(info.begin(), info.end());
    const auto median = (quantity - 1) / 2;

    // ���м�ֵ�ָ������Ρ�
    outSplitIndex0 = beginIndex - 1;
    for (auto i = 0; i <= median; ++i)
    {
        outSplit.at(++outSplitIndex0) = info.at(i).GetTriangle();
    }

    outSplitIndex1 = endIndex + 1;
    for (auto i = median + 1; i < quantity; ++i)
    {
        outSplit.at(--outSplitIndex1) = info.at(i).GetTriangle();
    }
}
