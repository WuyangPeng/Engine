/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:39)

#ifndef MATHEMATICS_QUERY_QUERY3_RATIONAL_H
#define MATHEMATICS_QUERY_QUERY3_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Query3.h"
#include "Mathematics/Rational/RationalVector3.h"
#include "Mathematics/Rational/SignRational.h"

namespace Mathematics
{
    template <typename Real>
    class Query3Rational : public Query3<Real>
    {
    public:
        using ClassType = Query3Rational<Real>;
        using ParentType = Query3<Real>;

        using Math = typename ParentType::Math;
        using Vector3 = typename ParentType::Vector3;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // ���붥�����ɲ��ֱ���ʾ��ȫ��ͬ������ֵ��
        explicit Query3Rational(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ����ʱ������Ϣ��
        NODISCARD QueryType GetType() const noexcept override;

        NODISCARD PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
        NODISCARD PlaneQueryType ToPlane(const Vector3& testVector, int v0, int v1, int v2) const override;

        NODISCARD TetrahedronQueryType ToTetrahedron(int index, int v0, int v1, int v2, int v3) const override;
        NODISCARD TetrahedronQueryType ToTetrahedron(const Vector3& testVector, int v0, int v1, int v2, int v3) const override;

        NODISCARD CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
        NODISCARD CircumsphereQueryType ToCircumsphere(const Vector3& testVector, int v0, int v1, int v2, int v3) const override;

    private:
        using QueryRational = SignRational<8 * sizeof(Real)>;
        using QueryRationalVector = RationalVector3<8 * sizeof(Real)>;
        using Container = std::vector<QueryRationalVector>;

    private:
        void Convert();
        NODISCARD PlaneQueryType ToPlane(const QueryRationalVector& rationalTest, int v0, int v1, int v2) const;
        NODISCARD TetrahedronQueryType ToTetrahedron(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const;
        NODISCARD CircumsphereQueryType ToCircumsphere(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const;

    private:
        // �����������������ʾ���������Ķ���������ʽ��ת���ǻ����ģ� ��������Ǹ�����Щֵ��ת����
        Container rationalVertices;
    };

    using Query3RationalF = Query3Rational<float>;
    using Query3RationalD = Query3Rational<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_RATIONAL_H
