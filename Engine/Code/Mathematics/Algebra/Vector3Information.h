/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/30 10:10)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    /// ��ȡ�й�ʸ������������ڲ���Ϣ��
    /// ���������Ч��points����գ�epsilon >= 0����
    /// ����������£����Ա��Ч��
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Vector3Information final
    {
    public:
        using ClassType = Vector3Information<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using AxesAlignBoundingBox3Type = AxesAlignBoundingBox3<Real>;
        using ContainerType = std::vector<Vector3Type>;
        using AlgebraVector3 = Algebra::Vector<3, Real>;
        using AlgebraContainerType = std::vector<AlgebraVector3>;

    public:
        /// ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
        /// ���캯���������뼯�������Ա��
        explicit Vector3Information(const ContainerType& points, Real epsilon = MathType::GetZeroTolerance());
        explicit Vector3Information(const AlgebraContainerType& points, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD AxesAlignBoundingBox3Type GetAxesAlignBoundingBox() const noexcept;
        NODISCARD Real GetMaxRange() const noexcept;
        NODISCARD Vector3Type GetOrigin() const noexcept;
        NODISCARD Vector3Type GetDirectionX() const noexcept;
        NODISCARD Vector3Type GetDirectionY() const noexcept;
        NODISCARD Vector3Type GetDirectionZ() const noexcept;
        NODISCARD Vector3Type GetMinExtreme() const;
        NODISCARD Vector3Type GetMaxExtreme() const;
        NODISCARD Vector3Type GetPerpendicularExtreme() const;
        NODISCARD Vector3Type GetTetrahedronExtreme() const;
        NODISCARD bool IsExtremeCCW() const noexcept;

        NODISCARD int GetMinExtremeIndex() const noexcept;
        NODISCARD int GetMaxExtremeIndex() const noexcept;
        NODISCARD int GetPerpendicularExtremeIndex() const noexcept;
        NODISCARD int GetTetrahedronExtremeIndex() const noexcept;

    private:
        void Init();
        void ComputeAxisAlignedBoundingBox();
        void DetermineMaximumRange();
        NODISCARD bool TestPointSetIsNearlyAPoint() noexcept;
        NODISCARD bool TestPointSetIsNearlyALineSegment();
        NODISCARD bool TestPointSetIsNearlyAPlanarPolygon();
        NODISCARD static ContainerType GetContainer(const AlgebraContainerType& points);

    private:
        using IndexContainerType = std::array<int, Vector3Type::pointSize>;

    private:
        ContainerType points;

        /// һ�ַǸ��������ȷ�����ϵ��ڲ�ά����
        Real epsilon;

        /// ���뼯���ڲ�ά�ȡ�
        /// ���У�������epsilon��������ȷ���ߴ�ʱ�ṩ�ݲ
        int dimension;

        /// ���뼯��������Χ�С�
        /// ���Χ��axesAlignBoundingBox.GetMaxPoint(0) - axesAlignBoundingBox.GetMinPoint(0) ��
        /// axesAlignBoundingBox.GetMaxPoint(1) - axesAlignBoundingBox.GetMinPoint(1)��
        /// axesAlignBoundingBox.GetMaxPoint(2) - axesAlignBoundingBox.GetMinPoint(2)�����ֵ��
        AxesAlignBoundingBox3Type axesAlignBoundingBox;
        Real maxRange;

        /// ����ϵ��ԭ���Ƕ��κ�ά��d����Ч��
        /// ��λ���ȵķ�������ֻ������0 <= i < d��
        /// ĩ�˵����������������ĵ�����飬����Ҳֻ������0 <= i < d��
        /// ���d = 0�����еĵ�ʵ��������ͬ�ģ�
        /// ��ʹ��һ��epsilon�Ŀ��ܻᵼ��ĩ�˵�������Ϊ�㡣
        /// ���d = 1�����е��λ����һ���߶��ϡ�
        /// ��d = 2ʱ�����е㲻���ߵ���һ��ƽ���ϡ�
        /// ��d = 3ʱ�����е��ǲ�����ġ�
        Vector3Type origin;
        Vector3Type directionX;
        Vector3Type directionY;
        Vector3Type directionZ;

        /// �������ռ䷶Χ��������
        /// ֵminExtreme��maxExtreme�����ڶ��������������������
        /// ��һ�����Χ����������
        /// ���ά����2����perpendicularExtreme��
        /// ��ֱ����Ӧ��minExtreme��maxExtreme
        /// ���Χ���ɵĵ��������
        /// ���⣬���ά����3��
        /// ��tetrahedronExtreme�Ǵ�ֱ����
        /// ����ĩ�˵�������������η����ϵ����Χ�ĵ㡣
        /// �ɵ�V[minExtreme], V[maxExtreme],
        /// V[perpendicularExtreme]��V[tetrahedronExtreme]���γɵ������壬
        /// ��˳ʱ�����ʱ�룬�����洢��extremeCCW��
        int minExtreme;
        int maxExtreme;
        int perpendicularExtreme;
        int tetrahedronExtreme;

        /// �Ƿ�����ʱ��
        bool extremeCCW;

        /// ��С�����������
        IndexContainerType indexMin;
        IndexContainerType indexMax;
    };

    using FloatVector3Information = Vector3Information<float>;
    using DoubleVector3Information = Vector3Information<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H
