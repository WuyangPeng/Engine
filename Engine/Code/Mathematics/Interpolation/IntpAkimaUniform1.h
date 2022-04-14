///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/19 12:45)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_H

#include "Mathematics/MathematicsDll.h"

#include "IntpAkima1.h"

namespace Mathematics
{
    template <typename Real>
    class IntpAkimaUniform1 : public IntpAkima1<Real>
    {
    public:
        using ClassType = IntpAkimaUniform1<Real>;
        using ParentType = IntpAkima1<Real>;

    public:
        IntpAkimaUniform1(int quantity, Real xMin, Real xSpacing, const std::vector<Real>& f);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Real GetXMin() const noexcept override;
        NODISCARD Real GetXMax() const noexcept override;
        NODISCARD Real GetXSpacing() const noexcept;

    protected:
        NODISCARD bool Lookup(Real x, int& index, Real& dx) const noexcept override;

    private:
        Real xMin;
        Real xMax;
        Real xSpacing;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_H
