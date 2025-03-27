///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 16:04)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

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

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;

    public:
        // ���[u0,u1]��[v0,v1]�������ࡣ
        // �յ��������u0 <= u1��v0 <= v1��
        // ����sm_MaxReal��-sm_MaxReal��ֵ��
        // �����˻������u0 = u1��v0 = v1��
        Intersector1(Real u0, Real u1, Real v0, Real v1, Real epsilon = MathType::GetZeroTolerance()) noexcept;
        virtual ~Intersector1() = default;
        Intersector1(const Intersector1& rhs) noexcept = default;
        Intersector1& operator=(const Intersector1& rhs) noexcept = default;
        Intersector1(Intersector1&& rhs) noexcept = default;
        Intersector1& operator=(Intersector1&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD Real GetU(int index) const;
        NODISCARD Real GetV(int index) const;

        NODISCARD virtual bool IsIntersection() const = 0;

        NODISCARD Real GetEpsilon() const noexcept;

    protected:
        virtual void Swap(Intersector1& rhs) noexcept;

    private:
        // �ཻ�ļ����
        Vector2Type u;
        Vector2Type v;

        Real epsilon;
    };

    using Intersector1F = Intersector1<float>;
    using Intersector1D = Intersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR1_H
