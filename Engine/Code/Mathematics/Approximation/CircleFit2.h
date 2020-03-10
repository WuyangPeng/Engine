// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 11:04)

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
    class CircleFit2
    {
    public:
        using ClassType = CircleFit2<Real>;
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        
    public:
        CircleFit2(const std::vector<Vector2D>& points,int maxIterations,bool initialCenterIsAverage);
        
      CLASS_INVARIANT_DECLARE;
        
        const Circle2 GetCircle() const;
        
    private:
        void Calculate(const std::vector<Vector2D>& points,int maxIterations,bool initialCenterIsAverage);
		const Vector2D GetAveragePoint(const std::vector<Vector2D>& points);
		void Iteration(const std::vector<Vector2D>& points, const Vector2D& average);

    private:
        Circle2 m_Circle;
    };

	using CircleFit2d = CircleFit2<double>;
	using CircleFit2f = CircleFit2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
