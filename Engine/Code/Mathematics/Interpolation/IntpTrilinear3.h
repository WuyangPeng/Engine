///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:14)

#ifndef MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_H
#define MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/MemoryTools/Array3.h"

namespace Mathematics
{
    template <typename Real>
    class IntpTrilinear3
    {
    public:
        using ClassType = IntpTrilinear3<Real>;

    public:
        IntpTrilinear3(int xBound, int yBound, int zBound, Real xMin, Real xSpacing, Real yMin, Real ySpacing, Real zMin, Real zSpacing, const CoreTools::Array3<Real>& f);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetXBound() const noexcept;
        NODISCARD int GetYBound() const noexcept;
        NODISCARD int GetZBound() const noexcept;
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD CoreTools::Array3<Real> GetF() const;

        NODISCARD Real GetXMin() const noexcept;
        NODISCARD Real GetXMax() const noexcept;
        NODISCARD Real GetXSpacing() const noexcept;
        NODISCARD Real GetYMin() const noexcept;
        NODISCARD Real GetYMax() const noexcept;
        NODISCARD Real GetYSpacing() const noexcept;
        NODISCARD Real GetZMin() const noexcept;
        NODISCARD Real GetZMax() const noexcept;
        NODISCARD Real GetZSpacing() const noexcept;

        NODISCARD Real operator()(Real x, Real y, Real z) const;
        NODISCARD Real operator()(int xOrder, int yOrder, int zOrder, Real x, Real y, Real z) const;

    private:
        int xBound;
        int yBound;
        int zBound;
        int quantity;
        Real xMin;
        Real xMax;
        Real xSpacing;
        Real invXSpacing;
        Real yMin;
        Real yMax;
        Real ySpacing;
        Real invYSpacing;
        Real zMin;
        Real zMax;
        Real zSpacing;
        Real invZSpacing;
        CoreTools::Array3<Real> f;

        static const std::array<std::array<Real, 2>, 2> blend;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_TRILINEAR3_H
