// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 09:45)

#ifndef MATHEMATICS_QUERY_QUERY2_FILTERED_H
#define MATHEMATICS_QUERY_QUERY2_FILTERED_H 

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"
#include "Query2Rational.h"

namespace Mathematics
{
	template <typename Real>
	class Query2Filtered : public Query2<Real>
	{
	public:
		using ClassType = Query2Filtered<Real>;
		using ParentType = Query2<Real>;
		using Vector2D = typename ParentType::Vector2D;

	public:
		// ���ദ�����ѯ��ÿ����ѯ�漰����ʽ������бȽϡ�
		// ���������ʽ�㹻�ӽ��㣬��ֵ�������������ܻᵼ������ʽ���ű�������ࡣ
		// Ϊ�˱�������������ò�ѯ���ظ�ʹ��ȷ����������������
		// ��ͨ��'uncertainty'��ָ���ӽ��������[0, 1]��ֵ�л��������Ե�������
		// uncertaintyΪ0�ᵼ�������Ϊ�ͺ�������Query2��
		// uncertaintyΪ1�ᵼ�������Ϊ�ͺ�������Query2Rational��
		Query2Filtered(const std::vector<Vector2D>& vertices, Real uncertainty);
		virtual ~Query2Filtered();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual QueryType GetType() const override;

		// ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

		virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
		virtual LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

		virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
		virtual CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;

	private:
		using Query2Rational = Query2Rational<Real>;

	private:
		Query2Rational m_RationalQuery;
		Real m_Uncertainty;
	};

	using Query2Filteredf = Query2Filtered<float>;
	using Query2Filteredd = Query2Filtered<double>;
}

#endif // MATHEMATICS_QUERY_QUERY2_FILTERED_H
