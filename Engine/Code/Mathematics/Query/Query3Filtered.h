/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:39)

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
        // ���ദ�����ѯ��ÿ����ѯ�漰����ʽ������бȽϡ�
        // ���������ʽ�㹻�ӽ��㣬��ֵ�������������ܻᵼ������ʽ���ű�������ࡣ
        // Ϊ�˱�������������ò�ѯ���ظ�ʹ��ȷ����������������
        // ��ͨ��'uncertainty'��ָ���ӽ��������[0, 1]��ֵ�л��������Ե�������
        // uncertaintyΪ0�ᵼ�������Ϊ�ͺ�������Query3��
        // uncertaintyΪ1�ᵼ�������Ϊ�ͺ�������Query3Rational��
        Query3Filtered(const VerticesType& vertices, Real uncertainty);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

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
