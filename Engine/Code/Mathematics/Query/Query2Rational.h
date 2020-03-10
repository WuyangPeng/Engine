// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 09:36)

#ifndef MATHEMATICS_QUERY_QUERY2_RATIONAL_H
#define MATHEMATICS_QUERY_QUERY2_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"
#include "Mathematics/Rational/SignRational.h"
#include "Mathematics/Rational/RationalVector2.h"

namespace Mathematics
{
	template <typename Real>
	class Query2Rational : public Query2<Real>
	{
	public:
		using ClassType = Query2Rational<Real>;
		using ParentType = Query2<Real>;
		using typename ParentType::Vector2D;
		using ParentType::GetNumVertices;
		using ParentType::GetVertice;

	public:
		// 输入顶点的组成部分被表示完全相同有理数值。
		explicit Query2Rational(const std::vector<Vector2D>& vertices);
		virtual ~Query2Rational ();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual QueryType GetType() const override;
		
		// 关于一个点的各种几何对象之间的关系查询。

		virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
		virtual LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

		virtual TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        virtual TriangleQueryType ToTriangle(const Vector2D& testVector, int lhsVerticesIndex,  int mhsVerticesIndex, int rhsVerticesIndex) const override;

		virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
		virtual CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        

	private:		
		using QueryRational= SignRational<4 * sizeof(Real)>;
		using QueryRationalVector = RationalVector2<4 * sizeof(Real)>;

	private:
		void Convert ();
		LineQueryType ToLine(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int rhsVerticesIndex) const;
		TriangleQueryType ToTriangle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
		CircumcircleQueryType ToCircumcircle(const QueryRationalVector& rationalTest, int lhsVerticesIndex,  int mhsVerticesIndex, int rhsVerticesIndex) const;
		
	private:		
		// 缓存输入的有理数表示。浮点数的对有理数形式的转化是缓慢的，
		// 所以最好是跟踪哪些值已转换。
		// 现修改为构造时直接转换
		std::vector<QueryRationalVector> m_RationalVertices;
	};	

	using Query2Rationalf = Query2Rational<float>;
	using Query2Rationald = Query2Rational<double>;
}

#endif // MATHEMATICS_QUERY_QUERY2_RATIONAL_H
