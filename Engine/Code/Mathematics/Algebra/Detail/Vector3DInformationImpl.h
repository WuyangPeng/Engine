///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 17:50)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_IMPL_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Vector3DInformationImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3DInformationImpl<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3D<Real>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
        explicit Vector3DInformationImpl(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetDimension() const noexcept;
        [[nodiscard]] AxesAlignBoundingBox3D GetAABB() const noexcept;
        [[nodiscard]] Real GetMaxRange() const noexcept;
        [[nodiscard]] const Vector3D GetOrigin() const noexcept;
        [[nodiscard]] const Vector3D GetDirectionX() const noexcept;
        [[nodiscard]] const Vector3D GetDirectionY() const noexcept;
        [[nodiscard]] const Vector3D GetDirectionZ() const noexcept;
        [[nodiscard]] const Vector3D GetMinExtreme() const;
        [[nodiscard]] const Vector3D GetMaxExtreme() const;
        [[nodiscard]] const Vector3D GetPerpendicularExtreme() const;
        [[nodiscard]] const Vector3D GetTetrahedronExtreme() const;
        [[nodiscard]] bool IsExtremeCCW() const noexcept;

        [[nodiscard]] int GetMinExtremeIndex() const noexcept;
        [[nodiscard]] int GetMaxExtremeIndex() const noexcept;
        [[nodiscard]] int GetPerpendicularExtremeIndex() const noexcept;
        [[nodiscard]] int GetTetrahedronExtremeIndex() const noexcept;

    private:
        void Init();
        void ComputeAxisAlignedBoundingBox();
        void DetermineMaximumRange();
        [[nodiscard]] bool TestPointSetIsNearlyAPoint() noexcept;
        [[nodiscard]] bool TestPointSetIsNearlyALineSegment();
        [[nodiscard]] bool TestPointSetIsNearlyAPlanarPolygon();

    private:
        using IndexContainerType = std::array<int, Vector3D::sm_PointSize>;

    private:
        ContainerType m_Points;
        Real m_Epsilon;

        // ���뼯�Ĺ���ά�ȡ�
        // ���У�������epsilon��������ȷ���ߴ�ʱ�ṩ�ݲ
        int m_Dimension;

        // ���뼯��������Χ�С�
        // ���Χ��aabb.max.x - aabb.min.x �� aabb.max.y - aabb.min.y
        // ��aabb.max.z - aabb.min.z�����ֵ��
        AxesAlignBoundingBox3D m_AABB;
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
        bool m_ExtremeCCW;  // �Ƿ�����ʱ��

        // ��С�����������
        IndexContainerType m_IndexMin;
        IndexContainerType m_IndexMax;
    };

    using FloatVector3DInformation = Vector3DInformation<float>;
    using DoubleVector3DInformation = Vector3DInformation<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_IMPL_H
