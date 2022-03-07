///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/21 13:53)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
    // ����(x0,y0)���׼˫����F(x,y) = (x/a)^2 - (y/b)^2 - 1 = 0֮��ľ���
    // ����a> 0��b> 0�� ���ǵ�(x0,y0)�ڵ�һ������ʱ�����������x0 >= 0 �� y0 >= 0��
    // ����ĵ�(x,y)Ҳ�ڵ�һ�����С�
    // �ڼ��Σ�����D =D = (x0-x,y0-y)���봹ֱ��(x,y)����˫���ߡ�
    // ������N = �ݶ�(Q)/2 =(x / a^2,-y / b^2)��

    // �������1����Ϊ�Ĵζ���ʽ����
    // ��ΪD��N��ƽ�еģ����Ե��µ�ʽG(x,y) = (x0-x)*y/b^2 + (y0-y)*x/a^2 = 0��
    // ���Դ���������F(x,y) = 0 ��G(x,y) = 0����������y��
    //   P(x) = c0 + c1*x + c2*x^2 + c3*x^3 + c4*x^4 = 0
    // ����
    //   c0 = -a^6*x0^2
    //   c1 = 2*a^4*(a^2+b^2)*x0,
    //   c2 = -a^2*((a^2+b^2)^2 - a^2*x0^2 + b^2*y0^2)
    //   c3 = -2*a*(a^2+b^2)*x0
    //   c4 = (a^2+b^2)^2
    // �����Լ���P(x) = 0�ĸ�������ÿ��������x = r��y = s���F(r,y) = 0��
    // ����� (x0,y0)��(r,s)�ľ��롣 �ڴ�������(r,s)�����о����У�
    // ѡ����С������Ϊ��(x0,y0)��˫���ߵľ��롣
    // ��ֵ�ϣ������Ҳ���׳�����Ҫ����ʹ�ô��㷨��

    // �������2���Ƚ�����
    // ��ΪD��N��ƽ�еģ����Ա������D = t*N�ı���t;
    // ��(x0-x,y0-y) = t*(x/a^2,-y/b^2)��
    // ��Ȼ���㷨�в���Ҫ��ͨ�����Σ�sign(t) = sign(F(x0,y0))�� һЩ��������
    //   (x,y) = x0/(1 + t/a^2), y0/(1 - t/b^2))
    // ֪��(x,y)�ڵ�һ�����У�tֵ��������-a^2 <= t <= b^2��
    // �� (x,y) ����F(x,y) = 0����H(t) = x0^2/(1 + t/a^2)^2 - y0^2/(1 - t/b^2)^2 - 1 = 0��
    // H(t)��ͼ��t = -a^2��t = b^2�����д�ֱ�����ߡ�
    // ����ֻ����ͼ��-a^2 <= t <= b^2��
    // ע�⣬��t���ұ߽ӽ�-a^2ʱ��H��t����Ϊ+�����
    // ��t����߽ӽ�b^2ʱ��H��t����Ϊ-�����
    // ����H'(t)�����һ����Ϊ��;
    // ��ʵ�ϣ�����Խ⿪�պ���ʽ��H'(t) = 0��
    // ���������ڽ����ߴ���H(t)����Ϊ��֤H(t)�� -a^2 <= t <= b^2�ĵݼ�������
    // �����������H(t) = 0����Ψһ�� �ڴ˼����
    // ��ˣ�������ʹ�ö��ַ���³���ؼ������ ��������ʹ�õ�ʵ�֡�
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Hyperbola2 : public DistanceBase<Real, Vector2<Real>>
    {
    public:
        using ClassType = DistancePoint2Hyperbola2<Real>;
        using Vector2 = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint2Hyperbola2(const Vector2& point, const Vector2& extent) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector2 GetPoint() const noexcept;
        NODISCARD Vector2 GetExtent() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const override;

    private:
        NODISCARD Real GetHyperbola(Real t, const Vector2& reciprocalExtentSquared) const;

    private:
        Vector2 point;
        Vector2 extent;
    };

    using DistancePoint2Hyperbola2F = DistancePoint2Hyperbola2<float>;
    using DistancePoint2Hyperbola2D = DistancePoint2Hyperbola2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_H
