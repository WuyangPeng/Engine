// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:24)

#ifndef MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H
#define MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Plane3.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Tetrahedron3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Tetrahedron3<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;

	public:
		// �������屻��ʾΪ�ĸ���������飺V0��V1��V2��V3��
		// ���㱻����ʹ������������Ĺ۲��߹۲�ʱ��
		// �����ε����Ǳ���ʱ������������Σ�
		//   �� 0 = <V[0],V[2],V[1]>
		//   �� 1 = <V[0],V[1],V[3]>
		//   �� 2 = <V[0],V[3],V[2]>
		//   �� 3 = <V[1],V[2],V[3]>

		Tetrahedron3(const Vector3D& fristVertex, const Vector3D& secondVertex,
					 const Vector3D& thirdVertex, const Vector3D& fourthVertex);

		Tetrahedron3(const std::vector<Vector3D> vertex);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetVertex(int index) const;
		void SetVertex(int index, const Vector3D& vertex);

		// ��ȡ����������ָ�����档
		static std::vector<int> GetFaceIndices(int face);

		// �������������ƽ�档
		// ����������ⲿָ��ķ�������
		// ƽ��������ͬǰ���GetFaceIndices���ص�������ͬ��
		const std::vector<Plane3> GetPlanes() const;

	private:
		Vector3D m_Vertex[4];
	};

	using Tetrahedron3f = Tetrahedron3<float>;
	using Tetrahedron3d = Tetrahedron3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H
