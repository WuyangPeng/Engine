// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:23)

#ifndef MATHEMATICS_OBJECTS3D_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS3D_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "CoreTools/MemoryTools/SmartPointer1DArrayDetail.h"

#include <vector>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Polyhedron3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Polyhedron3<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;
		using Vector3DPtr = CoreTools::SmartPointer1DArray<Vector3D>;
		using IntPtr = CoreTools::SmartPointer1DArray<int>;
		using Vector3DTools = Vector3DTools<Real>;

	public:
		// 调用者负责确保网格代表一个简单的多面体
		// （二维流形与球体的拓扑，非自相交的拓扑结构）。
		// 三角形面，从网格外观察时必须逆时针顺序。
		//
		// Polyhedron3对象一般从其他来源共享数据。
		// 这个类使用智能指针（SmartPointer1DArray）共享输入数组。
		// 如果您不希望类删除数组，使用自己的智能指针的数组。
		Polyhedron3(int numVertices, Vector3DPtr vertices, int numTriangles, IntPtr indices);
		virtual ~Polyhedron3();

	#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_VIRTUAL_DECLARE;
		bool IndicesIsValid() const noexcept;
	#endif // OPEN_CLASS_INVARIANT

		// 只读成员访问。
		int GetNumVertices() const;
		const Vector3DPtr GetVertices() const;
		const Vector3D& GetVertex(int index) const;
		int GetNumTriangles() const;
		int GetNumIndices() const;  // = 3 * numTriangles
		const IntPtr GetIndices() const;
		const int* GetTriangle(int index) const;

		// 允许顶点修改。调用者必须确保多面体仍然是简单多面体。
		virtual void SetVertex(int index, const Vector3D& vertex);

		// 计算关于所述多面体的各种信息。
		const Vector3D ComputeVertexAverage() const;
		Real ComputeSurfaceArea() const;
		Real ComputeVolume() const;

	private:
		int m_NumVertices;
		Vector3DPtr m_Vertices;
		int m_NumTriangles;
		int m_NumIndices;
		IntPtr m_Indices;
	};

	using Polyhedron3f = Polyhedron3<float>;
	using Polyhedron3d = Polyhedron3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_POLYHEDRON3_H
