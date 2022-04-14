///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/12 14:09)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    // ��������2D���Բ��
    template <typename Real>
    class ScribeCircle2Circumscribe
    {
    public:
        using ClassType = ScribeCircle2Circumscribe<Real>;
        using Vector2 = Vector2<Real>;
        using Circle2 = Circle2<Real>;
        using Math = Math<Real>;

    public:
        ScribeCircle2Circumscribe(const Vector2& v0, const Vector2& v1, const Vector2& v2);

        CLASS_INVARIANT_DECLARE;

        // ���Բ�����죬�����棬���򷵻ؼ٣����������������صģ�
        NODISCARD bool IsCircleConstructed() const noexcept;
        NODISCARD Circle2 GetCircle2() const;

    private:
        void Calculate();

    private:
        std::vector<Vector2> points;
        Circle2 circle2;
        bool isCircleConstructed;
    };

    using ScribeCircle2CircumscribeD = ScribeCircle2Circumscribe<double>;
    using ScribeCircle2CircumscribeF = ScribeCircle2Circumscribe<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_H
