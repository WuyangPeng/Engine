///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:35)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Intersection/Flags/VertexProjectionMap.h"

#include <array>
#include <memory>

namespace Mathematics
{
    template <typename Real>
    class IntersectorConfiguration final
    {
    public:
        using ClassType = IntersectorConfiguration<Real>;

    public:
        IntersectorConfiguration() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VertexProjectionMap GetMap() const noexcept;
        NODISCARD Real GetMin() const noexcept;
        NODISCARD Real GetMax() const noexcept;
        NODISCARD int GetIndex(int index) const;

        void SetMap(VertexProjectionMap newVertexProjectionMap) noexcept;
        void SetMin(Real newMin) noexcept;
        void SetMax(Real newMax) noexcept;
        void SetIndex(int index, int value);

    private:
        using IndexType = std::array<int, 8>;

    private:
        // 配置的“顶点投影图”值。
        VertexProjectionMap vertexProjectionMap;

        // 顶点的顺序。
        IndexType indexType;

        // 投影间隔。
        Real min;

        Real max;
    };
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H
