///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:43)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    // Բ��������2D����ɵ������Ρ�
    template <typename Real>
    class ScribeCircle2Inscribe
    {
    public:
        using ClassType = ScribeCircle2Inscribe<Real>;
        using Vector2Type = Vector2<Real>;
        using Circle2Type = Circle2<Real>;

    public:
        ScribeCircle2Inscribe(const Vector2Type& v0, const Vector2Type& v1, const Vector2Type& v2);

        CLASS_INVARIANT_DECLARE;

        // ���Բ�����죬�����棬���򷵻ؼ٣����������������صģ�
        NODISCARD bool IsCircleConstructed() const noexcept;
        NODISCARD Circle2Type GetCircle2() const;

    private:
        void Calculate();

    private:
        std::vector<Vector2Type> points;
        Circle2Type circle2;
        bool isCircleConstructed;
    };

    using ScribeCircle2InscribeD = ScribeCircle2Inscribe<double>;
    using ScribeCircle2InscribeF = ScribeCircle2Inscribe<float>;
}

#endif  // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_INSCRIBE_H
