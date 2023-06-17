///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:17)

#ifndef MATHEMATICS_MESHES_PLANAR_GRAPH_H
#define MATHEMATICS_MESHES_PLANAR_GRAPH_H

#include "Mathematics/MathematicsDll.h"

#include "EdgeKey.h"

#include <map>
#include <set>

namespace Mathematics
{
    template <typename Point2>
    class PlanarGraph
    {
    public:
        using ClassType = PlanarGraph<Point2>;

    public:
        PlanarGraph() noexcept;
        virtual ~PlanarGraph() noexcept = default;
        PlanarGraph(const PlanarGraph& rhs) = default;
        PlanarGraph& operator=(const PlanarGraph& rhs) = default;
        PlanarGraph(PlanarGraph&& rhs) noexcept = default;
        PlanarGraph& operator=(PlanarGraph&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        class Vertex
        {
        public:
            Vertex(const Point2& position, int index) noexcept;

            void Insert(const std::shared_ptr<Vertex>& adjacentVertex);
            void Remove(const std::shared_ptr<Vertex>& adjacentVertex);

            Point2 position;

            int index;

            std::vector<std::weak_ptr<Vertex>> adjacent;
        };

        using Vertices = std::map<int, std::shared_ptr<Vertex>>;
        using Edges = std::map<EdgeKey, bool>;

        NODISCARD const Vertices& GetVertices() const noexcept;
        NODISCARD std::shared_ptr<Vertex> GetVertex(int iIndex) const;
        bool InsertVertex(const Point2& position, int iIndex);
        bool RemoveVertex(int iIndex);

        NODISCARD const Edges& GetEdges() const noexcept;
        bool InsertEdge(int iIndex0, int iIndex1);
        bool RemoveEdge(int iIndex0, int iIndex1);

        enum class PrimitiveType
        {
            IsolatedVertex,
            Filament,
            MinimalCycle
        };

        class Primitive
        {
        public:
            explicit Primitive(PrimitiveType type) noexcept;

            PrimitiveType primitiveType;
            std::vector<std::pair<Point2, int>> sequence;
        };

        NODISCARD std::vector<std::shared_ptr<Primitive>> ExtractPrimitives();

    protected:
        class VertexPtr
        {
        public:
            explicit VertexPtr(const std::shared_ptr<Vertex>& vertex) noexcept;

            NODISCARD std::shared_ptr<Vertex> Get() noexcept;

            NODISCARD bool operator<(const VertexPtr& vertexPtr) const;

        private:
            std::shared_ptr<Vertex> vertex;
        };

        void SetCycleEdge(int index0, int index1, bool cycleEdge);
        NODISCARD bool GetCycleEdge(int index0, int index1) const;

        void ExtractIsolatedVertex(const std::shared_ptr<Vertex>& v0, std::set<VertexPtr>& heap, std::vector<std::shared_ptr<Primitive>>& primitives);

        void ExtractFilament(std::shared_ptr<Vertex> v0, std::shared_ptr<Vertex> v1, std::set<VertexPtr>& heap, std::vector<std::shared_ptr<Primitive>>& primitives);

        void ExtractPrimitive(std::shared_ptr<Vertex> v0, std::set<VertexPtr>& heap, std::vector<std::shared_ptr<Primitive>>& primitives);

        NODISCARD std::shared_ptr<Vertex> GetClockwiseMost(const std::shared_ptr<Vertex>& vPrev, const std::shared_ptr<Vertex>& vCurr);
        NODISCARD std::shared_ptr<Vertex> GetCounterclockwiseMost(const std::shared_ptr<Vertex>& vPrev, const std::shared_ptr<Vertex>& vCurr);

    private:
        Vertices vertices;
        Edges edges;
    };
}

#endif  // MATHEMATICS_MESHES_PLANAR_GRAPH_H
