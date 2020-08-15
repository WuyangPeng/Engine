// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:51)

#include "Mathematics/MathematicsExport.h"

#include "Int64Vector2Impl.h"
#include "Mathematics/Rational/Int64VectorDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::Int64Vector2Impl
	::Int64Vector2Impl() noexcept
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector2Impl
	::Int64Vector2Impl(const Int64Vector<2>& rhs) noexcept
	:m_Tuple{ rhs }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector2Impl
	::Int64Vector2Impl(const int64_t& x, const int64_t& y)
	:m_Tuple{}
{
	m_Tuple[0] = x;
	m_Tuple[1] = y;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl
	::operator=(const Int64Vector<2>& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple = rhs;

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Int64Vector2Impl)

int64_t Mathematics::Int64Vector2Impl
	::GetX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

int64_t Mathematics::Int64Vector2Impl
	::GetY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

void Mathematics::Int64Vector2Impl
	::SetX(const int64_t& x)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
}

void Mathematics::Int64Vector2Impl
	::SetY(const int64_t& y)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = y;
}

const Mathematics::Int64Vector2Impl Mathematics::Int64Vector2Impl
	::Perp() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Int64Vector2Impl{ m_Tuple[1], -m_Tuple[0] };
}

const Mathematics::Int64Vector2Impl Mathematics::Int64Vector2Impl ::operator-() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return -m_Tuple;
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl
	::operator+=(const Int64Vector2Impl& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple += rhs.m_Tuple;

	return *this;
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl
	::operator-=(const Int64Vector2Impl& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple -= rhs.m_Tuple;

	return *this;
}

Mathematics::Int64Vector2Impl& Mathematics::Int64Vector2Impl
	::operator*=(const int64_t& scalar) noexcept
{ 
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple *= scalar;

	return *this;
}

Mathematics::Int64Vector2Impl&	Mathematics::Int64Vector2Impl
	::operator/=(const int64_t& scalar)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple /= scalar;

	return *this;
}

int64_t Mathematics::Int64Vector2Impl
	::SquaredLength() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple.SquaredLength();
}

int64_t Mathematics
	::Dot(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs)
{
	return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY();
}

int64_t Mathematics
	::DotPerp(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs)
{
	return lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX();
}

bool Mathematics
	::operator==(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs)
{
	return lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY();
}

bool Mathematics
	::operator<(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs)
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

