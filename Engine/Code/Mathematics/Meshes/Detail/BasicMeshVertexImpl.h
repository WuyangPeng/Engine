///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:16)

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
        BasicMeshVertexImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetVertex(int index) const;
        NODISCARD int GetEdge(int index) const;
        NODISCARD int GetTriangle(int index) const;

        void InsertEdge(int vertex, int edge);
        void InsertTriangle(int triangle);

    private:
        std::vector<int> vertices;
        std::vector<int> edges;
        std::vector<int> triangles;
    };
}

#endif  // MATHEMATICS_MESHES_BASIC_BESH_VERTEX_IMPL_H
