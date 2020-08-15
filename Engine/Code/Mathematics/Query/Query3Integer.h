// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 09:52)

#ifndef MATHEMATICS_QUERY_QUERY3_INTEGER_H
#define MATHEMATICS_QUERY_QUERY3_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "Query3.h"

namespace Mathematics
{
	template <typename Real>
	class Query3Integer : public Query3<Real>
	{
	public:
		using ClassType = Query3Integer<Real>;
		using ParentType = Query3<Real>;
		using Vector3D = typename ParentType::Vector3D; 

	public:
		// ���붥�����ɲ��ֱ��ض�Ϊ32λ������
		// ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
		// ��Integer<N>��N��ֵ��ѡ���㹻���Ա�ȷ���ں�������������ȷ�ġ�
		explicit Query3Integer(const std::vector<Vector3D>& vertices);
		 ~Query3Integer();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// ����ʱ������Ϣ��
		 QueryType GetType() const override;

		 PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
		 PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;

		 CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const override;
		 CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const override;
	};

	using Query3Integerf = Query3Integer<float>;
	using Query3Integerd = Query3Integer<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_INTEGER_H

