///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 16:07)

#ifndef MATHEMATICS_OBJECTS3D_TETRAHEDRON3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_TETRAHEDRON3_ACHIEVE_H

#include "Tetrahedron3.h"
#include "Detail/Tetrahedron3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Tetrahedron3<Real>::Tetrahedron3(const Vector3D& vertex0, const Vector3D& vertex1, const Vector3D& vertex2, const Vector3D& vertex3)
    : m_Impl{ std::make_shared<ImplType>(vertex0, vertex1, vertex2, vertex3) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Tetrahedron3<Real>::Tetrahedron3(const ContainerType& vertex)
    : m_Impl{ std::make_shared<ImplType>(vertex) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Tetrahedron3<Real>::Copy()
{
    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "It is not allowed to define the Copy function used for copy delayed.");

    MATHEMATICS_CLASS_IS_VALID_1;

    if (1 < m_Impl.use_count())
    {
        m_Impl = std::make_shared<ImplType>(*m_Impl);
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Tetrahedron3<Real>::IsValid() const noexcept
{
    return m_Impl != nullptr;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Tetrahedron3<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetVertex(index);
}

template <typename Real>
void Mathematics::Tetrahedron3<Real>::SetVertex(int index, const Vector3D& vertex)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetVertex(index, vertex);
}

// static
template <typename Real>
typename Mathematics::Tetrahedron3<Real>::IndicesType Mathematics::Tetrahedron3<Real>::GetFaceIndices(int face)
{
    return ImplType::GetFaceIndices(face);
}

template <typename Real>
const typename Mathematics::Tetrahedron3<Real>::PlaneContainerType Mathematics::Tetrahedron3<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPlanes();
}

template <typename Real>
const Mathematics::Tetrahedron3<Real> Mathematics::Tetrahedron3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto movedV0 = GetVertex(0) + t * velocity;
    auto movedV1 = GetVertex(1) + t * velocity;
    auto movedV2 = GetVertex(2) + t * velocity;
    auto movedV3 = GetVertex(3) + t * velocity;
    Tetrahedron3 movedTetra{ movedV0, movedV1, movedV2, movedV3 };

    return movedTetra;
}

#endif  // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_ACHIEVE_H
