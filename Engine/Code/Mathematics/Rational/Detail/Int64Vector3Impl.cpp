///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 14:08)

#include "Mathematics/MathematicsExport.h"

#include "Int64Vector3Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Rational/Int64VectorDetail.h"

Mathematics::Int64Vector3Impl::Int64Vector3Impl() noexcept
    : m_Tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector3Impl::Int64Vector3Impl(const Int64Vector<3>& rhs) noexcept
    : m_Tuple{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector3Impl::Int64Vector3Impl(int64_t x, int64_t y, int64_t z) noexcept
    : m_Tuple{ x, y, z }
{
    
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector3Impl& Mathematics::Int64Vector3Impl::operator=(const Int64Vector<3>& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple = rhs;

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Int64Vector3Impl)

int64_t Mathematics::Int64Vector3Impl::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Tuple[0];
}

int64_t Mathematics::Int64Vector3Impl::GetY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Tuple[1];
}

int64_t Mathematics::Int64Vector3Impl::GetZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Tuple[2];
}

void Mathematics::Int64Vector3Impl::SetX(int64_t x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple[0] = x;
}

void Mathematics::Int64Vector3Impl::SetY(int64_t y)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple[1] = y;
}

void Mathematics::Int64Vector3Impl::SetZ(int64_t z)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple[2] = z;
}

const Mathematics::Int64Vector3Impl Mathematics::Int64Vector3Impl::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Int64Vector3Impl{ -m_Tuple };
}

Mathematics::Int64Vector3Impl& Mathematics::Int64Vector3Impl::operator+=(const Int64Vector3Impl& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple += rhs.m_Tuple;

    return *this;
}

Mathematics::Int64Vector3Impl& Mathematics::Int64Vector3Impl::operator-=(const Int64Vector3Impl& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple -= rhs.m_Tuple;

    return *this;
}

Mathematics::Int64Vector3Impl& Mathematics::Int64Vector3Impl::operator*=(int64_t scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple *= scalar;

    return *this;
}

Mathematics::Int64Vector3Impl& Mathematics::Int64Vector3Impl::operator/=(int64_t scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple /= scalar;

    return *this;
}

int64_t Mathematics::Int64Vector3Impl ::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Tuple.SquaredLength();
}

int64_t Mathematics::Dot(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs)
{
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
}

Mathematics::Int64Vector3Impl Mathematics::Cross(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs)
{
    return Int64Vector3Impl{ lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
                             lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
                             lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX() };
}

int64_t Mathematics::TripleScalar(const Int64Vector3Impl& lhs, const Int64Vector3Impl& mhs, const Int64Vector3Impl& rhs)
{
    return Dot(lhs, Cross(mhs, rhs));
}

bool Mathematics::operator==(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs)
{
    return lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY() && lhs.GetZ() == rhs.GetZ();
}

bool Mathematics::operator<(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs)
{
    if (lhs.GetX() < rhs.GetX())
        return true;
    else if (rhs.GetX() < lhs.GetX())
        return false;
    else if (lhs.GetY() < rhs.GetY())
        return true;
    else if (rhs.GetY() < lhs.GetY())
        return false;
    else if (lhs.GetZ() < rhs.GetZ())
        return true;
    else
        return false;
}
