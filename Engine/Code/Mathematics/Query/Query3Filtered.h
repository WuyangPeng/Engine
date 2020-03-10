// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 09:38)

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
		using typename ParentType::Vector3D;
		using ParentType::GetNumVertices;
		using ParentType::GetVertice;

	public:
		// ���ദ�����ѯ��ÿ����ѯ�漰����ʽ������бȽϡ�
		// ���������ʽ�㹻�ӽ��㣬��ֵ�������������ܻᵼ������ʽ���ű�������ࡣ
		// Ϊ�˱�������������ò�ѯ���ظ�ʹ��ȷ����������������
		// ��ͨ��'uncertainty'��ָ���ӽ��������[0, 1]��ֵ�л��������Ե�������
		// uncertaintyΪ0�ᵼ�������Ϊ�ͺ�������Query3��
		// uncertaintyΪ1�ᵼ�������Ϊ�ͺ�������Query3Rational��
		Query3Filtered(const std::vector<Vector3D>& vertices, Real uncertainty);
		virtual ~Query3Filtered();
 
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE; 

		virtual QueryType GetType() const override;

		// ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

		virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
		virtual PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;
		
		virtual CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
		virtual CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;

	private:
		using Query3Rational =  Query3Rational<Real>;

	private:
		Query3Rational m_RationalQuery;
		Real m_Uncertainty;
	};

	using Query3Filteredf = Query3Filtered<float>;
	using Query3Filteredd = Query3Filtered<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_FILTERED_H


 
