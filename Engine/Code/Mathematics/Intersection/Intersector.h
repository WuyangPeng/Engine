///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 10:10)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/IntersectionType.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"
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
        explicit Intersector(const Real epsilon = Math::GetZeroTolerance()) noexcept;
        virtual ~Intersector() noexcept = 0;
        Intersector(const Intersector& rhs) noexcept = default;
        virtual Intersector& operator=(const Intersector& rhs) noexcept = default;
        Intersector(Intersector&& rhs) noexcept = default;
        virtual Intersector& operator=(Intersector&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] Real GetEpsilon() const noexcept;
        [[nodiscard]] IntersectionType GetIntersectionType() const noexcept;
        [[nodiscard]] bool IsIntersection() const noexcept;

    protected:
        void SetIntersectionType(IntersectionType intersectionType) noexcept;
        virtual void Swap(Intersector& rhs) noexcept;

    private:
        IntersectionType m_IntersectionType;
        Real m_Epsilon;
    };

    using FloatIntersector2D = Intersector<float, Vector2D>;
    using FloatIntersector3D = Intersector<float, Vector3D>;
    using DoubleIntersector2D = Intersector<double, Vector2D>;
    using DoubleIntersector3D = Intersector<double, Vector3D>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_H
