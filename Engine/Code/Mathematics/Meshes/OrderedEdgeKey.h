// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:15)

#ifndef MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H
#define MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE OrderedEdgeKey
	{
	public:
		typedef OrderedEdgeKey ClassType;

	public:
		OrderedEdgeKey (int first, int second);

		OrderedEdgeKey(const OrderedEdgeKey& rhs);
		OrderedEdgeKey& operator = (const OrderedEdgeKey& rhs);

		CLASS_INVARIANT_DECLARE;

		int GetKey(int index) const; 

	private:
		int m_Vertex[2];
	};

	bool MATHEMATICS_DEFAULT_DECLARE operator< (const OrderedEdgeKey& lhs,const OrderedEdgeKey& rhs);
}

#endif // MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H
