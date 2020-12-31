///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 10:06)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_ACHIEVE_H

#include "ConvexPolygon2.h"
#include "Detail/ConvexPolygon2ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector2DTools.h"

template <typename Real>
Mathematics::ConvexPolygon2<Real>::ConvexPolygon2(const VerticesType& vertices, const LineType& lines)
    : ParentType{ vertices }, m_Impl{ std::make_shared<ImplType>(lines) }
{
    if (vertices.size() != lines.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�߶κͶ���Ĵ�С����ȡ�\n"s));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::ConvexPolygon2<Real>::ConvexPolygon2(const ConvexPolygon2& rhs)
    : ParentType{ rhs }, m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::ConvexPolygon2<Real>& Mathematics::ConvexPolygon2<Real>::operator=(const ConvexPolygon2& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    ConvexPolygon2 temp{ rhs };

    Swap(temp);

    return *this;
}

template <typename Real>
void Mathematics::ConvexPolygon2<Real>::Swap(ConvexPolygon2& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::Swap(rhs);

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::ConvexPolygon2<Real>::ConvexPolygon2(ConvexPolygon2&& rhs) noexcept
    : ParentType{ std::move(rhs) }, m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::ConvexPolygon2<Real>& Mathematics::ConvexPolygon2<Real>::operator=(ConvexPolygon2&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    ParentType::operator=(std::move(rhs));

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ConvexPolygon2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::ConvexPolygon2<Real>::LineType Mathematics::ConvexPolygon2<Real>::GetLines() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (IsUpdateLines())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ҫ�����߶Ρ�\n"s));
    }

    return m_Impl->GetLines();
}

template <typename Real>
const Mathematics::Line2<Real>& Mathematics::ConvexPolygon2<Real>::GetLine(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (IsUpdateLines())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ҫ�����߶Ρ�\n"s));
    }

    return m_Impl->GetLine(index);
}

template <typename Real>
void Mathematics::ConvexPolygon2<Real>::SetVertex(int index, const Vector2D& vertex)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::SetVertex(index, vertex);

    // �����������Ĺ���ߣ���Щ�߻����Ժ���¡�
    // ��������������ı�i��E[i] = <V[i],V[i+1]> �� E[i-1] = <V[i-1],V[i]>��
    // ����i+1 �� i-1������Ϊ��������ģ��
    return m_Impl->SetVertex(index);
}

template <typename Real>
void Mathematics::ConvexPolygon2<Real>::UpdateLines()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (IsUpdateLines())
    {
        const auto average = this->ComputeVertexAverage();
        for (auto i = 0; i < this->GetNumVertices(); ++i)
        {
            UpdateLine(i, average);
        }

        m_Impl->ClearSharingEdges();
    }
}

// private
template <typename Real>
void Mathematics::ConvexPolygon2<Real>::UpdateLine(int index, const Vector2D& average)
{
    const auto& vertex0 = this->GetVertex(index);
    const auto& vertex1 = this->GetVertex((index + 1) % this->GetNumVertices());

    auto diff = average - vertex0;
    auto edge = vertex1 - vertex0;
    auto normal = Vector2DTools::GetPerp(-edge);
    auto length = Vector2DTools::VectorMagnitude(normal);
    if (Math::GetZeroTolerance() < length)
    {
        normal /= length;
        auto dot = Vector2DTools::DotProduct(normal, diff);
        MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= dot, "�������Ϊ�Ǹ���\n");
        if (dot < Math::GetValue(0))
        {
            normal = -normal;
        }
    }
    else
    {
        // ��Ե�˻���ʹ�á�normal��ָ��ƽ��ֵ����
        normal = diff;
        normal.Normalize();
    }

    // ���߾�����ָ��ķ��ߡ�
    m_Impl->UpdateLine(index, vertex0, normal);
}

template <typename Real>
bool Mathematics::ConvexPolygon2<Real>::IsUpdateLines() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsUpdateLines();
}

template <typename Real>
bool Mathematics::ConvexPolygon2<Real>::IsConvex(Real threshold) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(threshold <= Math::GetValue(0), "threshold����Ϊ��ֵ��");

    if (IsUpdateLines())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ҫ�����߶Ρ�\n"s));
    }

    auto maxDistance = -Math::sm_MaxReal;
    auto minDistance = Math::sm_MaxReal;

    for (const auto& line : *m_Impl)
    {
        for (auto i = 0; i < this->GetNumVertices(); ++i)
        {
            auto distance = Vector2DTools::DotProduct(line.GetOrigin(), this->GetVertex(i)) - line.DotProduct();
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
bool Mathematics::ConvexPolygon2<Real>::Contains(const typename Vector2D& point, Real threshold) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(threshold <= Math::GetValue(0), "threshold����Ϊ��ֵ��");

    if (IsUpdateLines())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ҫ�����߶Ρ�\n"s));
    }

    for (const auto& line : *m_Impl)
    {
        auto distance = Vector2DTools::DotProduct(line.GetOrigin(), point) - line.DotProduct();

        if (distance < threshold)
        {
            return false;
        }
    }

    return true;
}

#endif  // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_ACHIEVE_H
