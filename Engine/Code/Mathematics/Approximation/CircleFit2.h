///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 17:46)

#ifndef MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
#define MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
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
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        using PointType = std::vector<Vector2D>;
        using Math = Math<Real>;

    public:
        CircleFit2(const PointType& points, int maxIterations, bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Circle2 GetCircle() const noexcept;

    private:
        void Calculate(const PointType& points, int maxIterations, bool initialCenterIsAverage);
        [[nodiscard]] const Vector2D GetAveragePoint(const PointType& points);
        void Iteration(const PointType& points, const Vector2D& average);

    private:
        Circle2 m_Circle;
    };

    using FloatCircleFit2 = CircleFit2<float>;
    using DoubleCircleFit2 = CircleFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
