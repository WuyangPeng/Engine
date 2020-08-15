// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 16:45)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Polygon2.h"
#include "Mathematics/Algebra/Vector2D.h"

#include <set>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class ConvexPolygon2 : public Polygon2<Real>
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = ConvexPolygon2<Real>;
		using ParentType = Polygon2<Real>;
		using Math = Math<Real>; 

		using Vector2D = ParentType::Vector2D;
		using Vector2DPtr = ParentType::Vector2DPtr;
		using Vector2DTools = ParentType::Vector2DTools;

		// 该Line表示Dot(N,X) = c。pair的第一部分表示单位法线N在这条线。
		// pair的第二部分表示线的常量c。X是线上的任意点。
		using Line = typename std::pair<Vector2D, Real>;
		using LinePtr = CoreTools::SmartPointer1DArray<Line>; 

	public:
		// 调用方负责确保顶点数组表示凸多边形，且逆时针顺序。

		// Polygon2对象通常是从其他来源共享数据。输入为智能指针类。		

		ConvexPolygon2(int verticesNumber, Vector2DPtr verticesPtr, LinePtr lines);
		virtual ~ConvexPolygon2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// 只读成员访问。
		const LinePtr GetLines() const;
		const Line& GetLine(int index) const;

		// 允许顶点修改。调用者必须确保多边形仍是凸多边形。
		// 只要你修改尽可能多的顶点后，调用UpdateLines()。
		// 所有经由SetVertex的修改，UpdateLines中线的更新，只在修改的共享的顶点的边进行。
		 void SetVertex(int index, const Vector2D& vertex) override;
		void UpdateLines();
		bool IsUpdateLines() const;

		// 测试是否是凸多边形。
		// 这个函数将遍历该多边形的边和验证每个边的多边形的顶点都在边缘线的非负侧。
		// 符号距离测试时，这样一个顶点是一条线（用于凸）的反面时，
		// 其有符号的距离满足d < 0，数值舍入误差会产生不正确凸性测试，
		// 所以一个小的负阈值t可能通过该函数，
		// 在这种情况下，距离测试会变成d < t < 0。
		bool IsConvex(Real threshold = -Math::sm_ZeroTolerance) const;

		// 点在多边形的测试，在点和边缘的线，在n个顶点之间边的查询执行，为O(n)算法。
		// 这不是最优算法。TODO：将二分搜索算法用于这个类。这是一个O(log n)的算法。
		bool Contains(const Vector2D& point, Real threshold = -Math::sm_ZeroTolerance) const;

	private:
		// 支持的边缘线的高效更新。
		// set存储那些修改共享顶点边的索引。
		void UpdateLine(int index, const Vector2D& average);

	private:
		using SharingType = std::set<int>;

	private:
		// 线的数量是顶点的数量。
		LinePtr m_Lines;

		// 要在UpdateLine处理的共享边
		SharingType m_SharingEdges;
	};

	using ConvexPolygon2f = ConvexPolygon2<float>;
	using ConvexPolygon2d = ConvexPolygon2<double>;
}

#endif // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H	
