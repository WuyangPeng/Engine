///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 18:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H

#include "Mathematics/MathematicsDll.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
    template <typename Real>
    class NoniterativeEigen3x3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<NoniterativeEigen3x3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<NoniterativeEigen3x3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<NoniterativeEigen3x3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE NoniterativeEigen3x3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using NoniterativeEigen3x3Impl = NoniterativeEigen3x3Impl<Real>;
   
        TYPE_DECLARE(NoniterativeEigen3x3);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using Matrix3 = Matrix3<Real>;
        using Vector3D = Vector3D<Real>;

    public:
        // 输入矩阵必须是对称的。
        explicit NoniterativeEigen3x3(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

        // 得到特征向量。特征值以递增的顺序存储。
        [[nodiscard]] Real GetEigenvalue(int index) const;
        [[nodiscard]] const Vector3D GetEigenvector(int index) const;

    private:
        PackageType impl;
    };

    using FloatNoniterativeEigen3x3 = NoniterativeEigen3x3<float>;
    using DoubleNoniterativeEigen3x3 = NoniterativeEigen3x3<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H
