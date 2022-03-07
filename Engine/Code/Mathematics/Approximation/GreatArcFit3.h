///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 15:47)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

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
        using Vector3 = Vector3<Real>;
        using Points = std::vector<Vector3>;
        using Math = Math<Real>;

    public:
        explicit GreatArcFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetNormal() const noexcept;
        NODISCARD Vector3 GetArcEnd0() const noexcept;
        NODISCARD Vector3 GetArcEnd1() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        Vector3 normal;
        Vector3 arcEnd0;
        Vector3 arcEnd1;
    };

    using GreatArcFit3F = GreatArcFit3<float>;
    using GreatArcFit3D = GreatArcFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_H
