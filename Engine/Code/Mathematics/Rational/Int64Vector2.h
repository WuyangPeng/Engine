/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:28)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR2_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR2_H

#include "Mathematics/MathematicsDll.h"

#include "Int64Vector.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iosfwd>

MATHEMATICS_DELAY_COPY_UNSHARED_EXPORT_IMPL(Int64Vector2, Int64Vector2Impl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE Int64Vector2 final : private boost::additive<Int64Vector2, boost::totally_ordered<Int64Vector2, boost::multiplicative<Int64Vector2, int64_t>>>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(Int64Vector2);

    private:
        explicit Int64Vector2(CoreTools::DisableNotThrow disableNotThrow);

    public:
        NODISCARD static Int64Vector2 CreateDefault();

        explicit Int64Vector2(const Int64Vector<2>& rhs);
        Int64Vector2(int64_t x, int64_t y);

        Int64Vector2& operator=(const Int64Vector<2>& rhs);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int64_t GetX() const;
        void SetX(int64_t x);
        NODISCARD int64_t GetY() const;
        void SetY(int64_t y);

        // 返回 (y,-x).
        NODISCARD Int64Vector2 Perp() const;

        NODISCARD Int64Vector2 operator-() const;

        Int64Vector2& operator+=(const Int64Vector2& rhs);
        Int64Vector2& operator-=(const Int64Vector2& rhs);
        Int64Vector2& operator*=(int64_t scalar);
        Int64Vector2& operator/=(int64_t scalar);

        NODISCARD int64_t SquaredLength() const noexcept;

        // 返回 Dot(lhs,rhs).
        NODISCARD int64_t Dot(const Int64Vector2& rhs) const;

        // 返回 Cross((lhs.x,lhs.y,0),(rhs.x,rhs.y,0)) = lhs.x*rhs.y - lhs.y*rhs.x.
        NODISCARD int64_t DotPerp(const Int64Vector2& rhs) const;

        NODISCARD bool operator==(const Int64Vector2& rhs) const;
        NODISCARD bool operator<(const Int64Vector2& rhs) const;

    private:
        PackageType impl;
    };

    MATHEMATICS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const Int64Vector2& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INT64_VECTOR2_H
