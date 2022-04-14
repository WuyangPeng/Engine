///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/09 10:41)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_INCREMENTAL_DELAUNAY2_H_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_INCREMENTAL_DELAUNAY2_H_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/MinHeap.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Meshes/VEManifoldMesh.h"
#include "Mathematics/Rational/RationalVector2.h"

#include <set>

namespace Mathematics
{
    template <typename Real>
    class IncrementalDelaunay2
    {
    public:
        using ClassType = IncrementalDelaunay2<Real>;
        using IndicesType = std::vector<int32_t>;
        using HullType = std::pair<IndicesType, bool>;
        using Vector2 = Vector2<Real>;
        using Vertices = std::vector<Vector2>;

    public:
        IncrementalDelaunay2(Real xmin, Real ymin, Real xmax, Real ymax, Real uncertainty = Math<Real>::GetValue(0));

        CLASS_INVARIANT_DECLARE;

        int Insert(const Vector2& position);
        int Remove(const Vector2& position);

        NODISCARD HullType GetAllTriangles() const;

        void GenerateRepresentation();

        NODISCARD int GetNumTriangles() const noexcept;
        NODISCARD IndicesType GetIndices() const;
        NODISCARD IndicesType GetAdjacencies() const;

        NODISCARD Vertices GetVertices() const;

        NODISCARD std::map<Vector2, int> GetUniqueVertices() const;

        NODISCARD HullType GetHull() const;

        NODISCARD int GetContainingTriangle(const Vector2& p) const;

        NODISCARD int GetPathLast() const noexcept;
        NODISCARD IndicesType GetPath() const;

        NODISCARD int GetLastEdge(int& v0, int& v1, int& v2) const noexcept;

        NODISCARD std::array<Vector2, 3> GetVertexSet(int i) const;

        NODISCARD std::array<int32_t, 3> GetIndexSet(int i) const;

        NODISCARD std::array<int32_t, 3> GetAdjacentSet(int i) const;

        NODISCARD std::array<Real, 3> GetBarycentricSet(int i, const Vector2& p) const;

    private:
        using VertexMap = std::map<Vector2, int>;
        using QRational = SignRational<4 * sizeof(Real)>;
        using QRVector = RationalVector2<4 * sizeof(Real)>;

        class Triangle
        {
        public:
            using TriangleSharedPtr = std::shared_ptr<Triangle>;

        public:
            Triangle(int v0, int v1, int v2) noexcept;

            NODISCARD bool IsInsertionComponent(int posIndex,
                                                const Vector2& test,
                                                const TriangleSharedPtr& adj,
                                                const IncrementalDelaunay2& delaunay);

            NODISCARD int DetachFrom(int adjIndex, const TriangleSharedPtr& adj);

            std::array<int, 3> v;
            std::array<TriangleSharedPtr, 3> adjTriangle;
            int time;
            bool isComponent;
            bool onStack;
        };

        using TriangleSharedPtr = std::shared_ptr<Triangle>;

        class Edge : public VEManifoldMesh::Edge
        {
        public:
            using ClassType = Edge;
            using ParentType = VEManifoldMesh::Edge;

        public:
            Edge(int v0,
                 int v1,
                 int nullIndex,
                 const TriangleSharedPtr& tri) noexcept;

            NODISCARD static VEManifoldMesh::EdgeSharedPtr EdgeCreator(int v0, int v1);

            int nullIndex;
            TriangleSharedPtr tri;
        };

        using EdgeSharedPtr = std::shared_ptr<Edge>;

        class RPVertex
        {
        public:
            RPVertex(int index, const TriangleSharedPtr& tri, const TriangleSharedPtr& adj) noexcept;

            int index;

            TriangleSharedPtr tri;

            TriangleSharedPtr adj;

            bool isConvex;

            bool isEarTip;

            bool isSuperVertex;

            Real weight;

            int vPrev;
            int vNext;

            int sPrev;
            int sNext;

            int earRecord;
        };

        class Triangulate
        {
        public:
            Triangulate(std::vector<RPVertex>& polygon, int removal, IncrementalDelaunay2* delaunay);

        private:
            NODISCARD RPVertex& Get(int i);
            NODISCARD bool IsConvex(int i);
            NODISCARD bool IsEarTip(int i);
            void InsertAfterC(int i);
            void InsertAfterR(int i);
            void RemoveV(int i);
            void RemoveR(int i);
            NODISCARD Real ComputeWeight(int v0, int p);

        private:
            std::vector<RPVertex>& polygon;
            int numVertices;
            IncrementalDelaunay2* delaunay;
            int cFirst;
            int cLast;
            int rFirst;
            int rLast;
            CoreTools::MinHeap<int, Real> eHeap;
        };

        NODISCARD int ToLine(const Vector2& test, int v0, int v1) const;

        NODISCARD int ToTriangle(const Vector2& test, int v0, int v1, int v2) const;

        NODISCARD int ToCircumcircle(const Vector2& test, int v0, int v1, int v2) const;

        NODISCARD TriangleSharedPtr GetContainingTriangleInternal(const Vector2& position) const;

        NODISCARD bool ContainsSupervertex(const Triangle& tri) const;

        void SwapEdge(const TriangleSharedPtr& tri0, const TriangleSharedPtr& tri1);

    private:
        Real xMin;
        Real xMax;
        Real yMin;
        Real yMax;

        VertexMap vMap;
        std::vector<Vector2> vertexPool;

        Real uncertainty;

        mutable std::shared_ptr<std::vector<QRVector>> ratVertexPool;
        mutable std::shared_ptr<std::vector<bool>> ratVertexEvaluated;

        std::set<TriangleSharedPtr> triangle;

        int numTriangles;
        IndicesType indices;
        IndicesType adjacencies;

        mutable int pathLast;
        mutable IndicesType path;

        mutable int lastEdgeV0;
        mutable int lastEdgeV1;
        mutable int lastEdgeOpposite;
        mutable int lastEdgeOppositeIndex;
    };

    using IncrementalDelaunay2F = IncrementalDelaunay2<float>;
    using IncrementalDelaunay2D = IncrementalDelaunay2<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_INCREMENTAL_DELAUNAY2_H_H
