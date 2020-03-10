// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 11:14)

#ifndef MATHEMATICS_MESHES_EDGE_KEY_H
#define MATHEMATICS_MESHES_EDGE_KEY_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <iosfwd>

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE EdgeKey
    {
    public:
        typedef EdgeKey ClassType;
        
    public:
        EdgeKey (int first, int second);
		EdgeKey();
        
        EdgeKey(const EdgeKey& rhs);
        EdgeKey& operator = (const EdgeKey& rhs);
        
		CLASS_INVARIANT_DECLARE;
        
        int GetKey(int index) const;
		void SetKey(int index,int value);
        
    private:
        int m_Vertex[2];
    };
    
    bool MATHEMATICS_DEFAULT_DECLARE operator< (const EdgeKey& lhs,  const EdgeKey& rhs);
    
	MATHEMATICS_DEFAULT_DECLARE System::OStream& operator<<(System::OStream& os, const EdgeKey& edgeKey);
}

#endif // MATHEMATICS_MESHES_EDGE_KEY_H