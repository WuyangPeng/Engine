///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:55)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "Curve2.h"

namespace Mathematics
{
    template <typename Real>
    class MultipleCurve2 : public Curve2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = MultipleCurve2<Real>;
        using ParentType = Curve2<Real>;

    public:
        MultipleCurve2(int numSegments, const std::vector<Real>& times);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetSegments() const noexcept;
        NODISCARD std::vector<Real> GetTimes() const;
        NODISCARD Real GetTimes(int index) const;

        NODISCARD Real GetLength(Real t0, Real t1) const override;
        NODISCARD Real GetTime(Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const override;

    protected:
        void GetKeyInfo(Real t, int& key, Real& dt) const;

        void InitializeLength() const;
        NODISCARD virtual Real GetSpeedKey(int key, Real t) const = 0;
        NODISCARD virtual Real GetLengthKey(int key, Real t0, Real t1) const = 0;

    private:
        int numSegments;
        std::vector<Real> times;

        mutable std::vector<Real> lengths;
        mutable std::vector<Real> accumLengths;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE2_H
