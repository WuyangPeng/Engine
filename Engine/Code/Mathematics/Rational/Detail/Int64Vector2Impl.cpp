///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:03)

#include "Mathematics/MathematicsExport.h"

#include "Int64Vector2Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Rational/Int64VectorDetail.h"

Mathematics::Int64Vector2Impl::Int64Vector2Impl() noexcept
    : tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector2Impl::Int64Vector2Impl(const Int64Vector<2>& rhs) noexcept
    : tuple{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector2Impl::Int64Vector2Impl(int64_t x, int64_t y) noexcept
    : tuple{ x, y }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl::operator=(const Int64Vector<2>& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple = rhs;

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Int64Vector2Impl)

int64_t Mathematics::Int64Vector2Impl::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple[0];
}

int64_t Mathematics::Int64Vector2Impl::GetY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple[1];
}

void Mathematics::Int64Vector2Impl::SetX(int64_t x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple[0] = x;
}

void Mathematics::Int64Vector2Impl::SetY(int64_t y)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple[1] = y;
}

Mathematics::Int64Vector2Impl Mathematics::Int64Vector2Impl::Perp() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Int64Vector2Impl{ tuple[1], -tuple[0] };
}

Mathematics::Int64Vector2Impl Mathematics::Int64Vector2Impl::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Int64Vector2Impl{ -tuple };
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl::operator+=(const Int64Vector2Impl& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple += rhs.tuple;

    return *this;
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl::operator-=(const Int64Vector2Impl& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple -= rhs.tuple;

    return *this;
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl::operator*=(int64_t scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple *= scalar;

    return *this;
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl::operator/=(int64_t scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple /= scalar;

    return *this;
}

int64_t Mathematics::Int64Vector2Impl::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple.SquaredLength();
}

int64_t Mathematics::Dot(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs)
{
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY();
}

int64_t Mathematics::DotPerp(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs)
{
    return lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX();
}

bool Mathematics::operator==(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs)
{
    return lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY();
}

bool Mathematics::operator<(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs)
{
    if (lhs.GetX() < rhs.GetX())
        return true;
    else if (rhs.GetX() < lhs.GetX())
        return false;
    else if (lhs.GetY() < rhs.GetY())
        return true;
    else
        return false;
}
