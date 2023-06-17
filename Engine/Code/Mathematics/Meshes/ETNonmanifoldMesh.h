///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:16)

#ifndef MATHEMATICS_MESHES_ET_NONMANIFOLD_MESH_H
#define MATHEMATICS_MESHES_ET_NONMANIFOLD_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "EdgeKey.h"
#include "TriangleKey.h"

#include <map>
#include <set>

namespace Mathematics
{
    class ETNonmanifoldMesh
    {
    public:
        using ClassType = ETNonmanifoldMesh;

        class Edge;
        using EdgeSharedPtr = std::shared_ptr<Edge>;
        using ConstEdgeSharedPtr = std::shared_ptr<const Edge>;
        using EdgeCreator = EdgeSharedPtr (*)(int, int);
        using EdgeMap = std::map<EdgeKey, EdgeSharedPtr>;

        class Triangle;
        using TriangleSharedPtr = std::shared_ptr<Triangle>;
        using ConstTriangleSharedPtr = std::shared_ptr<const Triangle>;
        using TriangleCreator = TriangleSharedPtr (*)(int, int, int);
        using TriangleMap = std::map<TriangleKey, TriangleSharedPtr>;

        class Edge
        {
        public:
            Edge(int v0, int v1) noexcept;
            virtual ~Edge() noexcept = default;
            Edge(const Edge& rhs) = default;
            Edge& operator=(const Edge& rhs) = default;
            Edge(Edge&& rhs) noexcept = default;
            Edge& operator=(Edge&& rhs) noexcept = default;

            std::array<int, 2> v;
            std::set<TriangleSharedPtr> t;
        };

        class Triangle
        {
        public:
            Triangle(int v0, int v1, int v2) noexcept;
            virtual ~Triangle() noexcept = default;
            Triangle(const Triangle& rhs) = default;
            Triangle& operator=(const Triangle& rhs) = default;
            Triangle(Triangle&& rhs) noexcept = default;
            Triangle& operator=(Triangle&& rhs) noexcept = default;

            std::array<int, 3> v;

            std::array<EdgeSharedPtr, 3> e;
        };

        explicit ETNonmanifoldMesh(EdgeCreator eCreator = nullptr, TriangleCreator tCreator = nullptr) noexcept;
        virtual ~ETNonmanifoldMesh() noexcept = default;
        ETNonmanifoldMesh(const ETNonmanifoldMesh& rhs) = default;
        ETNonmanifoldMesh& operator=(const ETNonmanifoldMesh& rhs) = default;
        ETNonmanifoldMesh(ETNonmanifoldMesh&& rhs) noexcept = default;
        ETNonmanifoldMesh& operator=(ETNonmanifoldMesh&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumEdges() const noexcept;
        NODISCARD const EdgeMap& GetEdges() const noexcept;
        NODISCARD int GetNumTriangles() const noexcept;
        NODISCARD const TriangleMap& GetTriangles() const noexcept;

        TriangleSharedPtr InsertTriangle(int v0, int v1, int v2);
        bool RemoveTriangle(int v0, int v1, int v2);

        NODISCARD bool IsManifold() const noexcept;
        NODISCARD bool IsClosed() const noexcept;
        NODISCARD bool IsConnected() const;

        NODISCARD std::vector<int> RemoveComponent();

        void Print(const std::string& filename);

    protected:
        NODISCARD static EdgeSharedPtr CreateEdge(int v0, int v1);
        NODISCARD static TriangleSharedPtr CreateTriangle(int v0, int v1, int v2);

    private:
        EdgeCreator edgeCreator;
        EdgeMap edgeMap;
        TriangleCreator triangleCreator;
        TriangleMap triangleMap;
    };
}

#endif  // MATHEMATICS_MESHES_ET_NONMANIFOLD_MESH_H
