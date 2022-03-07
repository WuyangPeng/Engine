// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 15:28)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_IMPL_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_IMPL_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

#include <vector>

namespace Physics
{ 
	class PHYSICS_HIDDEN_DECLARE BoundTreeSplitTrianglesImpl  
	{
	public:
		using ClassType = BoundTreeSplitTrianglesImpl;
		using AVector = Mathematics::AVectorF;
		using APoint = Mathematics::APointF;
		using Centroids = std::vector<APoint>;
		using Split = std::vector<int>;
		 
	public:
		BoundTreeSplitTrianglesImpl(const Centroids& centroids,int beginIndex, int endIndex,const Split& inSplit,const APoint& origin,const AVector& direction);

		CLASS_INVARIANT_DECLARE;
	
		int GetFirstOutSplitIndex() const noexcept;
                int GetSecondOutSplitIndex() const noexcept;
		const Split GetOutSplit() const;

	private:
		void SplitTriangles(const Centroids& centroids,int beginIndex, int endIndex,
							const Split& inSplit,const APoint& origin,const AVector& direction);
	 
	private:	
		int m_FirstOutSplitIndex;
		int m_SecondOutSplitIndex;
		Split m_OutSplit;
	};
}

#endif // PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_IMPL_H
