// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/24 14:33)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_H

#include "Flags/IntersectionType.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real, template <typename> class Vector>
    class Intersector
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Intersector<Real, Vector>;
        using Math = Math<Real>;
        using VectorType = Vector<Real>;

    public:
        explicit Intersector(const Real epsilon = Math::GetZeroTolerance()) noexcept;
        virtual ~Intersector() = 0;
        Intersector(const Intersector&) = default;
        Intersector& operator=(const Intersector&) = default;
        Intersector( Intersector&&) = default;
        Intersector& operator=( Intersector&&) = default;

            CLASS_INVARIANT_VIRTUAL_DECLARE;

        Real GetEpsilon() const noexcept;
        IntersectionType GetIntersectionType() const;
        bool IsIntersection() const noexcept;

    protected:
        void SetIntersectionType(IntersectionType intersectionType) noexcept;

    private:
        IntersectionType m_IntersectionType;
        Real m_Epsilon;
    };

    using Intersector2f = Intersector<float, Vector2D>;
    using Intersector3f = Intersector<float, Vector3D>;
    using Intersector2d = Intersector<double, Vector2D>;
    using Intersector3d = Intersector<double, Vector3D>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_H
