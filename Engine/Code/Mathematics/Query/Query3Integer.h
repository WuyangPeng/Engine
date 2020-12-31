///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 16:24)

#ifndef MATHEMATICS_QUERY_QUERY3_INTEGER_H
#define MATHEMATICS_QUERY_QUERY3_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "Query3.h"

namespace Mathematics
{
    template <typename Real>
    class Query3Integer : public Query3<Real>
    {
    public:
        using ClassType = Query3Integer<Real>;
        using ParentType = Query3<Real>;
        using Math = typename ParentType::Math;
        using Vector3D = typename ParentType::Vector3D;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // 输入顶点的组成部分被截断为32位整数，
        // 所以你应该确保顶点是足够大的分配好的数值。
        // 在Integer<N>的N的值被选择足够大，以便确保在函数中算术是正确的。
        explicit Query3Integer(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 运行时类型信息。
        [[nodiscard]] QueryType GetType() const noexcept override;

        [[nodiscard]] PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
        [[nodiscard]] PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;

        [[nodiscard]] CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
        [[nodiscard]] CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;
    };

    using FloatQuery3Integer = Query3Integer<float>;
    using DoubleQuery3Integer = Query3Integer<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_INTEGER_H
