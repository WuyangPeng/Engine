// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:18)

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

		// ��Plane��ʾDot(N,X) = c��
		// N��ʾ��λ���������ƽ�档
		// c��ʾƽ��ĳ�����
		// X��ƽ���ϵ�����㡣	 
		using PlanePtr = CoreTools::SmartPointer1DArray<Plane3>;

		using IntPtr = ParentType::IntPtr;
		using Vector3D = ParentType::Vector3D;
		using Vector3DPtr = ParentType::Vector3DPtr;
		using Vector3DTools = ParentType::Vector3DTools;

	public:
		// �����߸���ȷ���������һ��͹�����塣
		// ����������۲�ʱ�������ε�����뱣����ʱ��˳��
		//		
		// Polyhedron3����һ���������Դ�������ݡ�
		// �����ʹ������ָ�루SmartPointer1DArray�������������顣
		// �������ϣ����ɾ�����飬ʹ���Լ�������ָ������顣
		//	
		// ConvexPolyhedron3�洢���������������ƽ�档
		// ƽ�淨����ָʾ��
		// ��ƽ����Ա����캯���ṩ������������£�����ָ�����ڹ������ǡ�
		// ������ǲ�ͨ���������ݣ���planes��Ϊnull�������Զ��������ǡ�
		ConvexPolyhedron3(int numVertices, Vector3DPtr vertices, int numTriangles, IntPtr indices, PlanePtr planes);
		virtual ~ConvexPolyhedron3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// ֻ����Ա���ʡ�
		const PlanePtr GetPlanes() const;
		const Plane3& GetPlane(int index) const;

		// �������޸ġ������߱���ȷ������������͹�����塣
		// ֻҪ���޸ľ����ܶ�Ķ���󣬵���UpdatePlanes()��
		// ���о���SetVertex���޸ģ�
		// UpdatePlanes����ĸ��£�ֻ���޸ĵĹ���Ķ���������ν��С�		
		virtual void SetVertex(int index, const Vector3D& vertex) override;
		void UpdatePlanes();
		bool IsUpdatePlanes() const;

		// ����͹�ԡ�
		// ��������������ö�����������֤ÿ����Ķ�����Ķ��㶼��ƽ��ķǸ��ࡣ
		// ���ž������ʱ������һ��������һ��ƽ�棨����͹���ķ���ʱ��
		// ���з��ŵľ�������d < 0����ֵ���������������ȷ͹�Բ��ԣ�
		// ����һ��С�ĸ���ֵt����ͨ���ú�����
		// ����������£�������Ի���d < t < 0��
		bool IsConvex(Real threshold = -Math::sm_ZeroTolerance) const;

		// ���ڶ�����Ĳ��ԣ��ڵ��ƽ����棬��n������֮���ѯִ�У�ΪO(n)�㷨��
		// �ⲻ�������㷨���ɽ�����BSP�㷨��������ࡣ����һ��O(log n)���㷨��
		bool Contains(const Vector3D& point, Real threshold = -Math::sm_ZeroTolerance) const;

	private:
		void InitPlanes();

		// ֧�ֵ�ƽ��ĸ�Ч���¡�
		// set�洢��Щ�޸Ĺ����������ε�������
		void UpdatePlane(int index, const Vector3D& average);

	private:
		// 	��������������ε�������
		PlanePtr m_Planes;

		// Ҫ��UpdatePlane����Ĺ���������
		std::set<int> m_SharingTriangles;
	};

	using ConvexPolyhedron3f = ConvexPolyhedron3<float>;
	using ConvexPolyhedron3d = ConvexPolyhedron3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_H
