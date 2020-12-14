///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 16:23)

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
        using Vector3D = typename ParentType::Vector3D;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // ���ദ�����ѯ��ÿ����ѯ�漰����ʽ������бȽϡ�
        // ���������ʽ�㹻�ӽ��㣬��ֵ�������������ܻᵼ������ʽ���ű�������ࡣ
        // Ϊ�˱�������������ò�ѯ���ظ�ʹ��ȷ����������������
        // ��ͨ��'uncertainty'��ָ���ӽ��������[0, 1]��ֵ�л��������Ե�������
        // uncertaintyΪ0�ᵼ�������Ϊ�ͺ�������Query3��
        // uncertaintyΪ1�ᵼ�������Ϊ�ͺ�������Query3Rational��
        Query3Filtered(const VerticesType& vertices, Real uncertainty);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] QueryType GetType() const noexcept override;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        [[nodiscard]] PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
        [[nodiscard]] PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;

        [[nodiscard]] CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
        [[nodiscard]] CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;

    private:
        using Query3Rational = Query3Rational<Real>;

    private:
        Query3Rational m_RationalQuery;
        Real m_Uncertainty;
    };

    using FloatQuery3Filtered = Query3Filtered<float>;
    using DoubleQuery3Filtered = Query3Filtered<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_FILTERED_H
