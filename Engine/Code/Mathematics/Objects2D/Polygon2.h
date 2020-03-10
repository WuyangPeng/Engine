// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/06 11:12)

#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "CoreTools/MemoryTools/SmartPointer1DArrayDetail.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Polygon2
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Polygon2<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Vector2DPtr = CoreTools::SmartPointer1DArray<Vector2D>;
		
	public:
		// ���÷�����ȷ������������ʱ�룬����һ���򵥵Ķ���Ρ� 
		// ʹ�ù��������ָ��
		Polygon2 (int verticesNumber,Vector2DPtr verticesPtr);
		virtual ~Polygon2 ();	

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// ֻ����Ա���ʡ�
		int GetNumVertices () const;
		const Vector2DPtr GetVertices () const;
		const Vector2D& GetVertex (int index) const;

		// �������޸ġ������߱���ȷ���������Ȼ�Ǽ򵥶���Ρ�
		virtual void SetVertex (int index, const Vector2D& vertex);

		// ���������������εĸ�����Ϣ��
		const Vector2D ComputeVertexAverage () const;
		Real ComputePerimeterLength () const;
		Real ComputeArea () const;

	private:
		int m_VerticesNumber;
		Vector2DPtr m_Vertices;
	};

	using Polygon2f = Polygon2<float>;
	using Polygon2d = Polygon2<double>;
}

#endif // MATHEMATICS_OBJECTS2D_POLYGON2_H
