///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/11 18:54)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_IMPL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Vector2DInformationImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2DInformationImpl<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = Math<Real>;
        using AxesAlignBoundingBox2D = AxesAlignBoundingBox2D<Real>;
        using ContainerType = std::vector<Vector2D>;

    public:
        // ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
        explicit Vector2DInformationImpl(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetDimension() const noexcept;
        [[nodiscard]] AxesAlignBoundingBox2D GetAABB() const noexcept;
        [[nodiscard]] Real GetMaxRange() const noexcept; 
        [[nodiscard]] const Vector2D GetOrigin() const noexcept;
        [[nodiscard]] const Vector2D GetDirectionX() const noexcept;
        [[nodiscard]] const Vector2D GetDirectionY() const noexcept;
        [[nodiscard]] const Vector2D GetMinExtreme() const; 
        [[nodiscard]] const Vector2D GetMaxExtreme() const;
        [[nodiscard]] const Vector2D GetPerpendicularExtreme() const;
        [[nodiscard]] bool IsExtremeCCW() const noexcept;
        [[nodiscard]] int GetMinExtremeIndex() const noexcept;
        [[nodiscard]] int GetPerpendicularExtremeIndex() const noexcept;
        [[nodiscard]] int GetMaxExtremeIndex() const noexcept;
        [[nodiscard]] int GetIndexMin(int index) const;

    private:      
        using IndexContainerType = std::array<int, Vector2D::sm_PointSize>;

    private:
        void Init();
        void ComputeAxisAlignedBoundingBox();
        void DetermineMaximumRange() noexcept;
        [[nodiscard]] bool TestPointSetIsNearlyAPoint() noexcept;
        [[nodiscard]] bool TestPointSetIsNearlyALineSegment();

    private:
        ContainerType m_Points;
        Real m_Epsilon;

        // ���뼯�Ĺ���ά�ȡ����У�������epsilon��������ȷ���ߴ�ʱ�ṩ�ݲ
        int m_Dimension;

        // ���뼯��������Χ�С�
        // ���Χ��aabb.max.x - aabb.min.x �� aabb.max.y - aabb.min.y�����ֵ��
        AxesAlignBoundingBox2D m_AABB;
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
        bool m_ExtremeCCW;  // �Ƿ�����ʱ��

        // ��С�����������
        IndexContainerType m_IndexMin;
        IndexContainerType m_IndexMax;
    };
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_IMPL_H
