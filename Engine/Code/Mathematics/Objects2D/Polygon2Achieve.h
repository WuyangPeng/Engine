///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 15:00)

#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_ACHIEVE_H

#include "Polygon2.h"
#include "Detail/Polygon2ImplDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Polygon2<Real>::Polygon2(const VerticesType& vertices)
    : m_Impl{ std::make_shared<ImplType>(vertices) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polygon2<Real>::Polygon2(const Polygon2& rhs)
    : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::Polygon2<Real>& Mathematics::Polygon2<Real>::operator=(const Polygon2& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    Polygon2 result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
void Mathematics::Polygon2<Real>::Swap(Polygon2& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::Polygon2<Real>::Polygon2(Polygon2&& rhs) noexcept
    : m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::Polygon2<Real>& Mathematics::Polygon2<Real>::operator=(Polygon2&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polygon2<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Polygon2<Real>::GetNumVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNumVertices();
}

template <typename Real>
const typename Mathematics::Polygon2<Real>::VerticesType& Mathematics::Polygon2<Real>::GetVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetVertices();
}

template <typename Real>
const Mathematics::Vector2D<Real>& Mathematics::Polygon2<Real>::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetVertex(index);
}

template <typename Real>
void Mathematics::Polygon2<Real>::SetVertex(int index, const Vector2D& vertex)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetVertex(index, vertex);
}

template <typename Real>
const typename Mathematics::Polygon2<Real>::Vector2D Mathematics::Polygon2<Real>::ComputeVertexAverage() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ComputeVertexAverage();
}

template <typename Real>
Real Mathematics::Polygon2<Real>::ComputePerimeterLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ComputePerimeterLength();
}

template <typename Real>
Real Mathematics::Polygon2<Real>::ComputeArea() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ComputeArea();
}

#endif  // MATHEMATICS_OBJECTS2D_POLYGON2_ACHIEVE_H
