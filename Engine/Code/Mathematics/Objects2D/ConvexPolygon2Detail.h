///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 15:18)

#ifndef MATHEMATICS_OBJECTS_2D_CONVEX_POLYGON2_DETAIL_H
#define MATHEMATICS_OBJECTS_2D_CONVEX_POLYGON2_DETAIL_H

#include "ConvexPolygon2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector2Tools.h"

template <typename Real>
Mathematics::ConvexPolygon2<Real>::ConvexPolygon2(const VerticesType& vertices, const LineType& lines)
    : ParentType{ vertices }, lines{ lines }, sharingEdges{}
{
    if (vertices.size() != lines.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�߶κͶ���Ĵ�С����ȡ�\n"s));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ConvexPolygon2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::ConvexPolygon2<Real>::LineType Mathematics::ConvexPolygon2<Real>::GetLines() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (IsUpdateLines())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ҫ�����߶Ρ�\n"s))
    }

    return lines;
}

template <typename Real>
const Mathematics::Line2<Real>& Mathematics::ConvexPolygon2<Real>::GetLine(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (IsUpdateLines())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ҫ�����߶Ρ�\n"s))
    }

    return lines.at(index);
}

template <typename Real>
void Mathematics::ConvexPolygon2<Real>::SetVertex(int index, const Vector2& vertex)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    ParentType::SetVertex(index, vertex);

    // �����������Ĺ���ߡ�
    // ��Щ�߻����Ժ���¡�
    // ��������������ı�i��E[i] = <V[i],V[i+1]> �� E[i-1] = <V[i-1],V[i]>��
    // ����i+1 �� i-1������Ϊ��������ģ��
    const auto previous = index - 1;
    sharingEdges.insert(previous % lines.size());
    sharingEdges.insert(index);
}

template <typename Real>
void Mathematics::ConvexPolygon2<Real>::UpdateLines()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (IsUpdateLines())
    {
        const auto average = this->ComputeVertexAverage();
        for (auto i = 0; i < this->GetNumVertices(); ++i)
        {
            UpdateLine(i, average);
        }

        sharingEdges.clear();
    }
}

// private
template <typename Real>
void Mathematics::ConvexPolygon2<Real>::UpdateLine(int index, const Vector2& average)
{
    const auto& vertex0 = this->GetVertex(index);
    const auto& vertex1 = this->GetVertex((index + 1) % this->GetNumVertices());

    auto diff = average - vertex0;
    auto edge = vertex1 - vertex0;
    auto normal = Vector2Tools::GetPerp(-edge);
    auto length = Vector2Tools::GetLength(normal);
    if (Math::GetZeroTolerance() < length)
    {
        normal /= length;
        auto dot = Vector2Tools::DotProduct(normal, diff);
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
    auto& line = lines.at(index);

    line.SetOrigin(vertex0);
    line.SetDirection(normal);
}

template <typename Real>
bool Mathematics::ConvexPolygon2<Real>::IsUpdateLines() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return !sharingEdges.empty();
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

    auto maxDistance = -Math::maxReal;
    auto minDistance = Math::maxReal;

    for (const auto& line : lines)
    {
        for (auto i = 0; i < this->GetNumVertices(); ++i)
        {
            auto distance = Vector2Tools::DotProduct(line.GetOrigin(), this->GetVertex(i)) - line.DotProduct();
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
bool Mathematics::ConvexPolygon2<Real>::Contains(const typename Vector2& point, Real threshold) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(threshold <= Math::GetValue(0), "threshold����Ϊ��ֵ��");

    if (IsUpdateLines())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ҫ�����߶Ρ�\n"s));
    }

    for (const auto& line : lines)
    {
        auto distance = Vector2Tools::DotProduct(line.GetOrigin(), point) - line.DotProduct();

        if (distance < threshold)
        {
            return false;
        }
    }

    return true;
}

#endif  // MATHEMATICS_OBJECTS_2D_CONVEX_POLYGON2_DETAIL_H
