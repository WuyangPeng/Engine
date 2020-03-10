// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 09:37)

#ifndef MATHEMATICS_QUERY_QUERY3_H
#define MATHEMATICS_QUERY_QUERY3_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Query3 : public QueryBase
	{
	public:
		using ClassType = Query3<Real>;
		using ParentType = QueryBase;
		using Vector3D = Vector3D<Real>;

	public:
		// ���ദ�����ѯ��
		explicit Query3(const std::vector<Vector3D>& vertices);
		virtual ~Query3();
 
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE; 

		virtual QueryType GetType() const override;

		int GetNumVertices() const;
		const Vector3D GetVertice(int index) const;

		// ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

		// ����:		
		// PlaneQueryType::PositiveSide, ��ƽ������� 
		// PlaneQueryType::NegativeSide, ��ƽ��ĸ��� 
		// PlaneQueryType::OnPlane, ��ƽ����
		virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const;
		virtual PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const;

		// ����:		
		// TetrahedronQueryType::Outside, ��������  
		// TetrahedronQueryType::Inside, ��������
		// TetrahedronQueryType::OnTetrahedron,����������
		virtual TetrahedronQueryType ToTetrahedron(int index, int v0,int v1, int v2, int v3) const;
		virtual TetrahedronQueryType ToTetrahedron(const Vector3D& testVector, int v0,int v1, int v2, int v3) const;

		// ����:
		// Returns:
		// CircumsphereQueryType::Outside, ����������������� 
		// CircumsphereQueryType::Inside,�����������������
		// CircumsphereQueryType::OnCircumsphere, �����������������
		virtual CircumsphereQueryType ToCircumsphere(int index, int v0,int v1, int v2, int v3) const;
		virtual CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0,int v1, int v2, int v3) const;

	private:
		// �����
		std::vector<Vector3D> m_Vertices;
	};

	using Query3f = Query3<float>;
	using Query3d = Query3<double>;
}

#endif // MATHEMATICS_QUERY_QUERY3_H
