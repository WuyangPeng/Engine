// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 13:55)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Vector2DInformation
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector2DInformation<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;
		using AxesAlignBoundingBox2D = AxesAlignBoundingBox2D<Real>;
		using AxesAlignBoundingBox2DPtr = std::shared_ptr<AxesAlignBoundingBox2D>;
	
	public:
		// ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
		Vector2DInformation(const std::vector<Vector2D>& points,Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;
		
		int GetDimension() const;
		AxesAlignBoundingBox2DPtr GetAABBPtr() const;
		Real GetMaxRange() const;
		const Vector2D GetOrigin() const;
		const Vector2D GetDirectionX() const;
		const Vector2D GetDirectionY() const;
		const Vector2D GetMinExtreme() const;
		const Vector2D GetMaxExtreme() const;
		const Vector2D GetPerpendicularExtreme() const;
		bool IsExtremeCCW() const;
		int GetMinExtremeIndex() const;
		int GetPerpendicularExtremeIndex() const;
		int GetMaxExtremeIndex() const;
		int GetIndexMin(int index) const;

	private:
		void Init();
		void ComputeAxisAlignedBoundingBox();
		void DetermineMaximumRange();
		bool TestPointSetIsNearlyAPoint();
		bool TestPointSetIsNearlyALineSegment();

	private:
		std::vector<Vector2D> m_Points;
		Real m_Epsilon;

		// ���뼯�Ĺ���ά�ȡ�
		// ���У�������epsilon��������ȷ���ߴ�ʱ�ṩ�ݲ 
		int m_Dimension;		

		// ���뼯��������Χ�С�
		// ���Χ��aabb.max.x - aabb.min.x �� aabb.max.y - aabb.min.y�����ֵ��
		AxesAlignBoundingBox2DPtr m_AABBPtr;		
		Real m_MaxRange;	

		// ����ϵ��ԭ���Ƕ��κ�ά��d����Ч��
		// ��λ���ȵķ�������ֻ������0 <= i < d��
		// ĩ�˵����������������ĵ�����飬����Ҳֻ������0 <= i < d��
		// ���d = 0�����еĵ�ʵ��������ͬ�ģ�
		// ��ʹ��һ��epsilon�Ŀ��ܻᵼ��ĩ�˵�������Ϊ�㡣
		// ���d = 1�����е��λ����һ���߶��ϡ�
		// ��d = 2ʱ�����е㲻���ߡ�
		Vector2D m_Origin;
		Vector2D m_DirectionX;
		Vector2D m_DirectionY;
	
		// �������ռ䷶Χ�������� 
		// ֵm_MinExtreme��m_MaxExtreme�����ڶ�������������������е�һ�����Χ����������
		// ���ά����2����m_PerpendicularExtreme��
		// ��ֱ����Ӧ��m_MinExtreme��m_MaxExtreme
		// ���Χ���ɵĵ��������
		// �ɵ�V[m_MinExtreme], V[m_MaxExtreme], 
		// �� V[m_PerpendicularExtreme]���γɵ������Σ�
		// ��˳ʱ�����ʱ�룬�洢��m_ExtremeCCW��
		int m_MinExtreme;
		int m_MaxExtreme;
		int m_PerpendicularExtreme;
		bool m_ExtremeCCW; // �Ƿ�����ʱ��

        // ��С�����������
        int m_IndexMin[2];
        int m_IndexMax[2];
	};	

	using Vector2DInformationf = Vector2DInformation<float>;
	using Vector2DInformationd = Vector2DInformation<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H
