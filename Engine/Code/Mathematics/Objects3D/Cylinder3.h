///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 18:20)

#ifndef MATHEMATICS_OBJECTS3D_CYLINDER3_H
#define MATHEMATICS_OBJECTS3D_CYLINDER3_H

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

        [[nodiscard]] const Line3 GetAxis() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;
        [[nodiscard]] Real GetHeight() const noexcept;

    private:
        Line3 m_Axis;
        Real m_Radius;
        Real m_Height;
    };

    using FloatCylinder3 = Cylinder3<float>;
    using DoubleCylinder3 = Cylinder3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_CYLINDER3_H
