// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 10:23)

// ������Χ��2D�������
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2D.h"

namespace Mathematics
{
	template <typename Real>
	class AxesAlignBoundingBox2D
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AxesAlignBoundingBox2D<Real>;
		using Vector2D = Vector2D<Real>;

	public:
		AxesAlignBoundingBox2D(const Vector2D& minPoint,const Vector2D& maxPoint);

		template <typename RhsType>
		AxesAlignBoundingBox2D(const AxesAlignBoundingBox2D<RhsType>& aabb);

		// �����߱���ȷ��xMin <= xMax �� yMin <= yMax��
		AxesAlignBoundingBox2D (Real xMin, Real xMax, Real yMin, Real yMax);

		CLASS_INVARIANT_DECLARE;

		const Vector2D GetMinPoint() const; 
		const Vector2D GetMaxPoint() const;	
		
		// ������ӵ����ĵ�ͺ������ĵ����ӱ�Ե���뾶���ĳ��ȡ�
		const Vector2D GetCenter() const;
		Real GetExtentX() const;
		Real GetExtentY() const;		

	private:
		void Recalculate();

	private:
		Vector2D m_MinPoint;
		Vector2D m_MaxPoint;
	};	
		
	// �ص��Ĳ��������ϸ������ϡ�
	// ������������ع����߸պýӴ������ӱ�����Ϊ�ص���
	template <typename Real>
	bool HasXOverlap (const AxesAlignBoundingBox2D<Real>& lhs,const AxesAlignBoundingBox2D<Real>& rhs);

	template <typename Real>
	bool HasYOverlap (const AxesAlignBoundingBox2D<Real>& lhs,const AxesAlignBoundingBox2D<Real>& rhs);

	template <typename Real>
	bool IsIntersection(const AxesAlignBoundingBox2D<Real>& lhs,const AxesAlignBoundingBox2D<Real>& rhs);
	
	// ������ص�������������£����㱻���ء�
	// ���û���ص������׳��쳣
	template <typename Real>
	const AxesAlignBoundingBox2D<Real> FindIntersection (const AxesAlignBoundingBox2D<Real>& lhs,const AxesAlignBoundingBox2D<Real>& rhs);

	typedef AxesAlignBoundingBox2D<float> AxesAlignBoundingBox2Df;
	typedef AxesAlignBoundingBox2D<double> AxesAlignBoundingBox2Dd;
}

#endif // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H