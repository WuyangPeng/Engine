///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:04)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/IntersectionType.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Intersector
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Intersector<Real, Vector>;

        using Math = Math<Real>;
        using VectorType = Vector<Real>;

    public:
        explicit Intersector(Real epsilon = Math::GetZeroTolerance()) noexcept;
        virtual ~Intersector() noexcept = 0;
        Intersector(const Intersector& rhs) noexcept = default;
        virtual Intersector& operator=(const Intersector& rhs) noexcept = default;
        Intersector(Intersector&& rhs) noexcept = default;
        virtual Intersector& operator=(Intersector&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD Real GetEpsilon() const noexcept;
        NODISCARD IntersectionType GetIntersectionType() const noexcept;
        NODISCARD bool IsIntersection() const noexcept;

    protected:
        void SetIntersectionType(IntersectionType newIntersectionType) noexcept;
        virtual void Swap(Intersector& rhs) noexcept;

    private:
        IntersectionType intersectionType;
        Real epsilon;
    };

    using Intersector2F = Intersector<float, Vector2>;
    using Intersector3F = Intersector<float, Vector3>;
    using Intersector2D = Intersector<double, Vector2>;
    using Intersector3D = Intersector<double, Vector3>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_H
