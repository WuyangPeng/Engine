// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 09:49)

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
		using Vector3D = typename ParentType::Vector3D;

	public:
		// ���ദ�����ѯ��ÿ����ѯ�漰����ʽ������бȽϡ�
		// ���������ʽ�㹻�ӽ��㣬��ֵ�������������ܻᵼ������ʽ���ű�������ࡣ
		// Ϊ�˱�������������ò�ѯ���ظ�ʹ��ȷ����������������
		// ��ͨ��'uncertainty'��ָ���ӽ��������[0, 1]��ֵ�л��������Ե�������
		// uncertaintyΪ0�ᵼ�������Ϊ�ͺ�������Query3��
		// uncertaintyΪ1�ᵼ�������Ϊ�ͺ�������Query3Rational��
		Query3Filtered(const std::vector<Vector3D>& vertices, Real uncertainty);
		 ~Query3Filtered();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		 QueryType GetType() const override;

		// ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

		 PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
		 PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;

		 CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
		 CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;

	private:
		using Query3Rational = Query3Rational<Real>;

	private:
		Query3Rational m_RationalQuery;
		Real m_Uncertainty;
	};

	using Query3Filteredf = Query3Filtered<float>;
	using Query3Filteredd = Query3Filtered<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_FILTERED_H



