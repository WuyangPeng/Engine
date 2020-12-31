///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 10:05)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_DETAIL_H

#include "ConvexPolygon2Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::ConvexPolygon2Impl<Real>::ConvexPolygon2Impl(const LineType& lines)
    : m_Lines{ lines }, m_SharingEdges{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ConvexPolygon2Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::ConvexPolygon2Impl<Real>::LineType Mathematics::ConvexPolygon2Impl<Real>::GetLines() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Lines;
}

template <typename Real>
const Mathematics::Line2<Real>& Mathematics::ConvexPolygon2Impl<Real>::GetLine(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Lines.at(index);
}

template <typename Real>
int Mathematics::ConvexPolygon2Impl<Real>::GetNumLine() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Lines.size());
}

template <typename Real>
void Mathematics::ConvexPolygon2Impl<Real>::SetVertex(int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // �����������Ĺ���ߡ�
    // ��Щ�߻����Ժ���¡�
    // ��������������ı�i��E[i] = <V[i],V[i+1]> �� E[i-1] = <V[i-1],V[i]>��
    // ����i+1 �� i-1������Ϊ��������ģ��
    m_SharingEdges.insert((index - 1) % this->GetNumLine());
    m_SharingEdges.insert(index);
}

template <typename Real>
bool Mathematics::ConvexPolygon2Impl<Real>::IsUpdateLines() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !m_SharingEdges.empty();
}

template <typename Real>
void Mathematics::ConvexPolygon2Impl<Real>::ClearSharingEdges() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_SharingEdges.clear();
}

template <typename Real>
void Mathematics::ConvexPolygon2Impl<Real>::UpdateLine(int index, const Vector2D& origin, const Vector2D& direction)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto line = m_Lines.at(index);

    line.SetOrigin(origin);
    line.SetDirection(direction);
}

template <typename Real>
typename Mathematics::ConvexPolygon2Impl<Real>::LineTypeConstIter Mathematics::ConvexPolygon2Impl<Real>::begin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Lines.begin();
}

template <typename Real>
typename Mathematics::ConvexPolygon2Impl<Real>::LineTypeConstIter Mathematics::ConvexPolygon2Impl<Real>::end() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Lines.end();
}

#endif  // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_DETAIL_H
