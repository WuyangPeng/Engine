///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 13:58)

#include "Physics/PhysicsExport.h"

#include "BoundTreeSplitTriangles.h"
#include "Detail/BoundTreeSplitTrianglesImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Physics::BoundTreeSplitTriangles::BoundTreeSplitTriangles(const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction)
    : impl{ centroids, beginIndex, endIndex, inSplit, origin, direction }
{
    PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, BoundTreeSplitTriangles)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Physics, BoundTreeSplitTriangles, GetFirstOutSplitIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Physics, BoundTreeSplitTriangles, GetSecondOutSplitIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Physics, BoundTreeSplitTriangles, GetOutSplit, Physics::BoundTreeSplitTriangles::Split)
