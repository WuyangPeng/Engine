///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:12)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BICUBIC2_H
#define MATHEMATICS_INTERPOLATION_INTP_BICUBIC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"

namespace Mathematics
{
    template <typename Real>
    class IntpBicubic2
    {
    public:
        using ClassType = IntpBicubic2<Real>;

    public:
        IntpBicubic2(int xBound, int yBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, const VariableMatrix<Real>& f, bool catmullRom);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetXBound() const noexcept;
        NODISCARD int GetYBound() const noexcept;
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD VariableMatrix<Real> GetF() const;

        NODISCARD Real GetXMin() const noexcept;
        NODISCARD Real GetXMax() const noexcept;
        NODISCARD Real GetXSpacing() const noexcept;
        NODISCARD Real GetYMin() const noexcept;
        NODISCARD Real GetYMax() const noexcept;
        NODISCARD Real GetYSpacing() const noexcept;

        NODISCARD Real operator()(Real x, Real y) const;
        NODISCARD Real operator()(int xOrder, int yOrder, Real x, Real y) const;

    private:
        int xBound;
        int yBound;
        int quantity;
        Real xMin;
        Real xMax;
        Real xSpacing;
        Real invXSpacing;
        Real yMin;
        Real yMax;
        Real ySpacing;
        Real invYSpacing;
        VariableMatrix<Real> f;
        const std::array<std::array<Real, 4>, 4>& blend;

        static const std::array<std::array<Real, 4>, 4> crBlend;
        static const std::array<std::array<Real, 4>, 4> bsBlend;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BICUBIC2_H
