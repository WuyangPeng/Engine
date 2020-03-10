// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/06 11:12)

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
		// 调用方负责确保顶点数组逆时针，代表一个简单的多边形。 
		// 使用共享的智能指针
		Polygon2 (int verticesNumber,Vector2DPtr verticesPtr);
		virtual ~Polygon2 ();	

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// 只读成员访问。
		int GetNumVertices () const;
		const Vector2DPtr GetVertices () const;
		const Vector2D& GetVertex (int index) const;

		// 允许顶点修改。调用者必须确保多边形仍然是简单多边形。
		virtual void SetVertex (int index, const Vector2D& vertex);

		// 计算关于所述多边形的各种信息。
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
