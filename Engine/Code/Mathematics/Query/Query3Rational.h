///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 16:25)

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
        using Vector3D = typename ParentType::Vector3D;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // ���붥�����ɲ��ֱ���ʾ��ȫ��ͬ������ֵ��
        explicit Query3Rational(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ����ʱ������Ϣ��
        [[nodiscard]] QueryType GetType() const noexcept override;

        [[nodiscard]] PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
        [[nodiscard]] PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;

        [[nodiscard]] TetrahedronQueryType ToTetrahedron(int index, int v0, int v1, int v2, int v3) const override;
        [[nodiscard]] TetrahedronQueryType ToTetrahedron(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;

        [[nodiscard]] CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
        [[nodiscard]] CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;

    private:
        using QueryRational = SignRational<8 * sizeof(Real)>;
        using QueryRationalVector = RationalVector3<8 * sizeof(Real)>;
        using Container = std::vector<QueryRationalVector>;

    private:
        void Convert();
        [[nodiscard]] PlaneQueryType ToPlane(const QueryRationalVector& rationalTest, int v0, int v1, int v2) const;
        [[nodiscard]] TetrahedronQueryType ToTetrahedron(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const;
        [[nodiscard]] CircumsphereQueryType ToCircumsphere(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const;

    private:
        // �����������������ʾ���������Ķ���������ʽ��ת���ǻ����ģ� ��������Ǹ�����Щֵ��ת����
        Container m_RationalVertices;
    };

    using FloatQuery3Rational = Query3Rational<float>;
    using DoubleQuery3Rational = Query3Rational<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_RATIONAL_H
