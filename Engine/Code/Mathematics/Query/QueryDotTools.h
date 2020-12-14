///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 15:24)

#ifndef MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H
#define MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QueryDotTools final
    {
    public:
        using ClassType = QueryDotTools<Real>;

    public:
        CLASS_INVARIANT_DECLARE;

        // ��������

        [[nodiscard]] static Real Dot(Real x0, Real y0, Real x1, Real y1) noexcept(std::is_arithmetic_v<Real>);
        [[nodiscard]] static Real Det2(Real x0, Real y0, Real x1, Real y1) noexcept(std::is_arithmetic_v<Real>);
        [[nodiscard]] static Real Det3(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2) noexcept(std::is_arithmetic_v<Real>);

        [[nodiscard]] static Real Dot(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1) noexcept(std::is_arithmetic_v<Real>);
        [[nodiscard]] static Real Det4(Real x0, Real y0, Real z0, Real w0, Real x1, Real y1, Real z1, Real w1,
                                       Real x2, Real y2, Real z2, Real w2, Real x3, Real y3, Real z3, Real w3) noexcept(std::is_arithmetic_v<Real>);
    };

    using FloatQueryDotTools = QueryDotTools<float>;
    using DoubleQueryDotTools = QueryDotTools<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H
