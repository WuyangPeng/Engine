///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/22 14:53)

#ifndef MATHEMATICS_MESHES_BASIC_MESH_H
#define MATHEMATICS_MESHES_BASIC_MESH_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    class BasicMesh
    {
    public:
        using ClassType = BasicMesh;

    public:
        BasicMesh(int numVertices, int numTriangles, const std::vector<int>& indices);

        virtual ~BasicMesh() noexcept = default;
        BasicMesh(const BasicMesh& rhs) = default;
        BasicMesh& operator=(const BasicMesh& rhs) = default;
        BasicMesh(BasicMesh&& rhs) noexcept = default;
        BasicMesh& operator=(BasicMesh&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD bool IsBasicMeshValid() const noexcept;

        class Vertex
        {
        public:
            Vertex() noexcept;

            void InsertEdge(int v0, int e0);
            void InsertTriangle(int t0);

            int numVertices;
            std::vector<int> v;
            std::vector<int> e;
            int numTriangles;
            std::vector<int> t;
        };

        class Edge
        {
        public:
            Edge() noexcept;

            std::array<int, 2> v;
            std::array<int, 2> t;
        };

        class Triangle
        {
        public:
            Triangle() noexcept;

            std::array<int, 3> v;
            std::array<int, 3> e;
            std::array<int, 3> t;
        };

        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetNumEdges() const noexcept;
        NODISCARD int GetNumTriangles() const noexcept;

        NODISCARD std::vector<int> GetIndices() const;
        NODISCARD std::vector<Vertex> GetVertices() const;
        NODISCARD std::vector<Edge> GetEdges() const;
        NODISCARD std::vector<Triangle> GetTriangles() const;

    private:
        int numVertices;
        int numEdges;
        int numTriangles;

        std::vector<int> indices;
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        std::vector<Triangle> triangles;
        bool isValid;
    };
}

#endif  // MATHEMATICS_MESHES_BASIC_MESH_H
