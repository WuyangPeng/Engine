///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:10)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_H

#include "Mathematics/MathematicsDll.h"

#include "IntpAkima1.h"

namespace Mathematics
{
    template <typename Real>
    class IntpAkimaNonuniform1 : public IntpAkima1<Real>
    {
    public:
        using ClassType = IntpAkimaNonuniform1<Real>;
        using ParentType = IntpAkima1<Real>;

    public:
        IntpAkimaNonuniform1(int quantity, const std::vector<Real>& x, const std::vector<Real>& f);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD std::vector<Real> GetX() const;
        NODISCARD Real GetXMin() const override;
        NODISCARD Real GetXMax() const override;

    protected:
        NODISCARD bool Lookup(Real x, int& index, Real& dx) const override;

    private:
        std::vector<Real> xValue;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_H
