// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:15)

#ifndef MATHEMATICS_MESHES_TRIANGLE_KEY_H
#define MATHEMATICS_MESHES_TRIANGLE_KEY_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE TriangleKey
    {
    public:
        using ClassType = TriangleKey;
        
    public:
		TriangleKey();
        TriangleKey (int first, int second, int third);
        
        TriangleKey(const TriangleKey& rhs);
        TriangleKey& operator = (const TriangleKey& rhs);
    
		CLASS_INVARIANT_DECLARE;
        
        int GetKey(int index) const;
		int GetKeyIndex(int key) const;
		void SetKey(int index, int value);

		void Swap(int lhsIndex,int rhsIndex);
        
    private:
		const static int sm_VertexSize = 3;

        int m_Vertex[3];
    };
    
     bool MATHEMATICS_DEFAULT_DECLARE operator< (const TriangleKey& lhs,  const TriangleKey& rhs);
}

#endif // MATHEMATICS_MESHES_TRIANGLE_KEY_H
