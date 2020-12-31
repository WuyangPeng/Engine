///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 13:18)

#ifndef MATHEMATICS_QUERY_QUERY2_H
#define MATHEMATICS_QUERY_QUERY2_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector2D.h"

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
        using Vector2D = Vector2D<Real>;
        using VerticesType = std::vector<Vector2D>;

    public:
        // ���ദ�����ѯ��
        explicit Query2(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] QueryType GetType() const noexcept override;

        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const Vector2D GetVertice(int index) const;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        // ����:
        //   LineQueryType::Right, ���ߵ��Ҳ�
        //   LineQueryType::Left, ���ߵ����
        //   LineQueryType::OnLine, ������
        [[nodiscard]] virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const;
        [[nodiscard]] virtual LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const;

        // ����:
        // TriangleQueryType::Outside, ����������
        // TriangleQueryType::Inside, ����������
        // TriangleQueryType::OnTriangle, ����������
        [[nodiscard]] virtual TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        [[nodiscard]] virtual TriangleQueryType ToTriangle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

        // ����:
        // CircumcircleQueryType::Outside,�������ε����Բ��
        // CircumcircleQueryType::Inside, �������ε����Բ��
        // CircumcircleQueryType::OnCircumcircle,�������ε����Բ��
        [[nodiscard]] virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        [[nodiscard]] virtual CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

    private:
        // �����
        VerticesType m_Vertices;
    };

    using FloatQuery2 = Query2<float>;
    using DoubleQuery2 = Query2<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_H
