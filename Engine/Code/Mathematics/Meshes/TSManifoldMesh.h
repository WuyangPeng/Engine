///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:17)

#ifndef MATHEMATICS_MESHES_TS_MANIFOLD_MESH_H
#define MATHEMATICS_MESHES_TS_MANIFOLD_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "TetrahedronKey.h"
#include "TriangleKey.h"
#include "UnorderedTriangleKey.h"

#include <array>
#include <map>
#include <memory>
#include <string>

namespace Mathematics
{
    class TSManifoldMesh
    {
    public:
        using ClassType = TSManifoldMesh;

    public:
        class Triangle;
        using TriangleSharedPtr = std::shared_ptr<Triangle>;
        using TriangleCreator = TriangleSharedPtr (*)(int, int, int);
        using TriangleMap = std::map<UnorderedTriangleKey, TriangleSharedPtr>;

        class Tetrahedron;
        using TetrahedronSharedPtr = std::shared_ptr<Tetrahedron>;
        using TetrahedronCreator = TetrahedronSharedPtr (*)(int, int, int, int);
        using TetrahedronMap = std::map<TetrahedronKey, TetrahedronSharedPtr>;

        class Triangle
        {
        public:
            virtual ~Triangle() noexcept = default;
            Triangle(int v0, int v1, int v2);
            Triangle(const Triangle& rhs) = default;
            Triangle& operator=(const Triangle& rhs) = default;
            Triangle(Triangle&& rhs) noexcept = default;
            Triangle& operator=(Triangle&& rhs) noexcept = default;

            std::array<int, 3> v;

            std::array<TetrahedronSharedPtr, 2> t;
        };

        class Tetrahedron
        {
        public:
            virtual ~Tetrahedron() noexcept = default;
            Tetrahedron(int v0, int v1, int v2, int v3);
            Tetrahedron(const Tetrahedron& rhs) = default;
            Tetrahedron& operator=(const Tetrahedron& rhs) = default;
            Tetrahedron(Tetrahedron&& rhs) noexcept = default;
            Tetrahedron& operator=(Tetrahedron&& rhs) noexcept = default;

            std::array<int, 4> v;

            std::array<TriangleSharedPtr, 4> t;

            using TetrahedronSharedPtr = std::shared_ptr<Tetrahedron>;

            std::array<TetrahedronSharedPtr, 4> s;
        };

        virtual ~TSManifoldMesh() noexcept = default;
        TSManifoldMesh(TriangleCreator tCreator = nullptr, TetrahedronCreator sCreator = nullptr) noexcept;

        TSManifoldMesh(const TSManifoldMesh& rhs) = default;
        TSManifoldMesh& operator=(const TSManifoldMesh& rhs) = default;
        TSManifoldMesh(TSManifoldMesh&& rhs) noexcept = default;
        TSManifoldMesh& operator=(TSManifoldMesh&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD const TriangleMap& GetTriangles() const noexcept;
        NODISCARD const TetrahedronMap& GetTetrahedra() const noexcept;

        TetrahedronSharedPtr Insert(int v0, int v1, int v2, int v3);

        bool Remove(int v0, int v1, int v2, int v3);

        NODISCARD bool IsClosed() const noexcept;

        NODISCARD bool Print(const std::string& filename);

    protected:
        NODISCARD static TriangleSharedPtr CreateTriangle(int v0, int v1, int v2);
        NODISCARD static TetrahedronSharedPtr CreateTetrahedron(int v0, int v1, int v2, int v3);

    private:
        TriangleCreator triangleCreator;
        TriangleMap triangleMap;
        TetrahedronCreator tetrahedronCreator;
        TetrahedronMap tetrahedronMap;
    };
}

#endif  // MATHEMATICS_MESHES_TS_MANIFOLD_MESH_H
