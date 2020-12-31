///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 14:34)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector2D.h"

#include <array>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Intersector1
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Intersector1<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;

    public:
        // ���[u0,u1]��[v0,v1]�������ࡣ
        // �յ��������u0 <= u1��v0 <= v1��
        // ����sm_MaxReal��-sm_MaxReal��ֵ��
        // �����˻������u0 = u1��v0 = v1��
        Intersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance()) noexcept;
        virtual ~Intersector1() = default;
        Intersector1(const Intersector1& rhs) noexcept = default;
        virtual Intersector1& operator=(const Intersector1& rhs) noexcept = default;
        Intersector1(Intersector1&& rhs) noexcept = default;
        virtual Intersector1& operator=(Intersector1&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] Real GetU(int index) const;
        [[nodiscard]] Real GetV(int index) const;

        [[nodiscard]] virtual bool IsIntersection() const = 0;

        [[nodiscard]] Real GetEpsilon() const noexcept;

    protected:
        virtual void Swap(Intersector1& rhs) noexcept;

    private:
        // �ཻ�ļ����
        Vector2D m_U;
        Vector2D m_V;

        Real m_Epsilon;
    };

    using FloatIntersector1 = Intersector1<float>;
    using DoubleIntersector1 = Intersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR1_H
