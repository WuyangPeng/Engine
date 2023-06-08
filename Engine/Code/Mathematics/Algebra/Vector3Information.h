///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/01 10:20)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Vector3Information final
    {
    public:
        using ClassType = Vector3Information<Real>;

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3<Real>;
        using ContainerType = std::vector<Vector3>;

    public:
        // ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
        explicit Vector3Information(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD AxesAlignBoundingBox3D GetAABB() const noexcept;
        NODISCARD Real GetMaxRange() const noexcept;
        NODISCARD Vector3 GetOrigin() const noexcept;
        NODISCARD Vector3 GetDirectionX() const noexcept;
        NODISCARD Vector3 GetDirectionY() const noexcept;
        NODISCARD Vector3 GetDirectionZ() const noexcept;
        NODISCARD Vector3 GetMinExtreme() const;
        NODISCARD Vector3 GetMaxExtreme() const;
        NODISCARD Vector3 GetPerpendicularExtreme() const;
        NODISCARD Vector3 GetTetrahedronExtreme() const;
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

    private:
        using IndexContainerType = std::array<int, Vector3::pointSize>;

    private:
        ContainerType points;
        Real epsilon;

        // ���뼯�Ĺ���ά�ȡ�
        // ���У�������epsilon��������ȷ���ߴ�ʱ�ṩ�ݲ
        int dimension;

        // ���뼯��������Χ�С�
        // ���Χ��aabb.max.x - aabb.min.x �� aabb.max.y - aabb.min.y
        // ��aabb.max.z - aabb.min.z�����ֵ��
        AxesAlignBoundingBox3D aabb;
        Real maxRange;

        // ����ϵ��ԭ���Ƕ��κ�ά��d����Ч��
        // ��λ���ȵķ�������ֻ������0 <= i < d��
        // ĩ�˵����������������ĵ�����飬����Ҳֻ������0 <= i < d��
        // ���d = 0�����еĵ�ʵ��������ͬ�ģ�
        // ��ʹ��һ��epsilon�Ŀ��ܻᵼ��ĩ�˵�������Ϊ�㡣
        // ���d = 1�����е��λ����һ���߶��ϡ�
        // ��d = 2ʱ�����е㲻���ߵ���һ��ƽ���ϡ�
        // ��d = 3ʱ�����е��ǲ�����ġ�
        Vector3 origin;
        Vector3 directionX;
        Vector3 directionY;
        Vector3 directionZ;

        // �������ռ䷶Χ��������
        // ֵm_MinExtreme��m_MaxExtreme�����ڶ��������������������
        // ��һ�����Χ����������
        // ���ά����2����m_PerpendicularExtreme��
        // ��ֱ����Ӧ��m_MinExtreme��m_MaxExtreme
        // ���Χ���ɵĵ��������
        // ���⣬���ά����3��
        // ��m_TetrahedronExtreme�Ǵ�ֱ����
        // ����ĩ�˵�������������η����ϵ����Χ�ĵ㡣
        // �ɵ�V[minExtreme], V[maxExtreme],
        // V[perpendicularExtreme]��V[tetrahedronExtreme]���γɵ������壬
        // ��˳ʱ�����ʱ�룬�����洢��m_ExtremeCCW��
        int minExtreme;
        int maxExtreme;
        int perpendicularExtreme;
        int tetrahedronExtreme;
        bool extremeCCW;  // �Ƿ�����ʱ��

        // ��С�����������
        IndexContainerType indexMin;
        IndexContainerType indexMax;
    };

    using FloatVector3Information = Vector3Information<float>;
    using DoubleVector3Information = Vector3Information<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H
