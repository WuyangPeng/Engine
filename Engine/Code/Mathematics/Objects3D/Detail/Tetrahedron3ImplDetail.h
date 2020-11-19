///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 15:52)

#ifndef MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_DETAIL_H

#include "Tetrahedron3Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Tetrahedron3Impl<Real>::Tetrahedron3Impl(const Vector3D& vertex0, const Vector3D& vertex1, const Vector3D& vertex2, const Vector3D& vertex3) noexcept
    : m_Vertex{ vertex0, vertex1, vertex2, vertex3 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Tetrahedron3Impl<Real>::Tetrahedron3Impl(const ContainerType& vertex)
    : m_Vertex{}
{
    if (vertex.size() != sm_VertexSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的数组大小错误！"s));
    }

    auto index = 0;
    for (auto& value : m_Vertex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        value = vertex[index];
#include STSTEM_WARNING_POP

        ++index;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Tetrahedron3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Tetrahedron3Impl<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Vertex.at(index);
}

template <typename Real>
void Mathematics::Tetrahedron3Impl<Real>::SetVertex(int index, const Vector3D& vertex)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Vertex.at(index) = vertex;
}

// static
template <typename Real>
typename Mathematics::Tetrahedron3Impl<Real>::IndicesType Mathematics::Tetrahedron3Impl<Real>::GetFaceIndices(int face)
{
    MATHEMATICS_ASSERTION_0(0 <= face && face <= 3, "索引错误！");

    switch (face)
    {
        case 0:
            return IndicesType{ 0, 2, 1 };
        case 1:
            return IndicesType{ 0, 1, 3 };
        case 2:
            return IndicesType{ 0, 3, 2 };
        default:  // face == 3
            return IndicesType{ 1, 2, 3 };
    }
}

template <typename Real>
typename Mathematics::Tetrahedron3Impl<Real>::PlaneContainerType Mathematics::Tetrahedron3Impl<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto edge10 = m_Vertex[1] - m_Vertex[0];
    auto edge20 = m_Vertex[2] - m_Vertex[0];
    auto edge30 = m_Vertex[3] - m_Vertex[0];
    auto edge21 = m_Vertex[2] - m_Vertex[1];
    auto edge31 = m_Vertex[3] - m_Vertex[1];

#include STSTEM_WARNING_POP

    // <v0,v2,v1>
    // <v0,v1,v3>
    // <v0,v3,v2>
    // <v1,v2,v3>
    std::array<Vector3D, sm_VertexSize> normal{ Vector3DTools::UnitCrossProduct(edge20, edge10), Vector3DTools::UnitCrossProduct(edge10, edge30),
                                                Vector3DTools::UnitCrossProduct(edge30, edge20), Vector3DTools::UnitCrossProduct(edge21, edge31) };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    auto det = Vector3DTools::DotProduct(edge10, normal[3]);
#include STSTEM_WARNING_POP

    if (det < Math::GetValue(0))
    {
        // 法线是指向内部点，改变他们的方向。
        for (auto& value : normal)
        {
            value = -value;
        }
    }

    PlaneContainerType plane{};

    for (auto i = 0; i < sm_VertexSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        plane.emplace_back(normal[i], m_Vertex[i]);
#include STSTEM_WARNING_POP
    }

    MATHEMATICS_ASSERTION_1(plane.size() == sm_VertexSize, "返回的面大小错误！");

    return plane;
}

#endif  // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_DETAIL_H
