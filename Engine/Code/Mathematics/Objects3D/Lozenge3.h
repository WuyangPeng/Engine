///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/17 17:44)

#ifndef MATHEMATICS_OBJECTS3D_LOZENGE3_H
#define MATHEMATICS_OBJECTS3D_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Rectangle3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Lozenge3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Lozenge3<Real>;
        using Rectangle3 = Rectangle3<Real>;

    public:
        // ������һ���ǵȾ�ľ��εĵ㣬��ͬ�ľ����Ϊ�뾶��
        Lozenge3(const Rectangle3& rectangle, Real radius) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Rectangle3 GetRectangle() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;

    private:
        Rectangle3 m_Rectangle;
        Real m_Radius;
    };

    using FloatLozenge3 = Lozenge3<float>;
    using DoubleLozenge3 = Lozenge3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_LOZENGE3_H
