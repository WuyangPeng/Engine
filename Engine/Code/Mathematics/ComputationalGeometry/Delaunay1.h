///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:36)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_H

#include "Mathematics/MathematicsDll.h"

#include "Delaunay.h"

namespace Mathematics
{
    template <typename Real>
    class Delaunay1 : public Delaunay<Real>
    {
    public:
        using ClassType = Delaunay1<Real>;
        using ParentType = Delaunay<Real>;
        using Vertices = std::vector<Real>;
        using String = System::String;
        using HullType = std::tuple<int32_t, int32_t, bool>;
        using VertexType = std::tuple<Real, Real, bool>;
        using IndicesType = ParentType::IndicesType;

    public:
        Delaunay1(const Vertices& vertices, Real epsilon, QueryType queryType);
        explicit Delaunay1(const String& filename);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vertices GetVertices() const;

        NODISCARD HullType GetHull() const;
        NODISCARD int GetContainingSegment(const Real p) const;

        NODISCARD VertexType GetVertexSet(int i) const;

        NODISCARD HullType GetIndexSet(int i) const;

        NODISCARD HullType GetAdjacentSet(int i) const;

        NODISCARD VertexType GetBarycentricSet(int i, const Real p) const;

        void LoadFile(const String& filename);
        void SaveFile(const String& filename) const;

    private:
        class SortedVertex
        {
        public:
            Real value;
            int index;

            NODISCARD bool operator<(const SortedVertex& vertex) const noexcept
            {
                return value < vertex.value;
            }
        };

        void Init();

    private:
        Vertices vertices;
    };

    using Delaunay1F = Delaunay1<float>;
    using Delaunay1D = Delaunay1<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_H
