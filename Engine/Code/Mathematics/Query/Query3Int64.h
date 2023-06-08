///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:07)

#ifndef MATHEMATICS_QUERY_QUERY3_INT64_H
#define MATHEMATICS_QUERY_QUERY3_INT64_H

#include "Mathematics/MathematicsDll.h"

#include "Query3.h"

namespace Mathematics
{
    template <typename Real>
    class Query3Int64 : public Query3<Real>
    {
    public:
        using ClassType = Query3Int64<Real>;
        using ParentType = Query3<Real>;
        using Math = typename ParentType::Math;
        using Vector3 = typename ParentType::Vector3;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // 输入顶点的组成部分被截断为64位整数，
        // 所以你应该确保顶点是足够大的分配好的数值。
        explicit Query3Int64(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 运行时类型信息。
        NODISCARD QueryType GetType() const noexcept override;

        NODISCARD PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
        NODISCARD PlaneQueryType ToPlane(const Vector3& testVector, int v0, int v1, int v2) const override;

        NODISCARD CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
        NODISCARD CircumsphereQueryType ToCircumsphere(const Vector3& testVector, int v0, int v1, int v2, int v3) const override;
    };

    using Query3Int64F = Query3Int64<float>;
    using Query3Int64D = Query3Int64<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_INT64_H
