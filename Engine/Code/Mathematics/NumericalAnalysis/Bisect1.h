///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect1Root.h"
#include "Mathematics/Base/MathDetail.h"

// ���ַ��ⷽ��
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect1 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect1<Real>;
        using Math = Math<Real>;
        using Function = Real (*)(Real);
        using Bisect1Root = Bisect1Root<Real>;

    public:
        Bisect1(Function function, int maxLevel, Real tolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ͨ�������������˵����ⷽ��
        NODISCARD Bisect1Root Bisect(Real beginPoint, Real endPoint);

    private:
        // �������ݺͺ�����
        Function function;
        int maxLevel;
        Real tolerance;
    };

    using Bisect1F = Bisect1<float>;
    using Bisect1D = Bisect1<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H
