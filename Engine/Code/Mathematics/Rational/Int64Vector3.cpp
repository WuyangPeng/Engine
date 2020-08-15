// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:56)

#include "Mathematics/MathematicsExport.h"

#include "Int64Vector3.h"
#include "Detail/Int64Vector3Impl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iostream>

using std::ostream;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26455)
DELAY_COPY_CONSTRUCTION_DEFINE(Mathematics, Int64Vector3)

Mathematics::Int64Vector3
	::Int64Vector3()
	:m_Impl{ make_shared<ImplType>() }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector3
	::Int64Vector3(const Int64Vector<3>& rhs)
	:m_Impl{ make_shared<ImplType>(rhs) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector3
	::Int64Vector3(const int64_t& x, const int64_t& y, const int64_t& z)
	:m_Impl{ make_shared<ImplType>(x,y,z) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector3& Mathematics::Int64Vector3
	::operator=(const Int64Vector<3>& rhs)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl = rhs;

	return *this;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Mathematics, Int64Vector3)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Int64Vector3, GetX, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Int64Vector3, GetY, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Int64Vector3, GetZ, int64_t)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Mathematics, Int64Vector3, SetX, int64_t, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Mathematics, Int64Vector3, SetY, int64_t, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Mathematics, Int64Vector3, SetZ, int64_t, void)

const Mathematics::Int64Vector3 Mathematics::Int64Vector3
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	const auto impl = -(*m_Impl);

	return Int64Vector3{ impl.GetX(),impl.GetY(),impl.GetZ() };
}

Mathematics::Int64Vector3& Mathematics::Int64Vector3
	::operator+=(const Int64Vector3& rhs)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl += *rhs.m_Impl;

	return *this;
}

Mathematics::Int64Vector3& Mathematics::Int64Vector3
	::operator-=(const Int64Vector3& rhs)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl -= *rhs.m_Impl;

	return *this;
}

Mathematics::Int64Vector3&	Mathematics::Int64Vector3
	::operator*=(const int64_t& scalar)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl *= scalar;

	return *this;
}

Mathematics::Int64Vector3&	Mathematics::Int64Vector3
	::operator/=(const int64_t& scalar)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl /= scalar;

	return *this;
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Mathematics, Int64Vector3, SquaredLength, int64_t)

int64_t Mathematics::Int64Vector3
	::Dot(const Int64Vector3& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Mathematics::Dot(*m_Impl, *rhs.m_Impl);
}



bool Mathematics::Int64Vector3
::operator==(const Int64Vector3& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return *m_Impl == *rhs.m_Impl;
}

bool Mathematics::Int64Vector3
::operator<(const Int64Vector3& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return *m_Impl < *rhs.m_Impl;
}

Mathematics::Int64Vector3 Mathematics::Int64Vector3
::Cross(const Int64Vector3& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	const auto impl = Mathematics::Cross(*m_Impl, *rhs.m_Impl);

	return Int64Vector3{ impl.GetX(),impl.GetY(),impl.GetZ() };
}

int64_t Mathematics::Int64Vector3
::TripleScalar(const Int64Vector3& mhs, const Int64Vector3& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Mathematics::TripleScalar(*m_Impl, *mhs.m_Impl, *rhs.m_Impl);
}

ostream& Mathematics
::operator<<(ostream& os, const Int64Vector3& rhs)
{
	os << "x = " << rhs.GetX() << " y = " << rhs.GetY() << " z = " << rhs.GetZ();

	return os;
}

#include STSTEM_WARNING_POP