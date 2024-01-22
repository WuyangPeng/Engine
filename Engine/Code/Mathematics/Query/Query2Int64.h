/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:37)

#ifndef MATHEMATICS_QUERY_QUERY2_INT64_H
#define MATHEMATICS_QUERY_QUERY2_INT64_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"

namespace Mathematics
{
    template <typename Real>
    class Query2Int64 : public Query2<Real>
    {
    public:
        using ClassType = Query2Int64<Real>;
        using ParentType = Query2<Real>;

        using Math = typename ParentType::Math;
        using Vector2 = typename ParentType::Vector2;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // ���붥�����ɲ��ֱ��ض�Ϊ64λ������
        // ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
        explicit Query2Int64(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ����ʱ������Ϣ��
        NODISCARD QueryType GetType() const noexcept override;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ�Ĳ�ѯ��
        NODISCARD LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD LineQueryType ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

        NODISCARD CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD CircumcircleQueryType ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
    };

    using Query2Int64F = Query2Int64<float>;
    using Query2Int64D = Query2Int64<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_INT64_H
