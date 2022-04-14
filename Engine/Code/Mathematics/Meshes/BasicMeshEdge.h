///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/22 16:15)

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
