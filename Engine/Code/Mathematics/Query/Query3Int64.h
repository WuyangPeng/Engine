// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 09:39)

#ifndef MATHEMATICS_QUERY_QUERY3_INT64_H
#define MATHEMATICS_QUERY_QUERY3_INT64_H

#include "Mathematics/MathematicsDll.h"

#include "Query3.h"

namespace Mathematics
{
	template <typename Real>
	class Query3Int64 : public Query3<Real>
	{
	public:
		using ClassType = Query3Int64<Real>;
		using ParentType = Query3<Real>;
		using typename ParentType::Vector3D;
		using ParentType::GetNumVertices;
		using ParentType::GetVertice;

	public:
		// ���붥�����ɲ��ֱ��ض�Ϊ64λ������
		// ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
		explicit Query3Int64(const std::vector<Vector3D>& vertices);
		virtual ~Query3Int64(); 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// ����ʱ������Ϣ��
		virtual QueryType GetType() const override; 

		virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const override;
		virtual PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const override;
		
		virtual CircumsphereQueryType ToCircumsphere(int index, int v0,int v1, int v2, int v3) const override;
		virtual CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0,int v1, int v2, int v3) const override;
	};

	using Query3Int64f = Query3Int64<float>;
	using Query3Int64d = Query3Int64<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_INT64_H
