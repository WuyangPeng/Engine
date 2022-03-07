///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 16:22)

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
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using VerticesType = std::vector<Vector2>;

    public:
        // ���ദ�����ѯ��
        explicit Query2(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        NODISCARD int GetNumVertices() const;
        NODISCARD Vector2 GetVertice(int index) const;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        // ����:
        //   LineQueryType::Right, ���ߵ��Ҳ�
        //   LineQueryType::Left, ���ߵ����
        //   LineQueryType::OnLine, ������
        NODISCARD virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual LineQueryType ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const;

        // ����:
        // TriangleQueryType::Outside, ����������
        // TriangleQueryType::Inside, ����������
        // TriangleQueryType::OnTriangle, ����������
        NODISCARD virtual TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual TriangleQueryType ToTriangle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

        // ����:
        // CircumcircleQueryType::Outside,�������ε����Բ��
        // CircumcircleQueryType::Inside, �������ε����Բ��
        // CircumcircleQueryType::OnCircumcircle,�������ε����Բ��
        NODISCARD virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual CircumcircleQueryType ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

    private:
        // �����
        VerticesType vertices;
    };

    using Query2F = Query2<float>;
    using Query2D = Query2<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_H
