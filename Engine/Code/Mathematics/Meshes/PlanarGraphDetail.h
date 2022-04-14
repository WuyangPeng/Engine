///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/23 13:26)

#ifndef MATHEMATICS_MESHES_PLANAR_GRAPH_DETAIL_H
#define MATHEMATICS_MESHES_PLANAR_GRAPH_DETAIL_H

#include "PlanarGraph.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"

template <typename Point2>
Mathematics::PlanarGraph<Point2>::PlanarGraph() noexcept
    : vertices{}, edges{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PlanarGraph<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Point2>
const typename Mathematics::PlanarGraph<Point2>::Vertices& Mathematics::PlanarGraph<Point2>::GetVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices;
}

template <typename Point2>
std::shared_ptr<typename Mathematics::PlanarGraph<Point2>::Vertex> Mathematics::PlanarGraph<Point2>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto iter = vertices.find(index);

    return (iter != vertices.end() ? iter->second : 0);
}

template <typename Point2>
bool Mathematics::PlanarGraph<Point2>::InsertVertex(const Point2& position, int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto iter = vertices.find(index);
    if (iter != vertices.end())
    {
        return false;
    }

    auto vertex = std::make_shared<Vertex>(position, index);
    vertices[index] = vertex;

    return true;
}

template <typename Point2>
bool Mathematics::PlanarGraph<Point2>::RemoveVertex(int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto iter = vertices.find(index);
    if (iter != vertices.end())
    {
        auto vertex = iter->second;
        if (vertex->adjacent.size() == 0)
        {
            vertices.erase(iter);

            return true;
        }
    }

    return false;
}

template <typename Point2>
const typename Mathematics::PlanarGraph<Point2>::Edges& Mathematics::PlanarGraph<Point2>::GetEdges() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return edges;
}

template <typename Point2>
bool Mathematics::PlanarGraph<Point2>::InsertEdge(int index0, int index1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto vertex0 = GetVertex(index0);
    if (!vertex0)
    {
        return false;
    }

    auto vertex1 = GetVertex(index1);
    if (!vertex1)
    {
        return false;
    }

    const EdgeKey eKey{ index0, index1 };
    const auto iter = edges.find(eKey);
    if (iter == edges.end())
    {
        edges[eKey] = false;

        vertex0->Insert(vertex1);
        vertex1->Insert(vertex0);
        return true;
    }

    return false;
}

template <typename Point2>
bool Mathematics::PlanarGraph<Point2>::RemoveEdge(int index0, int index1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto vertex0 = GetVertex(index0);
    if (!vertex0)
    {
        return false;
    }

    auto vertex1 = GetVertex(index1);
    if (!vertex1)
    {
        return false;
    }

    const EdgeKey eKey{ index0, index1 };
    const auto iter = edges.find(eKey);
    if (iter != edges.end())
    {
        edges.erase(iter);

        vertex0->Remove(vertex1);
        vertex1->Remove(vertex0);
        return true;
    }

    return false;
}

template <typename Point2>
std::vector<std::shared_ptr<typename Mathematics::PlanarGraph<Point2>::Primitive>> Mathematics::PlanarGraph<Point2>::ExtractPrimitives()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::vector<std::shared_ptr<Primitive>> primitives{};

    std::set<VertexPtr> heap{};

    for (const auto& value : vertices)
    {
        heap.emplace(value.second);
    }

    while (!heap.empty())
    {
        auto vPtr = *heap.begin();
        auto v0 = vPtr;

        if (v0.Get()->adjacent.size() == 0)
        {
            ExtractIsolatedVertex(v0.Get(), heap, primitives);
        }
        else if (v0.Get()->adjacent.size() == 1)
        {
            ExtractFilament(v0.Get(), v0.Get()->adjacent.at(0).lock(), heap, primitives);
        }
        else
        {
            ExtractPrimitive(v0.Get(), heap, primitives);
        }
    }

    return primitives;
}

template <typename Point2>
void Mathematics::PlanarGraph<Point2>::SetCycleEdge(int index0, int index1, bool cycleEdge)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const EdgeKey eKey{ index0, index1 };
    const auto iter = edges.find(eKey);
    if (iter != edges.end())
    {
        iter->second = cycleEdge;
    }
}

template <typename Point2>
bool Mathematics::PlanarGraph<Point2>::GetCycleEdge(int index0, int index1) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const EdgeKey eKey{ index0, index1 };
    const auto iter = edges.find(eKey);
    if (iter != edges.end())
    {
        return iter->second;
    }

    return false;
}

template <typename Point2>
void Mathematics::PlanarGraph<Point2>::ExtractIsolatedVertex(const std::shared_ptr<Vertex>& v0, std::set<VertexPtr>& heap, std::vector<std::shared_ptr<Primitive>>& primitives)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto primitive = std::make_shared<Primitive>(PrimitiveType::IsolatedVertex);

    primitive->sequence.emplace_back(v0->position, v0->index);
    heap.erase(VertexPtr{ v0 });
    RemoveVertex(v0->index);

    primitives.emplace_back(primitive);
}

template <typename Point2>
void Mathematics::PlanarGraph<Point2>::ExtractFilament(std::shared_ptr<Vertex> v0, std::shared_ptr<Vertex> v1, std::set<VertexPtr>& heap, std::vector<std::shared_ptr<Primitive>>& primitives)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(v0->adjacent.size() != 2, "意外情况\n");
    if (GetCycleEdge(v0->index, v1->index))
    {
        if (v0->adjacent.size() >= 3)
        {
            RemoveEdge(v0->index, v1->index);
            v0 = v1;
            if (v0->adjacent.size() == 1)
            {
                v1 = v0->adjacent.at(0).lock();
            }
        }

        while (v0->adjacent.size() == 1)
        {
            v1 = v0->adjacent.at(0).lock();
            if (GetCycleEdge(v0->index, v1->index))
            {
                heap.erase(VertexPtr{ v0 });
                RemoveEdge(v0->index, v1->index);
                RemoveVertex(v0->index);
                v0 = v1;
            }
            else
            {
                break;
            }
        }

        if (v0->adjacent.size() == 0)
        {
            heap.erase(VertexPtr{ v0 });
            RemoveVertex(v0->index);
        }
    }
    else
    {
        auto primitive = std::make_shared<Primitive>(PrimitiveType::Filament);

        if (v0->adjacent.size() >= 3)
        {
            primitive->sequence.emplace_back(v0->position, v0->index);
            RemoveEdge(v0->index, v1->index);
            v0 = v1;
            if (v0->adjacent.size() == 1)
            {
                v1 = v0->adjacent.at(0).lock();
            }
        }

        while (v0->adjacent.size() == 1)
        {
            v1 = v0->adjacent.at(0).lock();
            primitive->sequence.emplace_back(v0->position, v0->index);
            heap.erase(VertexPtr{ v0 });
            RemoveEdge(v0->index, v1->index);
            RemoveVertex(v0->index);
            v0 = v1;
        }

        primitive->sequence.emplace_back(v0->position, v0->index);

        if (v0->adjacent.size() == 0)
        {
            heap.erase(VertexPtr{ v0 });
            RemoveVertex(v0->index);
        }

        primitives.emplace_back(primitive);
    }
}

template <typename Point2>
void Mathematics::PlanarGraph<Point2>::ExtractPrimitive(std::shared_ptr<Vertex> v0, std::set<VertexPtr>& heap, std::vector<std::shared_ptr<Primitive>>& primitives)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::set<std::shared_ptr<Vertex>> visited{};
    std::vector<std::pair<Point2, int>> sequence{};
    sequence.emplace_back(v0->position, v0->index);
    auto v1 = GetClockwiseMost(0, v0);
    auto vPrev = v0;
    auto vCurr = v1;

    while (vCurr && vCurr != v0 && visited.find(vCurr) == visited.end())
    {
        sequence.emplace_back(vCurr->position, vCurr->index);
        visited.emplace(vCurr);
        auto VNext = GetCounterclockwiseMost(vPrev, vCurr);
        vPrev = vCurr;
        vCurr = VNext;
    }

    if (!vCurr)
    {
        ExtractFilament(vPrev, vPrev->adjacent.at(0).lock(), heap, primitives);
    }
    else if (vCurr == v0)
    {
        auto primitive = std::make_shared<Primitive>(PrimitiveType::MinimalCycle);
        primitive->sequence = sequence;
        primitives.emplace_back(primitive);

        auto sQuantity = boost::numeric_cast<int>(sequence.size());
        for (auto i0 = sQuantity - 1, i1 = 0; i1 < sQuantity; i0 = i1++)
        {
            auto iV0 = sequence.at(i0).second;
            auto iV1 = sequence.at(i1).second;
            SetCycleEdge(iV0, iV1, true);
        }

        RemoveEdge(v0->index, v1->index);

        if (v0->adjacent.size() == 1)
        {
            ExtractFilament(v0, v0->adjacent.at(0).lock(), heap, primitives);
        }

        if (v1->adjacent.size() == 1)
        {
            ExtractFilament(v1, v1->adjacent.at(0).lock(), heap, primitives);
        }
    }
    else
    {
        while (v0->adjacent.size() == 2)
        {
            if (v0->adjacent.at(0).lock() != v1)
            {
                v1 = v0;
                v0 = v0->adjacent.at(0).lock();
            }
            else
            {
                v1 = v0;
                v0 = v0->adjacent.at(1).lock();
            }
        }

        ExtractFilament(v0, v1, heap, primitives);
    }
}

template <typename Point2>
std::shared_ptr<typename Mathematics::PlanarGraph<Point2>::Vertex> Mathematics::PlanarGraph<Point2>::GetClockwiseMost(const std::shared_ptr<Vertex>& vPrev, const std::shared_ptr<Vertex>& vCurr)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::shared_ptr<Vertex> vNext{};
    auto dCurr = (vPrev ? (vCurr->position - vPrev->position) : Point2{ 0, -1 });
    Point2 dNext{};
    auto vCurrConvex = false;

    for (auto i = 0u; i < vCurr->adjacent.size(); ++i)
    {
        auto vAdj = vCurr->adjacent.at(i).lock();

        if (vAdj == vPrev)
        {
            continue;
        }

        auto dAdj = vAdj->position - vCurr->position;

        if (!vNext)
        {
            vNext = vAdj;
            dNext = dAdj;
            vCurrConvex = (dNext[0] * dCurr[1] - dNext[1] * dCurr[0] <= 0);
            continue;
        }

        if (vCurrConvex)
        {
            if (dCurr[0] * dAdj[1] - dCurr[1] * dAdj[0] < 0 || dNext[0] * dAdj[1] - dNext[1] * dAdj[0] < 0)
            {
                vNext = vAdj;
                dNext = dAdj;
                vCurrConvex = (dNext[0] * dCurr[1] - dNext[1] * dCurr[0] <= 0);
            }
        }
        else
        {
            if (dCurr[0] * dAdj[1] - dCurr[1] * dAdj[0] < 0 && dNext[0] * dAdj[1] - dNext[1] * dAdj[0] < 0)
            {
                vNext = vAdj;
                dNext = dAdj;
                vCurrConvex = (dNext[0] * dCurr[1] - dNext[1] * dCurr[0] <= 0);
            }
        }
    }

    return vNext;
}

template <typename Point2>
std::shared_ptr<typename Mathematics::PlanarGraph<Point2>::Vertex> Mathematics::PlanarGraph<Point2>::GetCounterclockwiseMost(const std::shared_ptr<Vertex>& vPrev, const std::shared_ptr<Vertex>& vCurr)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::shared_ptr<Vertex> vNext{};
    auto dCurr = (vPrev ? vCurr->position - vPrev->position : Point2(0, -1));
    Point2 dNext{};
    auto vCurrConvex = false;

    for (auto i = 0u; i < vCurr->adjacent.size(); ++i)
    {
        auto vAdj = vCurr->adjacent.at(i).lock();

        if (vAdj == vPrev)
        {
            continue;
        }

        auto dAdj = vAdj->position - vCurr->position;

        if (!vNext)
        {
            vNext = vAdj;
            dNext = dAdj;
            vCurrConvex = (dNext[0] * dCurr[1] - dNext[1] * dCurr[0] <= 0);
            continue;
        }

        if (vCurrConvex)
        {
            if (dCurr[0] * dAdj[1] - dCurr[1] * dAdj[0] > 0 && dNext[0] * dAdj[1] - dNext[1] * dAdj[0] > 0)
            {
                vNext = vAdj;
                dNext = dAdj;
                vCurrConvex = (dNext[0] * dCurr[1] - dNext[1] * dCurr[0] <= 0);
            }
        }
        else
        {
            if (dCurr[0] * dAdj[1] - dCurr[1] * dAdj[0] > 0 || dNext[0] * dAdj[1] - dNext[1] * dAdj[0] > 0)
            {
                vNext = vAdj;
                dNext = dAdj;
                vCurrConvex = (dNext[0] * dCurr[1] - dNext[1] * dCurr[0] <= 0);
            }
        }
    }

    return vNext;
}

// PlanarGraph::Vertex

template <typename Point2>
Mathematics::PlanarGraph<Point2>::Vertex::Vertex(const Point2& position, int index) noexcept
    : position{ position }, index{ index }
{
}

template <typename Point2>
void Mathematics::PlanarGraph<Point2>::Vertex::Insert(const std::shared_ptr<Vertex>& adjacentVertex)
{
    adjacent.emplace_back(adjacentVertex);
}

template <typename Point2>
void Mathematics::PlanarGraph<Point2>::Vertex::Remove(const std::shared_ptr<Vertex>& adjacentVertex)
{
    auto numAdjacents = boost::numeric_cast<int>(adjacent.size());
    for (auto i = 0; i < numAdjacents; ++i)
    {
        if (adjacentVertex == adjacent.at(i).lock())
        {
            --numAdjacents;
            if (i < numAdjacents)
            {
                adjacent.at(i) = adjacent.at(numAdjacents);
            }
            adjacent.pop_back();
            return;
        }
    }
}

// PlanarGraph::Primitive

template <typename Point2>
Mathematics::PlanarGraph<Point2>::Primitive::Primitive(PrimitiveType type) noexcept
    : primitiveType{ type }
{
}

// PlanarGraph::VertexPtr

template <typename Point2>
Mathematics::PlanarGraph<Point2>::VertexPtr::VertexPtr(const std::shared_ptr<Vertex>& vertex) noexcept
    : vertex{ vertex }
{
}

template <typename Point2>
std::shared_ptr<typename Mathematics::PlanarGraph<Point2>::Vertex> Mathematics::PlanarGraph<Point2>::VertexPtr::Get() noexcept
{
    return vertex;
}

template <typename Point2>
bool Mathematics::PlanarGraph<Point2>::VertexPtr::operator<(const VertexPtr& vertexPtr) const
{
    if (vertex->position[0] < vertexPtr.vertex->position[0])
    {
        return true;
    }

    if (vertex->position[0] > vertexPtr.vertex->position[0])
    {
        return false;
    }

    return vertex->position[1] < vertexPtr.vertex->position[1];
}

#endif  // MATHEMATICS_MESHES_PLANAR_GRAPH_DETAIL_H