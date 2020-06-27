// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 10:17)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Vector3DInformation
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector3DInformation<Real>;
		using Vector3D = Vector3D<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;
		using AxesAlignBoundingBox3D = AxesAlignBoundingBox3D<Real>;
		using AxesAlignBoundingBox3DPtr = std::shared_ptr<AxesAlignBoundingBox3D>;

	public:
		// ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
		Vector3DInformation(const std::vector<Vector3D>& points, Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		int GetDimension() const;
		AxesAlignBoundingBox3DPtr GetAABBPtr() const;
		Real GetMaxRange() const;
		const Vector3D GetOrigin() const;
		const Vector3D GetDirectionX() const;
		const Vector3D GetDirectionY() const;
		const Vector3D GetDirectionZ() const;
		const Vector3D GetMinExtreme() const;
		const Vector3D GetMaxExtreme() const;
		const Vector3D GetPerpendicularExtreme() const;
		const Vector3D GetTetrahedronExtreme() const;
		bool IsExtremeCCW() const;

		int GetMinExtremeIndex() const;
		int GetMaxExtremeIndex() const;
		int GetPerpendicularExtremeIndex() const;
		int GetTetrahedronExtremeIndex() const;

	private:
		void Init();
		void ComputeAxisAlignedBoundingBox();
		void DetermineMaximumRange();
		bool TestPointSetIsNearlyAPoint();
		bool TestPointSetIsNearlyALineSegment();
		bool TestPointSetIsNearlyAPlanarPolygon();

	private:
		std::vector<Vector3D> m_Points;
		Real m_Epsilon;

		// ���뼯�Ĺ���ά�ȡ�
		// ���У�������epsilon��������ȷ���ߴ�ʱ�ṩ�ݲ 
		int m_Dimension;

		// ���뼯��������Χ�С�
		// ���Χ��aabb.max.x - aabb.min.x �� aabb.max.y - aabb.min.y
		// ��aabb.max.z - aabb.min.z�����ֵ��
		AxesAlignBoundingBox3DPtr m_AABBPtr;
		Real m_MaxRange;

		// ����ϵ��ԭ���Ƕ��κ�ά��d����Ч��
		// ��λ���ȵķ�������ֻ������0 <= i < d��
		// ĩ�˵����������������ĵ�����飬����Ҳֻ������0 <= i < d��
		// ���d = 0�����еĵ�ʵ��������ͬ�ģ�
		// ��ʹ��һ��epsilon�Ŀ��ܻᵼ��ĩ�˵�������Ϊ�㡣
		// ���d = 1�����е��λ����һ���߶��ϡ�
		// ��d = 2ʱ�����е㲻���ߵ���һ��ƽ���ϡ�
		// ��d = 3ʱ�����е��ǲ�����ġ�
		Vector3D m_Origin;
		Vector3D m_DirectionX;
		Vector3D m_DirectionY;
		Vector3D m_DirectionZ;

		// �������ռ䷶Χ�������� 
		// ֵm_MinExtreme��m_MaxExtreme�����ڶ��������������������
		// ��һ�����Χ����������
		// ���ά����2����m_PerpendicularExtreme��
		// ��ֱ����Ӧ��m_MinExtreme��m_MaxExtreme
		// ���Χ���ɵĵ��������
		// ���⣬���ά����3��
		// ��m_TetrahedronExtreme�Ǵ�ֱ����
		// ����ĩ�˵�������������η����ϵ����Χ�ĵ㡣 
		// �ɵ�V[m_MinExtreme], V[m_MaxExtreme], 
		// V[m_PerpendicularExtreme]��V[m_TetrahedronExtreme]���γɵ������壬
		// ��˳ʱ�����ʱ�룬�����洢��m_ExtremeCCW��
		int m_MinExtreme;
		int m_MaxExtreme;
		int m_PerpendicularExtreme;
		int m_TetrahedronExtreme;
		bool m_ExtremeCCW; // �Ƿ�����ʱ��

		// ��С�����������
		int m_IndexMin[3];
		int m_IndexMax[3];
	};

	using Vector3DInformationf = Vector3DInformation<float>;
	using Vector3DInformationd = Vector3DInformation<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_H
