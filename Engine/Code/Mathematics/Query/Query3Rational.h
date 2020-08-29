// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 09:52)

#ifndef MATHEMATICS_QUERY_QUERY3_RATIONAL_H
#define MATHEMATICS_QUERY_QUERY3_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Query3.h"
#include "Mathematics/Rational/SignRational.h"
#include "Mathematics/Rational/RationalVector3.h"

namespace Mathematics
{
	template <typename Real>
	class Query3Rational : public Query3<Real>
	{
	public:
		using ClassType = Query3Rational<Real>;
		using ParentType = Query3<Real>;
		using Vector3D = typename ParentType::Vector3D; 

	public:
		// ���붥�����ɲ��ֱ���ʾ��ȫ��ͬ������ֵ��
		explicit Query3Rational(const std::vector<Vector3D>& vertices);
		 ~Query3Rational();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// ����ʱ������Ϣ��
		 QueryType GetType() const override;

		 PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
		 PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;

		 TetrahedronQueryType ToTetrahedron(int index, int v0, int v1, int v2, int v3) const override;
		 TetrahedronQueryType ToTetrahedron(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;

		 CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
		 CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;

	private:
		using QueryRational = SignRational<8 * sizeof(Real)>;
		using QueryRationalVector = RationalVector3<8 * sizeof(Real)>;

	private:
		void Convert();
		PlaneQueryType ToPlane(const QueryRationalVector& rationalTest, int v0, int v1, int v2) const;
		TetrahedronQueryType ToTetrahedron(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const;
		CircumsphereQueryType ToCircumsphere(const QueryRationalVector& rationalTest, int v0, int v1, int v2, int v3) const;

	private:
		// �����������������ʾ���������Ķ���������ʽ��ת���ǻ����ģ�
		// ��������Ǹ�����Щֵ��ת����
		// ���޸�Ϊ����ʱֱ��ת��
		std::vector<QueryRationalVector> m_RationalVertices;
	};

	using Query3Rationalf = Query3Rational<float>;
	using Query3Rationald = Query3Rational<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_RATIONAL_H
