///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/11 18:43)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Vector2Information final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2Information<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using AxesAlignBoundingBox2D = AxesAlignBoundingBox2<Real>;
        using ContainerType = std::vector<Vector2>;

    public:
        // ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
        explicit Vector2Information(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD AxesAlignBoundingBox2D GetAABB() const noexcept;
        NODISCARD Real GetMaxRange() const noexcept;
        NODISCARD Vector2 GetOrigin() const noexcept;
        NODISCARD Vector2 GetDirectionX() const noexcept;
        NODISCARD Vector2 GetDirectionY() const noexcept;
        NODISCARD Vector2 GetMinExtreme() const;
        NODISCARD Vector2 GetMaxExtreme() const;
        NODISCARD Vector2 GetPerpendicularExtreme() const;
        NODISCARD bool IsExtremeCCW() const noexcept;
        NODISCARD int GetMinExtremeIndex() const noexcept;
        NODISCARD int GetPerpendicularExtremeIndex() const noexcept;
        NODISCARD int GetMaxExtremeIndex() const noexcept;
        NODISCARD int GetIndexMin(int index) const;

    private:
        using IndexContainerType = std::array<int, Vector2::pointSize>;

    private:
        void Init();
        void ComputeAxisAlignedBoundingBox();
        void DetermineMaximumRange() noexcept;
        NODISCARD bool TestPointSetIsNearlyAPoint() noexcept;
        NODISCARD bool TestPointSetIsNearlyALineSegment();

    private:
        ContainerType points;
        Real epsilon;

        // ���뼯�Ĺ���ά�ȡ����У�������epsilon��������ȷ���ߴ�ʱ�ṩ�ݲ
        int dimension;

        // ���뼯��������Χ�С�
        // ���Χ��aabb.max.x - aabb.min.x �� aabb.max.y - aabb.min.y�����ֵ��
        AxesAlignBoundingBox2D aabb;
        Real maxRange;

        // ����ϵ��ԭ���Ƕ��κ�ά��d����Ч��
        // ��λ���ȵķ�������ֻ������0 <= i < d��
        // ĩ�˵����������������ĵ�����飬����Ҳֻ������0 <= i < d��
        // ���d = 0�����еĵ�ʵ��������ͬ�ģ�
        // ��ʹ��һ��epsilon�Ŀ��ܻᵼ��ĩ�˵�������Ϊ�㡣
        // ���d = 1�����е��λ����һ���߶��ϡ�
        // ��d = 2ʱ�����е㲻���ߡ�
        Vector2 origin;
        Vector2 directionX;
        Vector2 directionY;

        // �������ռ䷶Χ��������
        // ֵm_MinExtreme��m_MaxExtreme�����ڶ�������������������е�һ�����Χ����������
        // ���ά����2����m_PerpendicularExtreme��
        // ��ֱ����Ӧ��m_MinExtreme��m_MaxExtreme
        // ���Χ���ɵĵ��������
        // �ɵ�V[m_MinExtreme], V[m_MaxExtreme],
        // �� V[m_PerpendicularExtreme]���γɵ������Σ�
        // ��˳ʱ�����ʱ�룬�洢��m_ExtremeCCW��
        int minExtreme;
        int maxExtreme;
        int perpendicularExtreme;
        bool extremeCCW;  // �Ƿ�����ʱ��

        // ��С�����������
        IndexContainerType indexMin;
        IndexContainerType indexMax;
    };

    using Vector2InformationF = Vector2Information<float>;
    using Vector2InformationD = Vector2Information<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H
