///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:07)

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
        // ���붥�����ɲ��ֱ��ض�Ϊ64λ������
        // ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
        explicit Query3Int64(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ����ʱ������Ϣ��
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
