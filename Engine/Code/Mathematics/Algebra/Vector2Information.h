/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/29 17:30)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2.h"

#include <vector>

namespace Mathematics
{
    /// ��ȡ�й�ʸ������������ڲ���Ϣ��
    /// ���������Ч��points����գ�epsilon >= 0����
    /// ����������£����Ա��Ч��
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Vector2Information final
    {
    public:
        using ClassType = Vector2Information<Real>;

        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using AxesAlignBoundingBox2 = AxesAlignBoundingBox2<Real>;
        using ContainerType = std::vector<Vector2>;
        using AlgebraVector2 = Algebra::Vector<2, Real>;
        using AlgebraContainerType = std::vector<AlgebraVector2>;

    public:
        /// ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
        /// ���캯���������뼯�������Ա��
        explicit Vector2Information(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());
        explicit Vector2Information(const AlgebraContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD AxesAlignBoundingBox2 GetAxesAlignBoundingBox() const noexcept;
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
        NODISCARD static ContainerType GetContainer(const AlgebraContainerType& points);

    private:
        ContainerType points;

        /// һ�ַǸ��������ȷ�����ϵ��ڲ�ά����
        Real epsilon;

        /// ���뼯���ڲ�ά�ȡ����У�������epsilon��������ȷ���ߴ�ʱ�ṩ�ݲ
        int dimension;

        /// ���뼯��������Χ�С�
        /// ���Χ��axesAlignBoundingBox.GetMaxPoint(0) - axesAlignBoundingBox.GetMinPoint(0) ��
        /// axesAlignBoundingBox.GetMaxPoint(1) - axesAlignBoundingBox.GetMinPoint(1)�����ֵ��
        AxesAlignBoundingBox2 axesAlignBoundingBox;
        Real maxRange;

        /// ����ϵ��ԭ���Ƕ��κ�ά��d����Ч��
        /// ��λ���ȵķ�������ֻ������0 <= i < d��
        /// ĩ�˵����������������ĵ�����飬����Ҳֻ������0 <= i < d��
        /// ���d = 0�����еĵ�ʵ��������ͬ�ģ�
        /// ��ʹ��һ��epsilon�Ŀ��ܻᵼ��ĩ�˵�������Ϊ�㡣
        /// ���d = 1�����е��λ����һ���߶��ϡ�
        /// ��d = 2ʱ�����е㲻���ߡ�
        Vector2 origin;
        Vector2 directionX;
        Vector2 directionY;

        /// �������ռ䷶Χ��������
        /// ֵminExtreme��maxExtreme�����ڶ�������������������е�һ�����Χ����������
        /// ���ά����2����perpendicularExtreme��
        /// ��ֱ����Ӧ��minExtreme��maxExtreme
        /// ���Χ���ɵĵ��������
        /// �ɵ�V[minExtreme], V[maxExtreme],
        /// �� V[perpendicularExtreme]���γɵ������Σ�
        /// ��˳ʱ�����ʱ�룬�洢��extremeCCW��
        int minExtreme;
        int maxExtreme;
        int perpendicularExtreme;

        /// �Ƿ�����ʱ��
        bool extremeCCW;

        /// ��С�����������
        IndexContainerType indexMin;
        IndexContainerType indexMax;
    };

    using Vector2InformationF = Vector2Information<float>;
    using Vector2InformationD = Vector2Information<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H
