// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 09:41)

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
		using typename ParentType::Vector3D;
		using ParentType::GetNumVertices;
		using ParentType::GetVertice;

	public:
		// ���붥�����ɲ��ֱ��ض�Ϊ32λ������
		// ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
		// ��Integer<N>��N��ֵ��ѡ���㹻���Ա�ȷ���ں�������������ȷ�ġ�
		explicit Query3Integer(const std::vector<Vector3D>& vertices);
		virtual ~Query3Integer(); 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// ����ʱ������Ϣ��
		virtual QueryType GetType() const override; 

		virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
		virtual PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;
		
		virtual CircumsphereQueryType ToCircumsphere(int index, int v0,int v1, int v2, int v3) const override;
		virtual CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0,int v1, int v2, int v3) const override;
	};
	
	using Query3Integerf = Query3Integer<float>;
	using Query3Integerd = Query3Integer<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_INTEGER_H

 