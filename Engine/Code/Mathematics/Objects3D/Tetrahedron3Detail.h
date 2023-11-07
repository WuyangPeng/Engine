///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 17:25)

#ifndef MATHEMATICS_OBJECTS_3D_TETRAHEDRON3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_TETRAHEDRON3_DETAIL_H

#include "Tetrahedron3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Tetrahedron3<Real>::Tetrahedron3(const Vector3& vertex0, const Vector3& vertex1, const Vector3& vertex2, const Vector3& vertex3) noexcept
    : vertex{ vertex0, vertex1, vertex2, vertex3 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Tetrahedron3<Real>::Tetrahedron3(const ContainerType& container)
    : vertex{}
{
    if (container.size() != vertexSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的数组大小错误！"s));
    }

    for (auto i = 0; i < vertexSize; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        vertex[i] = container[i];

#include SYSTEM_WARNING_POP
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Tetrahedron3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Tetrahedron3<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex.at(index);
}

template <typename Real>
void Mathematics::Tetrahedron3<Real>::SetVertex(int index, const Vector3& aVertex)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    vertex.at(index) = aVertex;
}

template <typename Real>
typename Mathematics::Tetrahedron3<Real>::IndicesType Mathematics::Tetrahedron3<Real>::GetFaceIndices(int face)
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
typename Mathematics::Tetrahedron3<Real>::PlaneContainerType Mathematics::Tetrahedron3<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto edge10 = vertex[1] - vertex[0];
    const auto edge20 = vertex[2] - vertex[0];
    const auto edge30 = vertex[3] - vertex[0];
    const auto edge21 = vertex[2] - vertex[1];
    const auto edge31 = vertex[3] - vertex[1];

#include SYSTEM_WARNING_POP

    // <v0,v2,v1>
    // <v0,v1,v3>
    // <v0,v3,v2>
    // <v1,v2,v3>
    std::array<Vector3, vertexSize> normal{ Vector3Tools::UnitCrossProduct(edge20, edge10),
                                            Vector3Tools::UnitCrossProduct(edge10, edge30),
                                            Vector3Tools::UnitCrossProduct(edge30, edge20),
                                            Vector3Tools::UnitCrossProduct(edge21, edge31) };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto det = Vector3Tools::DotProduct(edge10, normal[3]);

#include SYSTEM_WARNING_POP

    if (det < Math::GetValue(0))
    {
        // 法线是指向内部点，改变他们的方向。
        for (auto& value : normal)
        {
            value = -value;
        }
    }

    PlaneContainerType plane{};

    for (auto i = 0; i < vertexSize; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        plane.emplace_back(normal[i], vertex[i]);

#include SYSTEM_WARNING_POP
    }

    MATHEMATICS_ASSERTION_1(plane.size() == vertexSize, "返回的面大小错误！");

    return plane;
}

template <typename Real>
Mathematics::Tetrahedron3<Real> Mathematics::Tetrahedron3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedV0 = GetVertex(0) + t * velocity;
    const auto movedV1 = GetVertex(1) + t * velocity;
    const auto movedV2 = GetVertex(2) + t * velocity;
    const auto movedV3 = GetVertex(3) + t * velocity;
    const Tetrahedron3 movedTetra{ movedV0, movedV1, movedV2, movedV3 };

    return movedTetra;
}

#endif  // MATHEMATICS_OBJECTS_3D_TETRAHEDRON3_DETAIL_H
