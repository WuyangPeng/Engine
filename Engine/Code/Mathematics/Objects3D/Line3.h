///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 16:22)

#ifndef MATHEMATICS_OBJECTS3D_LINE3_H
#define MATHEMATICS_OBJECTS3D_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Line3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Line3<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;

    public:
        // 线表示为P+t*D，其中P是线原点，D是单位长度的方向向量，t是任意实数。
        // 用户必须确保D是单位长度。
        Line3(const Vector3D& origin, const Vector3D& direction, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetOrigin() const noexcept;
        [[nodiscard]] const Vector3D GetDirection() const noexcept;

        [[nodiscard]] const Line3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        Vector3D m_Origin;
        Vector3D m_Direction;
        Real m_Epsilon;
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Line3<Real>& lhs, const Line3<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Line3<Real>& line);

    using FloatLine3 = Line3<float>;
    using DoubleLine3 = Line3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_LINE3_H
