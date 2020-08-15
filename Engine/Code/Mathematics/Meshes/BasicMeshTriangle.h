// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:12)

#ifndef MATHEMATICS_MESHES_BASIC_BESH_TRIANGLE_H
#define MATHEMATICS_MESHES_BASIC_BESH_TRIANGLE_H

#include "Mathematics/MathematicsDll.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BasicMeshTriangle
    {
    public:
        using ClassType = BasicMeshTriangle;
        
    public:
        BasicMeshTriangle () noexcept;
        
        BasicMeshTriangle (const BasicMeshTriangle& rhs) noexcept;
        BasicMeshTriangle& operator =(const BasicMeshTriangle& rhs) noexcept;
        ~BasicMeshTriangle() noexcept = default;
		 BasicMeshTriangle (BasicMeshTriangle&& rhs) = default;
        BasicMeshTriangle& operator = (BasicMeshTriangle&& rhs)= default;
		
        CLASS_INVARIANT_DECLARE;
        
        int GetVertex(int index) const;
        int GetEdge(int index) const;
        int GetTriangle(int index) const;
        
        void SetVertex(int index,int vertex);
        void SetEdge(int index,int edge);
        void SetTriangle(int index,int triangle);
        
    private:
        int m_Vertex[3];
        int m_Edge[3];
        int m_Triangle[3];
    };
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_MESHES_BASIC_BESH_TRIANGLE_H

