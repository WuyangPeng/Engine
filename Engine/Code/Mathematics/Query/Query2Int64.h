// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 09:45)

#ifndef MATHEMATICS_QUERY_QUERY2_INT64_H
#define MATHEMATICS_QUERY_QUERY2_INT64_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"

namespace Mathematics
{
	template <typename Real>
	class Query2Int64 : public Query2<Real>
	{
	public:
		using ClassType = Query2Int64<Real>;
		using ParentType = Query2<Real>;
		using Vector2D = typename ParentType::Vector2D;

	public:
		// ���붥�����ɲ��ֱ��ض�Ϊ64λ������
		// ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
		explicit Query2Int64(const std::vector<Vector2D>& vertices);
		 ~Query2Int64();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// ����ʱ������Ϣ��
		 QueryType GetType() const override;

		// ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ�Ĳ�ѯ��		
		 LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
		 LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

		 CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
		 CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
	};

	using Query2Int64f = Query2Int64<float>;
	using Query2Int64d = Query2Int64<double>;
}

#endif // MATHEMATICS_QUERY_QUERY2_INT64_H
