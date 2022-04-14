///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/18 21:34)

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
