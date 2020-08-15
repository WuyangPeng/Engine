// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 09:46)

#ifndef MATHEMATICS_QUERY_QUERY2_INTEGER_H
#define MATHEMATICS_QUERY_QUERY2_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"
#include "Mathematics/Rational/Integer.h"

namespace Mathematics
{
	template <typename Real>
	class Query2Integer : public Query2<Real>
	{
	public:
		using ClassType = Query2Integer<Real>;
		using ParentType = Query2<Real>;
		using Vector2D = typename ParentType::Vector2D; 

	public:

		// ���붥�����ɲ��ֱ��ض�Ϊ32λ������
		// ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
		// ��Integer<N>��N��ֵ��ѡ���㹻���Ա�ȷ���ں�������������ȷ�ġ�
		explicit Query2Integer(const std::vector<Vector2D>& vertices);
		 ~Query2Integer();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		 QueryType GetType() const override;

		// ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ�Ĳ�ѯ��
		 LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
		 LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

		 CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
		 CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;

	};

	using Query2Integerf = Query2Integer<float>;
	using Query2Integerd = Query2Integer<double>;
}

#endif // MATHEMATICS_QUERY_QUERY2_INTEGER_H
