// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 16:45)

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

		// ��Line��ʾDot(N,X) = c��pair�ĵ�һ���ֱ�ʾ��λ����N�������ߡ�
		// pair�ĵڶ����ֱ�ʾ�ߵĳ���c��X�����ϵ�����㡣
		using Line = typename std::pair<Vector2D, Real>;
		using LinePtr = CoreTools::SmartPointer1DArray<Line>; 

	public:
		// ���÷�����ȷ�����������ʾ͹����Σ�����ʱ��˳��

		// Polygon2����ͨ���Ǵ�������Դ�������ݡ�����Ϊ����ָ���ࡣ		

		ConvexPolygon2(int verticesNumber, Vector2DPtr verticesPtr, LinePtr lines);
		virtual ~ConvexPolygon2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// ֻ����Ա���ʡ�
		const LinePtr GetLines() const;
		const Line& GetLine(int index) const;

		// �������޸ġ������߱���ȷ�����������͹����Ρ�
		// ֻҪ���޸ľ����ܶ�Ķ���󣬵���UpdateLines()��
		// ���о���SetVertex���޸ģ�UpdateLines���ߵĸ��£�ֻ���޸ĵĹ���Ķ���ı߽��С�
		 void SetVertex(int index, const Vector2D& vertex) override;
		void UpdateLines();
		bool IsUpdateLines() const;

		// �����Ƿ���͹����Ρ�
		// ��������������ö���εıߺ���֤ÿ���ߵĶ���εĶ��㶼�ڱ�Ե�ߵķǸ��ࡣ
		// ���ž������ʱ������һ��������һ���ߣ�����͹���ķ���ʱ��
		// ���з��ŵľ�������d < 0����ֵ���������������ȷ͹�Բ��ԣ�
		// ����һ��С�ĸ���ֵt����ͨ���ú�����
		// ����������£�������Ի���d < t < 0��
		bool IsConvex(Real threshold = -Math::sm_ZeroTolerance) const;

		// ���ڶ���εĲ��ԣ��ڵ�ͱ�Ե���ߣ���n������֮��ߵĲ�ѯִ�У�ΪO(n)�㷨��
		// �ⲻ�������㷨��TODO�������������㷨��������ࡣ����һ��O(log n)���㷨��
		bool Contains(const Vector2D& point, Real threshold = -Math::sm_ZeroTolerance) const;

	private:
		// ֧�ֵı�Ե�ߵĸ�Ч���¡�
		// set�洢��Щ�޸Ĺ�����ߵ�������
		void UpdateLine(int index, const Vector2D& average);

	private:
		using SharingType = std::set<int>;

	private:
		// �ߵ������Ƕ����������
		LinePtr m_Lines;

		// Ҫ��UpdateLine����Ĺ����
		SharingType m_SharingEdges;
	};

	using ConvexPolygon2f = ConvexPolygon2<float>;
	using ConvexPolygon2d = ConvexPolygon2<double>;
}

#endif // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H	
