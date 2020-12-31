///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 16:24)

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
        // ���붥�����ɲ��ֱ��ض�Ϊ32λ������
        // ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
        // ��Integer<N>��N��ֵ��ѡ���㹻���Ա�ȷ���ں�������������ȷ�ġ�
        explicit Query3Integer(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ����ʱ������Ϣ��
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
