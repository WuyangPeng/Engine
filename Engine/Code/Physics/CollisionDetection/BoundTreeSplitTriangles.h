// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 15:33)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/APoint.h"
#include "CoreTools/Helper/ExportMacro.h"

PHYSICS_EXPORT_SHARED_PTR(BoundTreeSplitTrianglesImpl);

namespace Physics
{
	class PHYSICS_DEFAULT_DECLARE BoundTreeSplitTriangles
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(BoundTreeSplitTriangles);
		using AVector = Mathematics::AVectorf;
		using APoint = Mathematics::APointf;
		using Centroids = std::vector<APoint>;
		using Split = std::vector<int>;

	public:
		BoundTreeSplitTriangles(const Centroids& centroids,int beginIndex, int endIndex,
								const Split& inSplit,const APoint& origin,const AVector& direction);

		CLASS_INVARIANT_DECLARE;

		int GetFirstOutSplitIndex() const;
		int GetSecondOutSplitIndex() const;
		const Split GetOutSplit() const;

	private:
		IMPL_TYPE_DECLARE(BoundTreeSplitTriangles);
	};
}

#endif // PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H
