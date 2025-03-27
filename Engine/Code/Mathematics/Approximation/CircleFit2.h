///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:25)

#ifndef MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
#define MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
    // ��һ������С�������Բ��
    // ��������Ĵ����ѳ���maxIterations������һ�����ԡ��������ӵ��������������
    // ���initialCenterIsAverage������Ϊ���桱��
    // Բ�ĵĳ�ʼֵ�²������ݵ��ƽ��ֵ��
    // ������ݵ�����һ��С���أ�CircleFit2�������ٶȺ�����
    // ���initialCenterIsAverage������Ϊ���١���
    // Բ�ĵĳ�ʼֵ�²�ʹ��һ�����η��̣�
    // ��ʾһ��Բ��ϵ������С���˷������㡣
    // ��������������Ѹ��������
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CircleFit2 final
    {
    public:
        using ClassType = CircleFit2<Real>;

        using Vector2 = Vector2<Real>;
        using Circle2 = Circle2<Real>;
        using PointType = std::vector<Vector2>;
        using MathType = Math<Real>;

    public:
        CircleFit2(const PointType& points, int maxIterations, bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Circle2 GetCircle() const noexcept;

    private:
        void Calculate(const PointType& points, int maxIterations, bool initialCenterIsAverage);
        NODISCARD Vector2 GetAveragePoint(const PointType& points);
        void Iteration(const PointType& points, const Vector2& average);

    private:
        Circle2 circle;
    };

    using CircleFit2F = CircleFit2<float>;
    using CircleFit2D = CircleFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
