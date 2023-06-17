///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:50)

#ifndef RENDERING_DETAIL_CLOD_MESH_VERTEX_H
#define RENDERING_DETAIL_CLOD_MESH_VERTEX_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Meshes/EdgeKey.h"
#include "Mathematics/Meshes/TriangleKey.h"

#include <set>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ClodMeshVertex
    {
    public:
        using ClassType = ClodMeshVertex;
        using TriangleKey = Mathematics::TriangleKey;
        using EdgeKey = Mathematics::EdgeKey;
        // 顶点——边——三角形的图形。
        using TriangleKeySet = std::set<TriangleKey>;
        using EdgeKeySet = std::set<EdgeKey>;
        using TriangleKeySetConstIter = TriangleKeySet::const_iterator;
        using EdgeKeySetConstIter = EdgeKeySet::const_iterator;

    public:
        ClodMeshVertex() noexcept;

        CLASS_INVARIANT_DECLARE;

        void InsertTriangleKey(const TriangleKey& triangleKey);
        void InsertEdgeKey(const EdgeKey& edgeKey);
        void SetCollapsible(bool aCollapsible) noexcept;

        void EraseTriangleKey(const TriangleKey& triangleKey);
        void EraseEdgeKey(const EdgeKey& edgeKey);

        NODISCARD int GetTriangleKeySize() const;
        NODISCARD int GetEdgeKeySize() const;
        NODISCARD bool IsCollapsible() const noexcept;

        NODISCARD TriangleKeySetConstIter GetTriangleKeyBegin() const noexcept;
        NODISCARD TriangleKeySetConstIter GetTriangleKeyEnd() const noexcept;
        NODISCARD EdgeKeySetConstIter GetEdgeKeyBegin() const noexcept;
        NODISCARD EdgeKeySetConstIter GetEdgeKeyEnd() const noexcept;

    private:
        EdgeKeySet adjEdges;
        TriangleKeySet adjTriangles;
        bool collapsible;
    };
}

#endif  // RENDERING_DETAIL_CLOD_MESH_VERTEX_H
