/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:44)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_INTERNAL_FWD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_INTERNAL_FWD_H

#include "NumericalAnalysisFwd.h"

namespace Mathematics
{
    class EquationImpl;
    class EquationFactory;

    template <typename Real>
    class Bisect2Calculate;

    template <typename Real>
    class Bisect2Node;

    template <typename Real>
    class Bisect2Storage;

    template <typename Real>
    class Bisect3Calculate;

    template <typename Real>
    class Bisect3Node;

    template <typename Real>
    class Bisect3Storage;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_INTERNAL_FWD_H