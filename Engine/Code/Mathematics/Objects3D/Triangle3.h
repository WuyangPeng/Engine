// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 09:18)

#ifndef MATHEMATICS_OBJECTS3D_TRIANGLE3_H
#define MATHEMATICS_OBJECTS3D_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits> 
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Triangle3
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Triangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		// �����α�ʾΪ�����������飺 
		Triangle3 (const Vector3D& firstVector, const Vector3D& secondVector,const Vector3D& thirdVector);

		CLASS_INVARIANT_DECLARE;

		// �ӵ�point�������εľ��롣
		Real DistanceTo (const Vector3D& point) const;

		const std::vector<Vector3D> GetVertex() const;
		const Vector3D GetVertex(int index) const;
		const std::vector<Vector3D> GetEdgeVectors() const;

		const Vector3D GetNormal() const;

	private:
		Vector3D m_Vertex[3];
	};

	using Triangle3f = Triangle3<float>;
	using Triangle3d = Triangle3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_TRIANGLE3_H
