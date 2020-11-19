///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 17:26)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR2_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR2_H

#include "Mathematics/MathematicsDll.h"

#include "Int64Vector.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iosfwd>

MATHEMATICS_EXPORT_SHARED_PTR(Int64Vector2Impl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE Int64Vector2 final : private boost::additive<Int64Vector2, boost::totally_ordered<Int64Vector2, boost::multiplicative<Int64Vector2, int64_t>>>
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Int64Vector2);

    public:
        Int64Vector2();
        explicit Int64Vector2(const Int64Vector<2>& rhs);
        Int64Vector2(int64_t x, int64_t y);

        Int64Vector2& operator=(const Int64Vector<2>& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int64_t GetX() const;
        void SetX(int64_t x);
        [[nodiscard]] int64_t GetY() const;
        void SetY(int64_t y);

        // 返回 (y,-x).
        [[nodiscard]] const Int64Vector2 Perp() const;

        [[nodiscard]] const Int64Vector2 operator-() const;

        Int64Vector2& operator+=(const Int64Vector2& rhs);
        Int64Vector2& operator-=(const Int64Vector2& rhs);
        Int64Vector2& operator*=(int64_t scalar);
        Int64Vector2& operator/=(int64_t scalar);

        [[nodiscard]] int64_t SquaredLength() const noexcept;

        // 返回 Dot(lhs,rhs).
        [[nodiscard]] int64_t Dot(const Int64Vector2& rhs) const;

        // 返回 Cross((lhs.x,lhs.y,0),(rhs.x,rhs.y,0)) = lhs.x*rhs.y - lhs.y*rhs.x.
        [[nodiscard]] int64_t DotPerp(const Int64Vector2& rhs) const;

        [[nodiscard]] bool operator==(const Int64Vector2& rhs) const;
        [[nodiscard]] bool operator<(const Int64Vector2& rhs) const;

    private:
        IMPL_TYPE_DECLARE(Int64Vector2);
    };

    MATHEMATICS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const Int64Vector2& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INT64_VECTOR2_H
