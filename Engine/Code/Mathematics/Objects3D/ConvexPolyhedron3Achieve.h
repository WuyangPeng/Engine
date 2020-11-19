///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 11:24)

#ifndef MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_ACHIEVE_H

#include "ConvexPolyhedron3.h"
#include "Polyhedron3Detail.h"
#include "Detail/ConvexPolyhedron3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::ConvexPolyhedron3<Real>::ConvexPolyhedron3(const VerticesType& vertices, const IndicesType& indices, const PlaneContainerType& planes)
    : ParentType{ vertices, indices }, m_Impl{ std::make_shared<ImplType>(planes) }
{
    InitPlanes();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::InitPlanes()
{
    if (m_Impl->GetNumPlane() == 0)
    {
        const auto numTriangles = this->GetNumTriangles();
        m_Impl->ResetTriangles(numTriangles);

        UpdatePlanes();
    }
}

template <typename Real>
Mathematics::ConvexPolyhedron3<Real>::ConvexPolyhedron3(const ConvexPolyhedron3& rhs)
    : ParentType{ rhs }, m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::ConvexPolyhedron3<Real>& Mathematics::ConvexPolyhedron3<Real>::operator=(const ConvexPolyhedron3& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    ConvexPolyhedron3 result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::Swap(ConvexPolyhedron3& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::Swap(rhs);

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::ConvexPolyhedron3<Real>::ConvexPolyhedron3(ConvexPolyhedron3&& rhs) noexcept
    : ParentType{ std::move(rhs) }, m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::ConvexPolyhedron3<Real>& Mathematics::ConvexPolyhedron3<Real>::operator=(ConvexPolyhedron3&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    ParentType::operator=(std::move(rhs));

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::ConvexPolyhedron3<Real>::PlaneContainerType Mathematics::ConvexPolyhedron3<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (IsUpdatePlanes())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("需要更新平面!\n"s));
    }

    return m_Impl->GetPlanes();
}

template <typename Real>
const Mathematics::Plane3<Real>& Mathematics::ConvexPolyhedron3<Real>::GetPlane(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (IsUpdatePlanes())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("需要更新平面!\n"s));
    }

    return m_Impl->GetPlane(index);
}

template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::SetVertex(int index, const Vector3D& vertex)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::SetVertex(index, vertex);

    // 跟踪面分享的顶点。他们的平面需要在以后更新。
    const auto numTriangles = this->GetNumTriangles();
    for (auto i = 0; i < numTriangles; ++i)
    {
        const auto indices = this->GetTriangle(i);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        if (index == indices[0] || index == indices[1] || index == indices[2])
        {
            m_Impl->SetVertex(i);
        }
#include STSTEM_WARNING_POP
    }
}

template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::UpdatePlanes()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (IsUpdatePlanes())
    {
        const auto average = this->ComputeVertexAverage();
        const auto numTriangles = this->GetNumTriangles();
        for (auto i = 0; i < numTriangles; ++i)
        {
            UpdatePlane(i, average);
        }

        m_Impl->ClearSharingTriangles();
    }
}

// private
template <typename Real>
void Mathematics::ConvexPolyhedron3<Real>::UpdatePlane(int index, const Vector3D& average)
{
    auto indices = this->GetIndices();
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
    auto normal = Vector3DTools::CrossProduct(edge2, edge1);
    auto length = Vector3DTools::VectorMagnitude(normal);
    if (Math::GetZeroTolerance() < length)
    {
        normal /= length;
        auto dot = Vector3DTools::DotProduct(normal, diff);
        MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= dot, "点积必须为非负数\n");
        if (dot < Math::GetValue(0))
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
    m_Impl->UpdatePlane(index, vertex0, normal);
}

template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>::IsUpdatePlanes() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsUpdatePlanes();
}

template <typename Real>
bool Mathematics::ConvexPolyhedron3<Real>::IsConvex(Real threshold) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(threshold <= Math::GetValue(0), "threshold必须为负值！");

    if (IsUpdatePlanes())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("需要更新平面。\n"s));
    }

    auto maxDistance = -Math::sm_MaxReal;
    auto minDistance = Math::sm_MaxReal;

    for (const auto& plane : *m_Impl)
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
bool Mathematics::ConvexPolyhedron3<Real>::Contains(const Vector3D& point, Real threshold) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_1(threshold <= Math::GetValue(0), "threshold必须为负值！");

    if (IsUpdatePlanes())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("需要更新平面。\n"s));
    }

    for (const auto& plane : *m_Impl)
    {
        auto distance = plane.DistanceTo(point);

        if (distance < threshold)
        {
            return false;
        }
    }

    return true;
}

#endif  // MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_ACHIEVE_H
