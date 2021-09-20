///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 18:34)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3D.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Vector3DInformationImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Vector3DInformationImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Vector3DInformationImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Vector3DInformationImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DInformation final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Vector3DInformationImpl = Vector3DInformationImpl<Real>;
      
        TYPE_DECLARE(Vector3DInformation);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using ClassType = Vector3DInformation<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3D<Real>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // ֵepsilon��ʹ���ڼ���㼯��ά��ʱ����Ϊ�����
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
        PackageType impl;
    };

    using FloatVector3DInformation = Vector3DInformation<float>;
    using DoubleVector3DInformation = Vector3DInformation<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_H
