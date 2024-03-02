/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/23 15:25)

#ifndef MATHEMATICS_OBJECTS_3D_CYLINDER3_H
#define MATHEMATICS_OBJECTS_3D_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Line3.h"
#include "Mathematics/Primitives/Line.h"

#include <type_traits>

namespace Mathematics
{
    /// Բ��������һ��ֱ�ߡ�
    /// Բ�����ԭ�㱻ѡ��Ϊֱ��ԭ�㡣
    /// ���ױ�����ľ���ΪR����λ��
    /// ���޵�Բ���������޵ĸ߶ȡ�
    /// ����Բ���������C��ֱ��ԭ�㴦�����Ҿ������޸߶�H��
    /// ����Բ������߶ξ��ж˵�C-(H/2)*D ��C+(H/2)*D��
    /// ����D��ֱ�ߵĵ�λ���ȷ���
    ///
    /// ע�⣺һЩ���β�ѯ�漰����Բ���塣
    /// Ϊ��֧�־�ȷ��������
    /// �б�Ҫ����std::numeric_limits��Ա����infinity()�� max()��
    /// �෴����ѯҪ����������Բ����ġ��߶ȡ�����Ϊ-1��
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Cylinder3 final
    {
    public:
        using ClassType = Cylinder3<Real>;

        using Math = Math<Real>;
        using Line3 = Line3<Real>;
        using Vector3 = Vector3<Real>;
        using AlgebraLine3 = Algebra::Line3<Real>;

    public:
        /// Ĭ�Ϲ��캯����������Ϊ(0,0,1)�����뾶����Ϊ1�����߶�����Ϊ1��
        Cylinder3() noexcept;

        /// ����������һ���ߡ������ԭ�㱻ѡ��Ϊ��ԭ�㡣
        /// ��������ھ�������Real��Ԫ�����޵ĸ��������޵ĸ߶ȡ�
        /// һ�����޸������е�C���ߵ����;������޵ĸ߶�H
        /// �߶�Ϊ����Բ����˵�C-(H/2)*D �� C+(H/2)*D������D���ߵĵ�λ���ȷ���
        Cylinder3(const Line3& axis, Real radius, Real height) noexcept;
        Cylinder3(const AlgebraLine3& axis, Real radius, Real height);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line3 GetAxis() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Real GetHeight() const noexcept;
        NODISCARD AlgebraLine3 GetAlgebraAxis() const noexcept;

        // ���Ķ����ļ���ͷ����Ϊ����Բ�������á��߶ȡ�������ע�͡�
        void MakeInfiniteCylinder() noexcept;

        void MakeFiniteCylinder(Real aHeight) noexcept;

        NODISCARD bool IsFinite() const noexcept;

        NODISCARD bool IsInfinite() const noexcept;

    private:
        Line3 axis;
        Real radius;
        Real height;
    };

    /// ��֧�����������ıȽϡ�
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    using Cylinder3F = Cylinder3<float>;
    using Cylinder3D = Cylinder3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_CYLINDER3_H
