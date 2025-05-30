/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_TORUS3_PARAMETERS_H
#define MATHEMATICS_OBJECTS_3D_TORUS3_PARAMETERS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Torus3Parameters final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Torus3Parameters<Real>;

        using MathType = Math<Real>;

    public:
        Torus3Parameters(Real s, Real t) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetS() const noexcept;
        NODISCARD Real GetT() const noexcept;

    private:
        Real s;
        Real t;
    };

    using Torus3ParametersF = Torus3Parameters<float>;
    using Torus3ParametersD = Torus3Parameters<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_TORUS3_PARAMETERS_H
