/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:39)

#ifndef MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_DETAIL_H

#include "ConvexPolyhedron3.h"
#include "Polyhedron3Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::ConvexPolyhedron3<Real>::ConvexPolyhedron3(const VerticesType& vertices, const IndicesType& indices, const PlaneContainerType& planes)
    : ParentType{ vertices, indices }, planes{ planes }, sharingTriangles{}
{
    InitPlanes();

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::InitPlanes()
{
    if (planes.empty())
    {
        const auto numTriangles = this->GetNumTriangles();
        planes.resize(numTriangles);

        for (auto i = 0; i < numTriangles; ++i)
        {
            sharingTriangles.insert(i);
        }

        UpdatePlanes();
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::ConvexPolyhedron3<Real>::PlaneContainerType Mathematics::ConvexPolyhedron3<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (IsUpdatePlanes())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("需要更新平面!\n"s));
    }

    return planes;
}

template <typename Real>
const Mathematics::Plane3<Real>& Mathematics::ConvexPolyhedron3<Real>::GetPlane(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (IsUpdatePlanes())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("需要更新平面!\n"s));
    }

    return planes.at(index);
}

template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::SetVertex(int index, const Vector3& vertex)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    ParentType::SetVertex(index, vertex);

    // 跟踪面分享的顶点。他们的平面需要在以后更新。
    const auto numTriangles = this->GetNumTriangles();
    for (auto i = 0; i < numTriangles; ++i)
    {
        const auto indices = this->GetTriangle(i);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        if (index == indices[0] || index == indices[1] || index == indices[2])
        {
            sharingTriangles.insert(i);
        }

#include SYSTEM_WARNING_POP
    }
}

template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::UpdatePlanes()
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (IsUpdatePlanes())
    {
        const auto average = this->ComputeVertexAverage();
        const auto numTriangles = this->GetNumTriangles();
        for (auto i = 0; i < numTriangles; ++i)
        {
            UpdatePlane(i, average);
        }

        sharingTriangles.clear();
    }
}

// private
template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::UpdatePlane(int index, const Vector3& average)
{
    const auto indices = this->GetIndices();
    const auto base0 = 3 * index;
    const auto base1 = base0 + 1;
    const auto base2 = base0 + 2;

    auto v0 = indices.at(base0);
    auto v1 = indices.at(base1);
    auto v2 = indices.at(base2);

    const auto& vertex0 = this->GetVertex(v0);
    const auto& vertex1 = this->GetVertex(v1);
    const auto& vertex2 = this->GetVertex(v2);

    auto diff = average - vertex0;
    auto edge1 = vertex1 - vertex0;
    auto edge2 = vertex2 - vertex0;
    auto normal = Vector3Tools::CrossProduct(edge2, edge1);
    auto length = Vector3Tools::GetLength(normal);
    if (MathType::GetZeroTolerance() < length)
    {
        normal /= length;
        auto dot = Vector3Tools::DotProduct(normal, diff);
        MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= dot, "点积必须为非负数\n");
        if (dot < MathType::GetValue(0))
        {
            normal = -normal;
        }
    }
    else
    {
        // 三角形退化。使用“normal”指向平均值朝向。
        normal = diff;
        normal.Normalize();
    }

    // 平面具有内指向的法线。
    auto& plane = planes.at(index);

    plane.SetPlane(normal, vertex0);
}

template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>::IsUpdatePlanes() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return !sharingTriangles.empty();
}

template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>::IsConvex(Real threshold) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_1(threshold <= MathType::GetValue(0), "threshold必须为负值！");

    if (IsUpdatePlanes())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("需要更新平面。\n"s))
    }

    auto maxDistance = -MathType::maxReal;
    auto minDistance = MathType::maxReal;

    for (const auto& plane : planes)
    {
        for (auto i = 0; i < this->GetNumVertices(); ++i)
        {
            auto distance = plane.DistanceTo(ParentType::GetVertex(i));

            if (distance < minDistance)
            {
                minDistance = distance;
            }
            if (maxDistance < distance)
            {
                maxDistance = distance;
            }

            if (distance < threshold)
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>::Contains(const Vector3& point, Real threshold) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_1(threshold <= MathType::GetValue(0), "threshold必须为负值！");

    if (IsUpdatePlanes())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("需要更新平面。\n"s))
    }

    for (const auto& plane : planes)
    {
        const auto distance = plane.DistanceTo(point);

        if (distance < threshold)
        {
            return false;
        }
    }

    return true;
}

#endif  // MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_DETAIL_H
