// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:23)

#ifndef MATHEMATICS_OBJECTS3D_PLANE3_H
#define MATHEMATICS_OBJECTS3D_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Objects3D/Triangle3.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Plane3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Plane3<Real>;
		using Vector3D = Vector3D<Real>;
		using Math = Math<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Triangle3 = Triangle3<Real>;

	public:
		// ƽ���ʾΪDot(N,X) = c��
		// ����N��һ����λ���ȵķ���������
		// c��ƽ�泣������X����ƽ���ϵ�����㡣
		// �û����뱣֤���ߵ������ǵ�λ����

		Plane3();

		// ֱ��ָ��N��C��
		Plane3(const Vector3D& normal, Real constant, const Real epsilon = Math::GetZeroTolerance());

		// ָ��N��c = Dot(N,P)������P��ƽ���ǵ�һ�㡣
		Plane3(const Vector3D& normal, const Vector3D& point, const Real epsilon = Math::GetZeroTolerance());

		// N = Cross(P1-P0,P2-P0)/Length(Cross(P1-P0,P2-P0))��
		// c = Dot(N,P0)������P0��P1��P2����ƽ���ϵĵ㡣
		Plane3(const Vector3D& firstPoint, const Vector3D& secondPoint, const Vector3D& thirdPoint, const Real epsilon = Math::GetZeroTolerance());

		explicit Plane3(const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetNormal() const;
		Real GetConstant() const;

		// ����d = Dot(N,P)-c ����N��ƽ�淨�ߺ�c��ƽ�泣����
		// ����һ�����ž��롣
		// �������ֵ�ķ��������ģ���õ�����ƽ���ϵ�������
		// ����Ǹ��ģ�����ƽ�渺����
		// ���Ϊ�㣬�����ƽ���ϡ�
		Real DistanceTo(const Vector3D& point) const;

		// ƽ��������Ƿ��ߵ����ڵİ�ռ䣬��������һ��ռ䡣
		// �������ص���ƽ�����һ�ࡣ
		NumericalValueSymbol WhichSide(const Vector3D& point) const;

	private:
		Vector3D m_Normal;
		Real m_Constant;

		Real m_Epsilon;
	};

	using Plane3f = Plane3<float>;
	using Plane3d = Plane3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_PLANE3_H
