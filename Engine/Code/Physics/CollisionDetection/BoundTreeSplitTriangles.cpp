// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 15:58)

#include "Physics/PhysicsExport.h"

#include "BoundTreeSplitTriangles.h"
#include "Detail/BoundTreeSplitTrianglesImpl.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

using std::make_shared;

Physics::BoundTreeSplitTriangles
	::BoundTreeSplitTriangles(const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction)
	:impl{centroids,beginIndex,endIndex,inSplit,origin,direction }
{
	PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, BoundTreeSplitTriangles)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Physics, BoundTreeSplitTriangles, GetFirstOutSplitIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Physics, BoundTreeSplitTriangles, GetSecondOutSplitIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Physics, BoundTreeSplitTriangles, GetOutSplit, const Physics::BoundTreeSplitTriangles::Split)

 