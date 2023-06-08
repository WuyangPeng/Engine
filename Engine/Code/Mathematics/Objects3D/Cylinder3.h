///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 15:44)

#ifndef MATHEMATICS_OBJECTS_3D_CYLINDER3_H
#define MATHEMATICS_OBJECTS_3D_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Line3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Cylinder3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Cylinder3<Real>;
        using Math = Math<Real>;
        using Line3 = Line3<Real>;

    public:
        // ����������һ���ߡ������ԭ�㱻ѡ��Ϊ��ԭ�㡣
        // ��������ھ�������Real��Ԫ�����޵ĸ��������޵ĸ߶ȡ�
        // һ�����޸������е�C���ߵ����;������޵ĸ߶�H
        // �߶�Ϊ����Բ����˵�C-(H/2)*D �� C+(H/2)*D������D���ߵĵ�λ���ȷ���
        Cylinder3(const Line3& axis, Real radius, Real height) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line3 GetAxis() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Real GetHeight() const noexcept;

    private:
        Line3 axis;
        Real radius;
        Real height;
    };

    using Cylinder3F = Cylinder3<float>;
    using Cylinder3D = Cylinder3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_CYLINDER3_H
