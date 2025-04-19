///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:43)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    // 包含三个2D点的圆。
    template <typename Real>
    class ScribeCircle2Circumscribe
    {
    public:
        using ClassType = ScribeCircle2Circumscribe<Real>;
        using Vector2Type = Vector2<Real>;
        using Circle2Type = Circle2<Real>;
        using MathType = Math<Real>;

    public:
        ScribeCircle2Circumscribe(const Vector2Type& v0, const Vector2Type& v1, const Vector2Type& v2);

        CLASS_INVARIANT_DECLARE;

        // 如果圆被构造，返回真，否则返回假，（输入点是线性相关的）
        NODISCARD bool IsCircleConstructed() const noexcept;
        NODISCARD Circle2Type GetCircle2() const;

    private:
        void Calculate();

    private:
        std::vector<Vector2Type> points;
        Circle2Type circle2;
        bool isCircleConstructed;
    };

    using ScribeCircle2CircumscribeD = ScribeCircle2Circumscribe<double>;
    using ScribeCircle2CircumscribeF = ScribeCircle2Circumscribe<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_H
