///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:50)

#ifndef RENDERING_DETAIL_CLOD_MESH_EDGE_H
#define RENDERING_DETAIL_CLOD_MESH_EDGE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Meshes/TriangleKey.h"

#include <set>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ClodMeshEdge
    {
    public:
        using ClassType = ClodMeshEdge;
        using TriangleKey = Mathematics::TriangleKey;
        using TriangleKeySet = std::set<TriangleKey>;
        using TriangleKeySetConstIter = TriangleKeySet::const_iterator;

    public:
        ClodMeshEdge() noexcept;

        CLASS_INVARIANT_DECLARE;

        void InsertTriangleKey(const TriangleKey& triangleKey);
        void EraseTriangleKey(const TriangleKey& triangleKey);

        NODISCARD int GetTriangleKeySize() const;

        NODISCARD TriangleKeySetConstIter GetTriangleKeyBegin() const noexcept;
        NODISCARD TriangleKeySetConstIter GetTriangleKeyEnd() const noexcept;

        NODISCARD int GetMinHeapRecordIndex() const noexcept;
        void SetMinHeapRecordIndex(int index) noexcept;

        NODISCARD TriangleKey GetBeginTriangleKey() const;
        NODISCARD TriangleKey GetEndTriangleKey() const;

    private:
        TriangleKeySet adjTriangles;
        int minHeapRecordIndex;
    };
}

#endif  // RENDERING_DETAIL_CLOD_MESH_EDGE_H
