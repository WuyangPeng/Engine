// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 11:16)

#ifndef MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H
#define MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE UnorderedTriangleKey
    {
    public:
        using ClassType = UnorderedTriangleKey;
        
    public:
        UnorderedTriangleKey (int first, int second,int third);
        
        UnorderedTriangleKey(const UnorderedTriangleKey& rhs);
        UnorderedTriangleKey& operator =
        (const UnorderedTriangleKey& rhs);
        
        CLASS_INVARIANT_DECLARE;
        
        int GetKey(int index) const;
        
    private:
        int m_Vertex[3];
    };
    
    bool MATHEMATICS_DEFAULT_DECLARE operator < (const UnorderedTriangleKey& lhs,  const UnorderedTriangleKey& rhs);
    
}

#endif // MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H



