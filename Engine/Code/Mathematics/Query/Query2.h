/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:35)

#ifndef MATHEMATICS_QUERY_QUERY2_H
#define MATHEMATICS_QUERY_QUERY2_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Query2 : public QueryBase
    {
    public:
        using ClassType = Query2<Real>;
        using ParentType = QueryBase;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using VerticesType = std::vector<Vector2Type>;

    public:
        // ���ദ�����ѯ��
        explicit Query2(VerticesType vertices) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        NODISCARD int GetNumVertices() const;
        NODISCARD Vector2Type GetVertex(int index) const;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        // ����:
        //   LineQueryType::Right, ���ߵ��Ҳ�
        //   LineQueryType::Left, ���ߵ����
        //   LineQueryType::OnLine, ������
        NODISCARD virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual LineQueryType ToLine(const Vector2Type& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const;

        // ����:
        // TriangleQueryType::Outside, ����������
        // TriangleQueryType::Inside, ����������
        // TriangleQueryType::OnTriangle, ����������
        NODISCARD virtual TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual TriangleQueryType ToTriangle(const Vector2Type& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

        // ����:
        // CircumcircleQueryType::Outside,�������ε����Բ��
        // CircumcircleQueryType::Inside, �������ε����Բ��
        // CircumcircleQueryType::OnCircumcircle,�������ε����Բ��
        NODISCARD virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual CircumcircleQueryType ToCircumcircle(const Vector2Type& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

    private:
        // �����
        VerticesType vertices;
    };

    using Query2F = Query2<float>;
    using Query2D = Query2<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_H
