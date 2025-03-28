///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:36)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Delaunay.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/ComputationalGeometry/ComputationalGeometryFwd.h"
#include "Mathematics/Meshes/ETManifoldMesh.h"
#include "Mathematics/Meshes/OrderedEdgeKey.h"
#include "Mathematics/Query/Query2.h"

#include <set>

namespace Mathematics
{
    template <typename Real>
    class Delaunay2 : public Delaunay<Real>
    {
    public:
        using ClassType = Delaunay2<Real>;
        using ParentType = Delaunay<Real>;
        using Vector2Type = Vector2<Real>;
        using Vertices = std::vector<Vector2Type>;
        using String = System::String;
        using IndicesType = ParentType::IndicesType;
        using Delaunay1Type = Delaunay1<Real>;
        using HullType = std::pair<IndicesType, bool>;
        using VertexType = std::tuple<Vector2Type, Vector2Type, Vector2Type, bool>;
        using IndexType = std::tuple<int32_t, int32_t, int32_t, bool>;
        using BaryType = std::tuple<Real, Real, Real, bool>;

    public:
        Delaunay2(const Vertices& vertices, Real epsilon, QueryType queryType);
        explicit Delaunay2(const String& filename);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vertices GetVertices() const;
        NODISCARD int GetNumUniqueVertices() const noexcept;

        NODISCARD Vector2Type GetLineOrigin() const noexcept;
        NODISCARD Vector2Type GetLineDirection() const noexcept;
        NODISCARD Delaunay1Type GetDelaunay1() const;

        NODISCARD HullType GetHull() const;

        NODISCARD int GetContainingTriangle(const Vector2Type& p) const;

        NODISCARD int GetPathLast() const noexcept;
        NODISCARD IndicesType GetPath() const;

        NODISCARD int GetLastEdge(int& v0, int& v1, int& v2) const noexcept;

        NODISCARD VertexType GetVertexSet(int i) const;

        NODISCARD IndexType GetIndexSet(int i) const;

        NODISCARD IndexType GetAdjacentSet(int i) const;

        NODISCARD BaryType GetBarycentricSet(int i, const Vector2Type& p) const;

        void LoadFile(const String& filename);
        void SaveFile(const String& filename) const;

    private:
        using Triangle = ETManifoldMesh::Triangle;
        using TriangleSharedPtr = std::shared_ptr<Triangle>;
        using Query2 = Query2<Real>;
        using Query2SharedPtr = std::shared_ptr<Query2>;

        NODISCARD bool GetContainingTriangle(int i, const Triangle& tri) const;

        void GetAndRemoveInsertionPolygon(int i, std::set<TriangleSharedPtr>& candidates, std::set<OrderedEdgeKey>& boundary);

        void Update(int i);
        void Init();

    private:
        Vertices vertices;

        int numUniqueVertices;

        Vertices sVertices;
        Query2SharedPtr query;
        Vector2Type min;
        Real scale;

        ETManifoldMesh triMesh;

        Vector2Type lineOrigin;
        Vector2Type lineDirection;

        mutable int pathLast;
        mutable IndicesType path;

        mutable int lastEdgeV0;
        mutable int lastEdgeV1;
        mutable int lastEdgeOpposite;
        mutable int lastEdgeOppositeIndex;

        static const std::array<std::array<int32_t, 2>, 3> index;
    };

    using Delaunay2F = Delaunay2<float>;
    using Delaunay2D = Delaunay2<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_H
