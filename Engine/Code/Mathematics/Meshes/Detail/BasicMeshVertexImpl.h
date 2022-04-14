///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/22 16:24)

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
