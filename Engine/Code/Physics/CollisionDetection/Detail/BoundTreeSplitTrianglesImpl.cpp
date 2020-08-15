// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 15:57)

#include "Physics/PhysicsExport.h"

#include "BoundTreeSplitTrianglesImpl.h" 
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "CoreTools/Helper/Assertion/PhysicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Physics/CollisionDetection/BoundTreeProjectionInfo.h"

using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26486)
Physics::BoundTreeSplitTrianglesImpl
	::BoundTreeSplitTrianglesImpl(const Centroids& centroids, int beginIndex,int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction)
	:m_FirstOutSplitIndex{ 0 }, m_SecondOutSplitIndex{ 0 }, m_OutSplit(inSplit.size())
{
	SplitTriangles(centroids, beginIndex, endIndex, inSplit, origin, direction);

	PHYSICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Physics::BoundTreeSplitTrianglesImpl
	::IsValid() const noexcept
{
	if (0 <= m_FirstOutSplitIndex && m_FirstOutSplitIndex <= m_SecondOutSplitIndex)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Physics::BoundTreeSplitTrianglesImpl ::GetFirstOutSplitIndex() const noexcept
{
	PHYSICS_CLASS_IS_VALID_CONST_1;	

	return m_FirstOutSplitIndex;
}

int Physics::BoundTreeSplitTrianglesImpl ::GetSecondOutSplitIndex() const noexcept
{
	PHYSICS_CLASS_IS_VALID_CONST_1;	

	return m_SecondOutSplitIndex;
}

const Physics::BoundTreeSplitTrianglesImpl::Split Physics::BoundTreeSplitTrianglesImpl
	::GetOutSplit() const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;	

	return m_OutSplit;
}

void Physics::BoundTreeSplitTrianglesImpl
	::SplitTriangles(const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction)
{
	PHYSICS_ASSERTION_2(beginIndex <= endIndex && endIndex < static_cast<int>(inSplit.size()),"beginIndex大于endIndex");

	// 投射到特定行
	const int quantity = endIndex - beginIndex + 1;
	vector<BoundTreeProjectionInfo> info;
 
	for (int i = beginIndex; i <= endIndex; ++i)
    {
            const int triangle = inSplit[i];
		AVector difference = centroids[triangle] - origin;
		info.push_back(BoundTreeProjectionInfo(triangle, Dot(direction, difference)));	
    }

	PHYSICS_ASSERTION_2(quantity == static_cast<int>(info.size()),"BoundTreeProjectionInfo大小错误。");
	  
	// 通过排序查找投影的中值。
    sort(info.begin(), info.end());
        const int median = (quantity - 1) / 2;

    // 用中间值分隔三角形。
	m_FirstOutSplitIndex = beginIndex - 1;
    for (int i = 0; i <= median; ++i)
    {
		m_OutSplit[++m_FirstOutSplitIndex] = info[i].GetTriangle();
    }

	m_SecondOutSplitIndex = endIndex + 1;
	for (int i = median + 1; i < quantity; ++i)
    {
		m_OutSplit[--m_SecondOutSplitIndex] = info[i].GetTriangle();
    }
}

#include STSTEM_WARNING_POP