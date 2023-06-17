///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:56)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class NaturalSpline1
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = NaturalSpline1<Real>;

    public:
        NaturalSpline1(bool free, int numSamples, const std::vector<Real>& times, const std::vector<Real>& values);

        NaturalSpline1(int numSamples, const std::vector<Real>& times, const std::vector<Real>& values, Real slopeFirst, Real slopeLast);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetFunction(Real t) const;
        NODISCARD Real GetFirstDerivative(Real t) const;
        NODISCARD Real GetSecondDerivative(Real t) const;
        NODISCARD Real GetThirdDerivative(Real t) const;

        NODISCARD int GetNumSegments() const noexcept;
        NODISCARD std::vector<Real> GetA() const;
        NODISCARD std::vector<Real> GetB() const;
        NODISCARD std::vector<Real> GetC() const;
        NODISCARD std::vector<Real> GetD() const;

    private:
        void CreateFreeSpline();
        void CreateClampedSpline(Real slopeFirst, Real slopeLast);
        void CreatePeriodicSpline();

        void GetKeyInfo(Real t, int& key, Real& dt) const;

    private:
        int numSamples;
        int numSegments;
        std::vector<Real> times;

        std::vector<Real> a;
        std::vector<Real> b;
        std::vector<Real> c;
        std::vector<Real> d;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_H
