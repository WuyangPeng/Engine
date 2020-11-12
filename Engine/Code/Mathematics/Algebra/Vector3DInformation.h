///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 18:34)

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
    class Vector3DInformationImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Vector3DInformationImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Vector3DInformationImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Vector3DInformationImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DInformation final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Vector3DInformationImpl = Vector3DInformationImpl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(Vector3DInformation);

        using ClassType = Vector3DInformation<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3D<Real>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // 值epsilon被使用在计算点集的维度时，作为相对误差。
        explicit Vector3DInformation(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

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
        IMPL_TYPE_DECLARE(Vector3DInformation);
    };

    using FloatVector3DInformation = Vector3DInformation<float>;
    using DoubleVector3DInformation = Vector3DInformation<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_H
