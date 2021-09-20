///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 18:43)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2D.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Vector2DInformationImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Vector2DInformationImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Vector2DInformationImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Vector2DInformationImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DInformation final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Vector2DInformationImpl = Vector2DInformationImpl<Real>;

        TYPE_DECLARE(Vector2DInformation);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;

        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = Math<Real>;
        using AxesAlignBoundingBox2D = AxesAlignBoundingBox2D<Real>;
        using ContainerType = std::vector<Vector2D>;

    public:
        // 值epsilon被使用在计算点集的维度时，作为相对误差。
        explicit Vector2DInformation(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

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
        PackageType impl;
    };

    using FloatVector2DInformation = Vector2DInformation<float>;
    using DoubleVector2DInformation = Vector2DInformation<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H
