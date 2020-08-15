// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:15)

#ifndef MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H
#define MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H

#include "Mathematics/MathematicsDll.h"
 #include "System/Helper/PragmaWarning.h"
    #include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE OrderedEdgeKey
	{
	public:
		typedef OrderedEdgeKey ClassType;

	public:
		OrderedEdgeKey (int first, int second) noexcept;

		OrderedEdgeKey(const OrderedEdgeKey& rhs) noexcept;
		OrderedEdgeKey& operator = (const OrderedEdgeKey& rhs) noexcept;
		
		~OrderedEdgeKey() = default;
		OrderedEdgeKey(OrderedEdgeKey&& rhs) noexcept= default;
		OrderedEdgeKey& operator = (OrderedEdgeKey&& rhs) noexcept= default;

		CLASS_INVARIANT_DECLARE;

		int GetKey(int index) const; 

	private:
		int m_Vertex[2];
	};

	bool MATHEMATICS_DEFAULT_DECLARE operator< (const OrderedEdgeKey& lhs,const OrderedEdgeKey& rhs);
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H
