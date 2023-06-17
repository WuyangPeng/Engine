///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:16)

#ifndef MATHEMATICS_MESHES_BASIC_BESH_EDGE_H
#define MATHEMATICS_MESHES_BASIC_BESH_EDGE_H

#include "Mathematics/MathematicsDll.h"

#include <array>

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE BasicMeshEdge
    {
    public:
        using ClassType = BasicMeshEdge;

    public:
        BasicMeshEdge() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetVertex(int index) const;

        NODISCARD int GetTriangle(int index) const;

        void SetVertex(int index, int vertex);
        void SetTriangle(int index, int triangle0);

    private:
        std::array<int, 3> vertices;
        std::array<int, 3> triangle;
    };
}

#endif  // MATHEMATICS_MESHES_BASIC_BESH_EDGE_H
