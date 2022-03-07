// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:16)

#ifndef MATHEMATICS_MESHES_BASIC_BESH_VERTEX_IMPL_H
#define MATHEMATICS_MESHES_BASIC_BESH_VERTEX_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE BasicMeshVertexImpl
    {
    public:
        using ClassType = BasicMeshVertexImpl;
        
    public:
        BasicMeshVertexImpl(MAYBE_UNUSED int count) noexcept;
        
        CLASS_INVARIANT_DECLARE;
        
        int GetVertex(int index) const;
        int GetEdge(int index) const;
        int GetTriangle(int index) const;    
        
        void InsertEdge (int vertex, int edge);
        void InsertTriangle (int triangle0);
        
    private:        
        std::vector<int> m_Vertex;
        std::vector<int> m_Edge;
        std::vector<int> triangle;
    };
}

#endif // MATHEMATICS_MESHES_BASIC_BESH_VERTEX_IMPL_H

