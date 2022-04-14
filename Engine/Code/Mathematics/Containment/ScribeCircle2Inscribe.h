///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/12 14:12)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    // 圆内切三个2D点组成的三角形。
    template <typename Real>
    class ScribeCircle2Inscribe
    {
    public:
        using ClassType = ScribeCircle2Inscribe<Real>;
        using Vector2 = Vector2<Real>;
        using Circle2 = Circle2<Real>;

    public:
        ScribeCircle2Inscribe(const Vector2& v0, const Vector2& v1, const Vector2& v2);

        CLASS_INVARIANT_DECLARE;

        // 如果圆被构造，返回真，否则返回假，（输入点是线性相关的）
        NODISCARD bool IsCircleConstructed() const noexcept;
        NODISCARD Circle2 GetCircle2() const;

    private:
        void Calculate();

    private:
        std::vector<Vector2> points;
        Circle2 circle2;
        bool isCircleConstructed;
    };

    using ScribeCircle2InscribeD = ScribeCircle2Inscribe<double>;
    using ScribeCircle2InscribeF = ScribeCircle2Inscribe<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H
