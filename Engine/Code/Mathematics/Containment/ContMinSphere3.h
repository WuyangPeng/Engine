///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/11 14:56)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class ContMinSphere3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContMinSphere3<Real>;

    public:
        ContMinSphere3(const std::vector<Vector3<Real>>& points, Sphere3<Real>& minimal, Real epsilon = static_cast<Real>(1e-03));

        CLASS_INVARIANT_DECLARE;

    private:
        class Support
        {
        public:
            bool Contains(int index, const std::vector<Vector3<Real>>& points, Real epsilon);

            int quantity;
            std::array<int, 4> index;
        };

        NODISCARD bool Contains(const Vector3<Real>& point, const Sphere3<Real>& sphere, Real& distDiff);

        NODISCARD Sphere3<Real> ExactSphere1(const Vector3<Real>& p) noexcept;
        NODISCARD Sphere3<Real> ExactSphere2(const Vector3<Real>& p0, const Vector3<Real>& p1);
        NODISCARD Sphere3<Real> ExactSphere3(const Vector3<Real>& p0, const Vector3<Real>& p1, const Vector3<Real>& p2);
        NODISCARD Sphere3<Real> ExactSphere4(const Vector3<Real>& p0, const Vector3<Real>& p1, const Vector3<Real>& p2, const Vector3<Real>& p3);

        NODISCARD Sphere3<Real> UpdateSupport1(int i, const std::vector<Vector3<Real>>& permuted, Support& support);
        NODISCARD Sphere3<Real> UpdateSupport2(int i, const std::vector<Vector3<Real>>& permuted, Support& support);
        NODISCARD Sphere3<Real> UpdateSupport3(int i, const std::vector<Vector3<Real>>& permuted, Support& support);
        NODISCARD Sphere3<Real> UpdateSupport4(int i, const std::vector<Vector3<Real>>& permuted, Support& support);

        using UpdateFunction = Sphere3<Real> (ClassType::*)(int, const std::vector<Vector3<Real>>&, Support&);

    private:
        Real epsilon;
        std::array<UpdateFunction, 5> update;
    };

    using MinSphere3F = ContMinSphere3<float>;
    using MinSphere3D = ContMinSphere3<double>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_H
