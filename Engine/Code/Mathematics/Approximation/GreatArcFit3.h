///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 14:29)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    // ������С���˵�һ����Բ����������ͶӰ��Բ��
    // ��С�ǵ�����(���ܵ�)��������㡣
    // ���Ķ˵�����α����ء����صĶ˵�A0��A1�Ǵ�ֱ�ڷ��صķ���N��
    // ����,����鿴��ͨ���۲�ƽ��Ĵ�Բ�� N����,Բ���Ǳ�����ʱ���A0��A1��
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE GreatArcFit3 final
    {
    public:
        using ClassType = GreatArcFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using Points = std::vector<Vector3D>;
        using Math = Math<Real>;

    public:
        explicit GreatArcFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetNormal() const noexcept;
        [[nodiscard]] const Vector3D GetArcEnd0() const noexcept;
        [[nodiscard]] const Vector3D GetArcEnd1() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        Vector3D m_Normal;
        Vector3D m_ArcEnd0;
        Vector3D m_ArcEnd1;
    };

    using FloatGreatArcFit3 = GreatArcFit3<float>;
    using DoubleGreatArcFit3 = GreatArcFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
