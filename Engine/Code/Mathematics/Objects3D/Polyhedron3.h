// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:23)

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
		// �����߸���ȷ���������һ���򵥵Ķ�����
		// ����ά��������������ˣ������ཻ�����˽ṹ����
		// �������棬��������۲�ʱ������ʱ��˳��
		//
		// Polyhedron3����һ���������Դ�������ݡ�
		// �����ʹ������ָ�루SmartPointer1DArray�������������顣
		// �������ϣ����ɾ�����飬ʹ���Լ�������ָ������顣
		Polyhedron3(int numVertices, Vector3DPtr vertices, int numTriangles, IntPtr indices);
		virtual ~Polyhedron3();

	#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_VIRTUAL_DECLARE;
		bool IndicesIsValid() const noexcept;
	#endif // OPEN_CLASS_INVARIANT

		// ֻ����Ա���ʡ�
		int GetNumVertices() const;
		const Vector3DPtr GetVertices() const;
		const Vector3D& GetVertex(int index) const;
		int GetNumTriangles() const;
		int GetNumIndices() const;  // = 3 * numTriangles
		const IntPtr GetIndices() const;
		const int* GetTriangle(int index) const;

		// �������޸ġ������߱���ȷ����������Ȼ�Ǽ򵥶����塣
		virtual void SetVertex(int index, const Vector3D& vertex);

		// �����������������ĸ�����Ϣ��
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
