// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:24)

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
		// 该四面体被表示为四个顶点的数组：V0，V1，V2和V3。
		// 顶点被排序，使得由四面体外的观察者观察时，
		// 三角形的面是被逆时针排序的三角形：
		//   面 0 = <V[0],V[2],V[1]>
		//   面 1 = <V[0],V[1],V[3]>
		//   面 2 = <V[0],V[3],V[2]>
		//   面 3 = <V[1],V[2],V[3]>

		Tetrahedron3(const Vector3D& fristVertex, const Vector3D& secondVertex,
					 const Vector3D& thirdVertex, const Vector3D& fourthVertex);

		Tetrahedron3(const std::vector<Vector3D> vertex);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetVertex(int index) const;
		void SetVertex(int index, const Vector3D& vertex);

		// 获取顶点索引在指定的面。
		static std::vector<int> GetFaceIndices(int face);

		// 构造四面体面的平面。
		// 该四面具有外部指向的法向量。
		// 平面索引是同前面的GetFaceIndices返回的索引相同。
		const std::vector<Plane3> GetPlanes() const;

	private:
		Vector3D m_Vertex[4];
	};

	using Tetrahedron3f = Tetrahedron3<float>;
	using Tetrahedron3d = Tetrahedron3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H
