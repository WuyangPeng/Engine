// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:12)

#ifndef MATHEMATICS_MESHES_BASIC_BESH_EDGE_H
#define MATHEMATICS_MESHES_BASIC_BESH_EDGE_H

#include "System/Helper/PragmaWarning.h"
#include "Mathematics/MathematicsDll.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BasicMeshEdge
    {
    public:
        using ClassType = BasicMeshEdge;

    public:
        BasicMeshEdge() noexcept;

        BasicMeshEdge(const BasicMeshEdge& rhs) noexcept;
        BasicMeshEdge& operator=(const BasicMeshEdge& rhs) noexcept;

        ~BasicMeshEdge() noexcept = default;
        BasicMeshEdge(BasicMeshEdge&& rhs) = default;
        BasicMeshEdge& operator=(BasicMeshEdge&& rhs) = default;

        CLASS_INVARIANT_DECLARE;

        int GetVertex(int index) const;

        int GetTriangle(int index) const;

        void SetVertex(int index, int vertex);
        void SetTriangle(int index, int triangle0);

    private:
        int m_Vertex[2];
        int triangle[2];
    };
}
#include STSTEM_WARNING_POP
#endif  // MATHEMATICS_MESHES_BASIC_BESH_EDGE_H
