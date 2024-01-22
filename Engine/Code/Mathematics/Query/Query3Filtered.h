/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:39)

#ifndef MATHEMATICS_QUERY_QUERY3_FILTERED_H
#define MATHEMATICS_QUERY_QUERY3_FILTERED_H

#include "Mathematics/MathematicsDll.h"

#include "Query3.h"
#include "Query3Rational.h"

namespace Mathematics
{
    template <typename Real>
    class Query3Filtered : public Query3<Real>
    {
    public:
        using ClassType = Query3Filtered<Real>;
        using ParentType = Query3<Real>;

        using Math = typename ParentType::Math;
        using Vector3 = typename ParentType::Vector3;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // 基类处理浮点查询。每个查询涉及行列式和零进行比较。
        // 如果该行列式足够接近零，数值四舍五入误差可能会导致行列式符号被错误分类。
        // 为了避免这种情况，该查询被重复使用确切有理数的算术。
        // 您通过'uncertainty'，指定接近零的区间[0, 1]的值切换到有理性的算术。
        // uncertainty为0会导致类的行为就好像它是Query3。
        // uncertainty为1会导致类的行为就好像它是Query3Rational。
        Query3Filtered(const VerticesType& vertices, Real uncertainty);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        // 关于一个点的各种几何对象之间的关系查询。

        NODISCARD PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
        NODISCARD PlaneQueryType ToPlane(const Vector3& testVector, int v0, int v1, int v2) const override;

        NODISCARD CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
        NODISCARD CircumsphereQueryType ToCircumsphere(const Vector3& testVector, int v0, int v1, int v2, int v3) const override;

    private:
        using Query3Rational = Query3Rational<Real>;

    private:
        Query3Rational rationalQuery;
        Real uncertainty;
    };

    using Query3FilteredF = Query3Filtered<float>;
    using Query3FilteredD = Query3Filtered<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_FILTERED_H
