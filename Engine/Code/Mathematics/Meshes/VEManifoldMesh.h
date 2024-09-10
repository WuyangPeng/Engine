///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:17)

#ifndef MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H
#define MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H

#include "Mathematics/MathematicsDll.h"

#include <array>
#include <map>
#include <memory>
#include <string>

namespace Mathematics
{
    class VEManifoldMesh
    {
    public:
        using ClassType = VEManifoldMesh;

    public:
        class Vertex;
        using VertexSharedPtr = std::shared_ptr<Vertex>;
        using ConstVertexSharedPtr = std::shared_ptr<const Vertex>;
        using VertexCreator = VertexSharedPtr (*)(int);
        using VertexMap = std::map<int, VertexSharedPtr>;

        class Edge;
        using EdgeSharedPtr = std::shared_ptr<Edge>;
        using ConstEdgeSharedPtr = std::shared_ptr<const Edge>;
        using EdgeCreator = EdgeSharedPtr (*)(int, int);
        using EdgeMap = std::map<std::pair<int, int>, EdgeSharedPtr>;

        class Vertex
        {
        public:
            explicit Vertex(int v);
            virtual ~Vertex() noexcept = default;
            Vertex(const Vertex& rhs) = default;
            Vertex& operator=(const Vertex& rhs) = default;
            Vertex(Vertex&& rhs) noexcept = default;
            Vertex& operator=(Vertex&& rhs) noexcept = default;

            int v;
            std::array<EdgeSharedPtr, 2> e;
        };

        class Edge
        {
        public:
            Edge(int v0, int v1);
            virtual ~Edge() noexcept = default;
            Edge(const Edge& rhs) = default;
            Edge& operator=(const Edge& rhs) = default;
            Edge(Edge&& rhs) noexcept = default;
            Edge& operator=(Edge&& rhs) noexcept = default;

            std::array<int, 2> v;

            std::array<EdgeSharedPtr, 2> e;
        };

        VEManifoldMesh(VertexCreator vCreator = nullptr, EdgeCreator eCreator = nullptr) noexcept;
        virtual ~VEManifoldMesh() noexcept = default;
        VEManifoldMesh(const VEManifoldMesh& rhs) = default;
        VEManifoldMesh& operator=(const VEManifoldMesh& rhs) = default;
        VEManifoldMesh(VEManifoldMesh&& rhs) = default;
        VEManifoldMesh& operator=(VEManifoldMesh&& rhs) = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD const VertexMap& GetVertices() const noexcept;
        NODISCARD const EdgeMap& GetEdges() const noexcept;

        EdgeSharedPtr InsertEdge(int v0, int v1);
        bool RemoveEdge(int v0, int v1);

        NODISCARD bool IsClosed() const noexcept;

        NODISCARD void Print(const std::string& filename);

    protected:
        NODISCARD static VertexSharedPtr CreateVertex(int v0);
        NODISCARD static EdgeSharedPtr CreateEdge(int v0, int v1);

    private:
        VertexCreator vertexCreator;
        VertexMap vertexMap;

        EdgeCreator edgeCreator;
        EdgeMap edgeMap;
    };
}

#endif  // MATHEMATICS_MESHES_VE_MANIFOLD_MESH_H
