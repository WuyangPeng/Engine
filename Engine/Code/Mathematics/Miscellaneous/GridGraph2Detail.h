///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:22)

#ifndef MATHEMATICS_MISCELLANEOUS_GRID_GRAPH2_DETAIL_H
#define MATHEMATICS_MISCELLANEOUS_GRID_GRAPH2_DETAIL_H

#include "GridGraph2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::GridGraph2<Real>::GridGraph2(int xSize, int ySize)
    : relaxationCallback{ nullptr },
      xSize{ xSize },
      ySize{ ySize },
      numVertices{ xSize * ySize },
      vertices(numVertices),
      pathQuantity{ 0 },
      path(numVertices),
      pending(numVertices),
      numProcessed{ 0 }
{
    MATHEMATICS_ASSERTION_0(xSize > 0 && ySize > 0, "无效输入。\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::GridGraph2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::GridGraph2<Real>::GetXSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xSize;
}

template <typename Real>
int Mathematics::GridGraph2<Real>::GetYSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ySize;
}

template <typename Real>
int Mathematics::GridGraph2<Real>::GetVertexQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numVertices;
}

template <typename Real>
void Mathematics::GridGraph2<Real>::SetWeight(int x, int y, int dx, int dy, Real weight)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(0 <= x && x < xSize && 0 <= y && y < ySize, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(abs(dx) <= 1 && abs(dy) <= 1, "无效输入。\n");

    vertices.at(GetIndex(x, y)).SetWeight(dx, dy, weight);
}

template <typename Real>
Real Mathematics::GridGraph2<Real>::GetWeight(int x, int y, int dx, int dy) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(0 <= x && x < xSize && 0 <= y && y < ySize, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(abs(dx) <= 1 && abs(dy) <= 1, "无效输入。\n");

    return vertices.at(GetIndex(x, y)).GetWeight(dx, dy);
}

template <typename Real>
void Mathematics::GridGraph2<Real>::ComputeMinimumWeightPath(int x0, int y0, int x1, int y1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    pathQuantity = 0;

    if (x0 < 0 || x0 >= xSize || y0 < 0 || y0 >= ySize || x1 < 0 || x1 >= xSize || y1 < 0 || y1 >= ySize)
    {
        return;
    }

    auto pendingQuantity = numVertices;

    for (auto i = 0; i < numVertices; ++i)
    {
        auto& vertex = vertices.at(i);
        vertex.SetEstimate(Math<Real>::maxReal);
        vertex.SetPredecessor(-1);
        pending.at(i) = i;
    }
    vertices.at(GetIndex(x0, y0)).SetEstimate(Math<Real>::GetValue(0));

    numProcessed = 0;
    if (relaxationCallback)
    {
        relaxationCallback();
    }

    while (pendingQuantity > 0)
    {
        auto minimum = vertices.at(pending.at(0)).GetEstimate();
        auto minIndex = 0;
        for (auto i = 1; i < pendingQuantity; ++i)
        {
            auto value = vertices.at(pending.at(i)).GetEstimate();
            if (value < minimum)
            {
                minimum = value;
                minIndex = i;
            }
        }

        auto minVertexIndex = pending.at(minIndex);
        --pendingQuantity;
        if (minIndex != pendingQuantity)
        {
            pending.at(minIndex) = pending.at(pendingQuantity);
        }

        auto& minVertex = vertices.at(minVertexIndex);
        const auto xmin = GetX(minVertexIndex);
        const auto ymin = GetY(minVertexIndex);
        for (auto dy = -1; dy <= 1; ++dy)
        {
            for (auto dx = -1; dx <= 1; ++dx)
            {
                if (dx != 0 || dy != 0)
                {
                    const auto xadj = xmin + dx;
                    const auto yadj = ymin + dy;
                    if (0 <= xadj && xadj < xSize && 0 <= yadj && yadj < ySize)
                    {
                        auto& adjacent = vertices.at(GetIndex(xadj, yadj));

                        auto weight = GetWeight(xmin, ymin, dx, dy);
                        auto newEstimate = minVertex.GetEstimate() + weight;
                        if (adjacent.GetEstimate() > newEstimate)
                        {
                            adjacent.SetEstimate(newEstimate);
                            adjacent.SetPredecessor(minVertexIndex);
                        }
                    }
                }
            }
        }

        ++numProcessed;
        if (relaxationCallback)
        {
            relaxationCallback();
        }
    }

    auto value = 0;
    auto i = GetIndex(x1, y1);
    while (i >= 0)
    {
        ++pathQuantity;
        path.at(value++) = i;

        i = vertices.at(i).GetPredecessor();
    }
}

template <typename Real>
int Mathematics::GridGraph2<Real>::GetPathQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return pathQuantity;
}

template <typename Real>
void Mathematics::GridGraph2<Real>::GetPathPoint(int i, int& x, int& y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= i && i < pathQuantity)
    {
        x = GetX(path.at(i));
        y = GetY(path.at(i));
    }
}

template <typename Real>
int Mathematics::GridGraph2<Real>::GetNumProcessed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numProcessed;
}

// GridGraph2::Vertex

template <typename Real>
Mathematics::GridGraph2<Real>::Vertex::Vertex() noexcept
    : estimate{ Math<Real>::maxReal },
      predecessor{ -1 },
      weight{ Math<Real>::maxReal, Math<Real>::maxReal, Math<Real>::maxReal, Math<Real>::maxReal, Math<Real>::maxReal, Math<Real>::maxReal, Math<Real>::maxReal, Math<Real>::maxReal }
{
}

template <typename Real>
void Mathematics::GridGraph2<Real>::Vertex::SetWeight(int dx, int dy, Real newWeight)
{
    const auto x = dx + 1;
    const auto y = dy + 1;
    weight.at(index.at(y).at(x)) = newWeight;
}

template <typename Real>
Real Mathematics::GridGraph2<Real>::Vertex::GetWeight(int dx, int dy) const
{
    const auto x = dx + 1;
    const auto y = dy + 1;
    return weight.at(index.at(y).at(x));
}

template <typename Real>
int Mathematics::GridGraph2<Real>::GetIndex(int x, int y) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x + xSize * y;
}

template <typename Real>
int Mathematics::GridGraph2<Real>::GetX(int newIndex) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return newIndex % xSize;
}

template <typename Real>
int Mathematics::GridGraph2<Real>::GetY(int newIndex) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return newIndex / xSize;
}

template <typename Real>
Real Mathematics::GridGraph2<Real>::Vertex::GetEstimate() const noexcept
{
    return estimate;
}

template <typename Real>
void Mathematics::GridGraph2<Real>::Vertex::SetEstimate(Real val) noexcept
{
    estimate = val;
}

template <typename Real>
int Mathematics::GridGraph2<Real>::Vertex::GetPredecessor() const noexcept
{ 
    return predecessor;
}

template <typename Real>
void Mathematics::GridGraph2<Real>::Vertex::SetPredecessor(int val) noexcept
{
    predecessor = val;
}

template <typename Real>
const std::array<std::array<int, 3>, 3> Mathematics::GridGraph2<Real>::index{ std::array<int, 3>{ 0, 1, 2 }, std::array<int, 3>{ 3, -1, 4 }, std::array<int, 3>{ 5, 6, 7 } };

#endif  // MATHEMATICS_MISCELLANEOUS_GRID_GRAPH2_DETAIL_H