///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/08 15:51)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_H

#include "Mathematics/MathematicsDll.h"

#include "Delaunay1.h"
#include "Delaunay2.h"
#include "Mathematics/Meshes/TSManifoldMesh.h"
#include "Mathematics/Query/Query3.h"

namespace Mathematics
{
    template <typename Real>
    class Delaunay3 : public Delaunay<Real>
    {
    public:
        using ClassType = Delaunay3<Real>;
        using ParentType = Delaunay<Real>;
        using Vector3 = Vector3<Real>;
        using Vertices = std::vector<Vector3>;
        using Delaunay1 = Delaunay1<Real>;
        using Delaunay2 = Delaunay2<Real>;
        using String = System::String;
        using IndicesType = ParentType::IndicesType;
        using HullType = std::pair<IndicesType, bool>;
        using VertexType = std::tuple<Vector3, Vector3, Vector3, Vector3, bool>;
        using IndexType = std::tuple<int32_t, int32_t, int32_t, int32_t, bool>;
        using BaryType = std::tuple<Real, Real, Real, Real, bool>;

    public:
        Delaunay3(const Vertices& vertices, Real epsilon, QueryType queryType);
        explicit Delaunay3(const String& filename);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vertices GetVertices() const;

        NODISCARD int GetNumUniqueVertices() const noexcept;

        NODISCARD Vector3 GetLineOrigin() const noexcept;
        NODISCARD Vector3 GetLineDirection() const noexcept;
        NODISCARD Delaunay1 GetDelaunay1() const;

        NODISCARD Vector3 GetPlaneOrigin() const noexcept;
        NODISCARD Vector3 GetPlaneDirection(int i) const;
        NODISCARD Delaunay2 GetDelaunay2() const;

        NODISCARD HullType GetHull() const;

        NODISCARD int GetContainingTetrahedron(const Vector3& p) const;

        NODISCARD int GetPathLast() const noexcept;
        NODISCARD IndicesType GetPath() const;

        NODISCARD int GetLastFace(int& v0, int& v1, int& v2, int& v3) const noexcept;

        NODISCARD VertexType GetVertexSet(int i) const;

        NODISCARD IndexType GetIndexSet(int i) const;

        NODISCARD IndexType GetAdjacentSet(int i) const;

        NODISCARD BaryType GetBarycentricSet(int i, const Vector3& p) const;

        void LoadFile(const String& filename);
        void SaveFile(const String& filename) const;

    private:
        using Tetrahedron = TSManifoldMesh::Tetrahedron;
        using TetrahedronSharedPtr = std::shared_ptr<Tetrahedron>;
        using Query3 = Query3<Real>;
        using Query3SharedPtr = std::shared_ptr<Query3>;

    private:
        NODISCARD bool GetContainingTetrahedron(int i, const Tetrahedron& tetra) const;

        void GetAndRemoveInsertionPolyhedron(int i, std::set<TetrahedronSharedPtr>& candidates, std::set<TriangleKey>& boundary);

        void Update(int i);
        void Init();

    private:
        Vertices vertices;

        int numUniqueVertices;

        Vertices sVertices;
        Query3SharedPtr query;
        Vector3 min;
        Real scale;

        TSManifoldMesh tetraMesh;

        Vector3 lineOrigin;
        Vector3 lineDirection;

        Vector3 planeOrigin;
        std::array<Vector3, 2> planeDirection;

        mutable int pathLast;
        mutable IndicesType path;

        mutable int lastFaceV0;
        mutable int lastFaceV1;
        mutable int lastFaceV2;
        mutable int lastFaceOpposite;
        mutable int lastFaceOppositeIndex;
    };

    using Delaunay3F = Delaunay3<float>;
    using Delaunay3D = Delaunay3<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_H
