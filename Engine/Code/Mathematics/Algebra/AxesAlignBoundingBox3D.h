// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 10:26)

// ������Χ��3D�������
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class AxesAlignBoundingBox3D
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AxesAlignBoundingBox3D<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		explicit AxesAlignBoundingBox3D(const Vector3D& minPoint,const Vector3D& maxPoint);

		// �����߱���ȷ��xMin <= xMax �� yMin <= yMax��zMin <= zMax��
		AxesAlignBoundingBox3D (Real xMin, Real xMax, Real yMin, Real yMax,Real zMin, Real zMax);

		template <typename RhsType>
		AxesAlignBoundingBox3D(const AxesAlignBoundingBox3D<RhsType>& aabb);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetMinPoint() const; 
		const Vector3D GetMaxPoint() const;	

		// ������ӵ����ĵ�ͺ������ĵ����ӱ�Ե���뾶���ĳ��ȡ�
		const Vector3D GetCenter() const;
		Real GetExtentX() const;
		Real GetExtentY() const;
		Real GetExtentZ() const;

	private:
		void Recalculate();

	private:
		Vector3D m_MinPoint;
		Vector3D m_MaxPoint;
	};	

	// �ص��Ĳ��������ϸ������ϡ�
	// ������������ع����߸պýӴ������ӱ�����Ϊ�ص���
	template <typename Real>
	bool HasXOverlap (const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);

	template <typename Real>
	bool HasYOverlap (const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);

	template <typename Real>
	bool HasZOverlap (const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);

	template <typename Real>
	bool IsIntersection(const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);
	
	// ������ص�������������£����㱻���ء�
	// ���û���ص������׳��쳣
	template <typename Real>
	const AxesAlignBoundingBox3D<Real> FindIntersection (const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);

	using AxesAlignBoundingBox3Df = AxesAlignBoundingBox3D<float>;
	using AxesAlignBoundingBox3Dd = AxesAlignBoundingBox3D<double>;
}

#endif // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H