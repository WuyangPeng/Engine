/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_LINE3_H
#define MATHEMATICS_OBJECTS_3D_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Primitives/Line.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Line3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Line3<Real>;

        using MathType = Math<Real>;
        using Vector3 = Vector3<Real>;
        using AlgebraLine3 = Algebra::Line3<Real>;

    public:
        // 线表示为P+t*D，其中P是线原点，D是单位长度的方向向量，t是任意实数。
        // 用户必须确保D是单位长度。
        Line3(const Vector3& origin, const Vector3& direction, Real epsilon = MathType::GetZeroTolerance()) noexcept;
        explicit Line3(const AlgebraLine3& line, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetOrigin() const noexcept;
        NODISCARD Vector3 GetDirection() const noexcept;

        NODISCARD Line3 GetMove(Real t, const Vector3& velocity) const;

    private:
        Vector3 origin;
        Vector3 direction;
        Real epsilon;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Line3<Real>& lhs, const Line3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Line3<Real>& line);

    using Line3F = Line3<float>;
    using Line3D = Line3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_LINE3_H
