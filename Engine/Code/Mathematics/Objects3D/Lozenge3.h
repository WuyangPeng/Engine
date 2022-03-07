///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/10 17:14)

#ifndef MATHEMATICS_OBJECTS3D_LOZENGE3_H
#define MATHEMATICS_OBJECTS3D_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Rectangle3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Lozenge3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Lozenge3<Real>;
        using Rectangle3 = Rectangle3<Real>;

    public:
        // ������һ���ǵȾ�ľ��εĵ㣬��ͬ�ľ����Ϊ�뾶��
        Lozenge3(const Rectangle3& rectangle, Real radius) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Rectangle3 GetRectangle() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

    private:
        Rectangle3 rectangle;
        Real radius;
    };

    using Lozenge3F = Lozenge3<float>;
    using Lozenge3D = Lozenge3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_LOZENGE3_H
