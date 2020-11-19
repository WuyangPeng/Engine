///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 9:35)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_H
#define MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Torus3Parameters final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Torus3Parameters<Real>;
        using Math = Math<Real>;

    public:
        Torus3Parameters(Real s, Real t) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetS() const noexcept;
        [[nodiscard]] Real GetT() const noexcept;

    private:
        Real m_S;
        Real m_T;
    };

    using FloatTorus3Parameters = Torus3Parameters<float>;
    using DoubleTorus3Parameters = Torus3Parameters<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_H
