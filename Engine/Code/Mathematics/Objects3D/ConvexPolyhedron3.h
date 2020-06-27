// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:18)

#ifndef MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Polyhedron3.h"
#include "Plane3.h"
#include "Mathematics/Base/Math.h"

#include <type_traits> 
#include <set>

namespace Mathematics
{
	template <typename Real>
	class ConvexPolyhedron3 : public Polyhedron3<Real>
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = ConvexPolyhedron3<Real>;
		using ParentType = Polyhedron3<Real>;
		using Math = Math<Real>;
		using Plane3 = Plane3<Real>;

		// 该Plane表示Dot(N,X) = c。
		// N表示单位法线在这个平面。
		// c表示平面的常量。
		// X是平面上的任意点。	 
		using PlanePtr = CoreTools::SmartPointer1DArray<Plane3>;

		using IntPtr = ParentType::IntPtr;
		using Vector3D = ParentType::Vector3D;
		using Vector3DPtr = ParentType::Vector3DPtr;
		using Vector3DTools = ParentType::Vector3DTools;

	public:
		// 调用者负责确保网格代表一个凸多面体。
		// 从网格外面观察时，三角形的面必须保持逆时针顺序。
		//		
		// Polyhedron3对象一般从其他来源共享数据。
		// 这个类使用智能指针（SmartPointer1DArray）共享输入数组。
		// 如果您不希望类删除数组，使用自己的智能指针的数组。
		//	
		// ConvexPolyhedron3存储与所述面相关联的平面。
		// 平面法线内指示。
		// 该平面可以被构造函数提供，在这种情况下，智能指针用于共享它们。
		// 如果他们不通过参数传递（“planes”为null），类自动生成它们。
		ConvexPolyhedron3(int numVertices, Vector3DPtr vertices, int numTriangles, IntPtr indices, PlanePtr planes);
		virtual ~ConvexPolyhedron3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// 只读成员访问。
		const PlanePtr GetPlanes() const;
		const Plane3& GetPlane(int index) const;

		// 允许顶点修改。调用者必须确保多面体仍是凸多面体。
		// 只要你修改尽可能多的顶点后，调用UpdatePlanes()。
		// 所有经由SetVertex的修改，
		// UpdatePlanes中面的更新，只在修改的共享的顶点的三角形进行。		
		virtual void SetVertex(int index, const Vector3D& vertex) override;
		void UpdatePlanes();
		bool IsUpdatePlanes() const;

		// 测试凸性。
		// 这个函数将遍历该多面体的面和验证每个面的多面体的顶点都在平面的非负侧。
		// 符号距离测试时，这样一个顶点是一条平面（用于凸）的反面时，
		// 其有符号的距离满足d < 0，数值舍入误差会产生不正确凸性测试，
		// 所以一个小的负阈值t可能通过该函数，
		// 在这种情况下，距离测试会变成d < t < 0。
		bool IsConvex(Real threshold = -Math::sm_ZeroTolerance) const;

		// 点在多面体的测试，在点和平面的面，在n个顶点之间查询执行，为O(n)算法。
		// 这不是最优算法。可将基本BSP算法用于这个类。这是一个O(log n)的算法。
		bool Contains(const Vector3D& point, Real threshold = -Math::sm_ZeroTolerance) const;

	private:
		void InitPlanes();

		// 支持的平面的高效更新。
		// set存储那些修改共享顶点三角形的索引。
		void UpdatePlane(int index, const Vector3D& average);

	private:
		// 	面的数量是三角形的数量。
		PlanePtr m_Planes;

		// 要在UpdatePlane处理的共享三角形
		std::set<int> m_SharingTriangles;
	};

	using ConvexPolyhedron3f = ConvexPolyhedron3<float>;
	using ConvexPolyhedron3d = ConvexPolyhedron3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_H
