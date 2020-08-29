// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 09:52)

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
		// 输入顶点的组成部分被表示完全相同有理数值。
		explicit Query3Rational(const std::vector<Vector3D>& vertices);
		 ~Query3Rational();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// 运行时类型信息。
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
		// 缓存输入的有理数表示。浮点数的对有理数形式的转化是缓慢的，
		// 所以最好是跟踪哪些值已转换。
		// 现修改为构造时直接转换
		std::vector<QueryRationalVector> m_RationalVertices;
	};

	using Query3Rationalf = Query3Rational<float>;
	using Query3Rationald = Query3Rational<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_RATIONAL_H
