// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:53)

#include "Mathematics/MathematicsExport.h"

#include "Int64Vector2.h"
#include "Detail/Int64Vector2Impl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iostream>

using std::ostream;
using std::make_shared;

DELAY_COPY_CONSTRUCTION_DEFINE(Mathematics, Int64Vector2)

Mathematics::Int64Vector2
	::Int64Vector2()
	:m_Impl{ make_shared<ImplType>() }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector2
	::Int64Vector2(const Int64Vector<2>& rhs)
	:m_Impl{ make_shared<ImplType>(rhs) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector2
	::Int64Vector2(const int64_t& x, const int64_t& y)
	:m_Impl{ make_shared<ImplType>(x,y) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector2& Mathematics::Int64Vector2
	::operator=(const Int64Vector<2>& rhs)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl = rhs;

	return *this;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics, Int64Vector2)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Int64Vector2, GetX, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Int64Vector2, GetY, int64_t)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Mathematics, Int64Vector2, SetX, int64_t, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Mathematics, Int64Vector2, SetY, int64_t, void)

const Mathematics::Int64Vector2
Mathematics::Int64Vector2
	::Perp() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto impl = m_Impl->Perp();

	return Int64Vector2{ impl.GetX(),impl.GetY() };
}

const Mathematics::Int64Vector2 Mathematics::Int64Vector2
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto impl = -(*m_Impl);

	return Int64Vector2{ impl.GetX(),impl.GetY() };
}

Mathematics::Int64Vector2& Mathematics::Int64Vector2
	::operator+=(const Int64Vector2& rhs)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl += *rhs.m_Impl;

	return *this;
}

Mathematics::Int64Vector2& Mathematics::Int64Vector2
	::operator-=(const Int64Vector2& rhs)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl -= *rhs.m_Impl;

	return *this;
}

Mathematics::Int64Vector2& Mathematics::Int64Vector2
	::operator*=(const int64_t& scalar)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl *= scalar;

	return *this;
}

Mathematics::Int64Vector2&	Mathematics::Int64Vector2
	::operator/=(const int64_t& scalar)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl /= scalar;

	return *this;
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Int64Vector2, SquaredLength, int64_t)

int64_t Mathematics::Int64Vector2
	::Dot(const Int64Vector2& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Mathematics::Dot(*m_Impl, *rhs.m_Impl);
}

int64_t Mathematics::Int64Vector2
	::DotPerp(const Int64Vector2& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Mathematics::DotPerp(*m_Impl, *rhs.m_Impl);
}

bool Mathematics::Int64Vector2
	::operator==(const Int64Vector2& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return *m_Impl == *rhs.m_Impl;
}

bool Mathematics::Int64Vector2
	::operator<(const Int64Vector2& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return *m_Impl < *rhs.m_Impl;
}

ostream& Mathematics
	::operator<<(ostream& os, const Int64Vector2& rhs)
{
	os << "x = " << rhs.GetX() << " y = " << rhs.GetY();

	return os;
}


