// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:12)

#ifndef MATHEMATICS_MESHES_BASIC_BESH_EDGE_H
#define MATHEMATICS_MESHES_BASIC_BESH_EDGE_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BasicMeshEdge
    {
    public:
        using ClassType = BasicMeshEdge;
        
    public:
        BasicMeshEdge ();
        
        BasicMeshEdge (const BasicMeshEdge& rhs);
        BasicMeshEdge& operator = (const BasicMeshEdge& rhs);

        CLASS_INVARIANT_DECLARE;
        
        int GetVertex(int index) const;
       
        int GetTriangle(int index) const;
        
        void SetVertex(int index,int vertex);
        void SetTriangle(int index,int triangle);
        
    private:
        int m_Vertex[2];
        int m_Triangle[2];
    };
}

#endif // MATHEMATICS_MESHES_BASIC_BESH_EDGE_H

