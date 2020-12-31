///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 18:41)

#ifndef MATHEMATICS_OBJECTS3D_POLYHEDRON3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_POLYHEDRON3_ACHIEVE_H

#include "Polyhedron3.h"
#include "Detail/Polyhedron3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Polyhedron3<Real>::Polyhedron3(const VerticesType& vertices, const IndicesType& indices)
    : m_Impl{ std::make_shared<ImplType>(vertices, indices) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polyhedron3<Real>::Polyhedron3(const Polyhedron3& rhs)
    : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::Polyhedron3<Real>& Mathematics::Polyhedron3<Real>::operator=(const Polyhedron3& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    Polyhedron3 result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
void Mathematics::Polyhedron3<Real>::Swap(Polyhedron3& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::Polyhedron3<Real>::Polyhedron3(Polyhedron3&& rhs) noexcept
    : m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::Polyhedron3<Real>& Mathematics::Polyhedron3<Real>::operator=(Polyhedron3&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polyhedron3<Real>::IsValid() const noexcept
{
    return m_Impl != nullptr;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Polyhedron3<Real>::GetNumVertices() const  
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNumVertices();
}

template <typename Real>
typename const Mathematics::Polyhedron3<Real>::VerticesType Mathematics::Polyhedron3<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetVertices();
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::Polyhedron3<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetVertex(index);
}

template <typename Real>
int Mathematics::Polyhedron3<Real>::GetNumTriangles() const  
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNumTriangles();
}

template <typename Real>
int Mathematics::Polyhedron3<Real>::GetNumIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNumIndices();
}

template <typename Real>
typename const Mathematics::Polyhedron3<Real>::IndicesType Mathematics::Polyhedron3<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetIndices();
}

template <typename Real>
typename const Mathematics::Polyhedron3<Real>::IndicesType Mathematics::Polyhedron3<Real>::GetTriangle(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTriangle(index);
}

template <typename Real>
void Mathematics::Polyhedron3<Real>::SetVertex(int index, const Vector3D& vertex)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetVertex(index, vertex);
}

template <typename Real>
typename const Mathematics::Polyhedron3<Real>::Vector3D Mathematics::Polyhedron3<Real>::ComputeVertexAverage() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ComputeVertexAverage();
}

template <typename Real>
Real Mathematics::Polyhedron3<Real>::ComputeSurfaceArea() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ComputeSurfaceArea();
}

template <typename Real>
Real Mathematics::Polyhedron3<Real>::ComputeVolume() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ComputeVolume();
}

#endif  // MATHEMATICS_OBJECTS3D_POLYHEDRON3_ACHIEVE_H
