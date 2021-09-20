///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 17:28)

#include "Mathematics/MathematicsExport.h"

#include "Int64Vector2.h"
#include "Detail/Int64Vector2Impl.h"

#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include <iostream>

using std::make_shared;
using std::ostream;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Mathematics::Int64Vector2::Int64Vector2()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

Mathematics::Int64Vector2::Int64Vector2(const Int64Vector<2>& rhs)
    : impl{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector2::Int64Vector2(int64_t x, int64_t y)
    : impl{ x, y }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
Mathematics::Int64Vector2& Mathematics::Int64Vector2::operator=(const Int64Vector<2>& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl = rhs;

    return *this;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Int64Vector2)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Int64Vector2, GetX, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Mathematics, Int64Vector2, GetY, int64_t)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Int64Vector2, SetX, int64_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Mathematics, Int64Vector2, SetY, int64_t, void)

const Mathematics::Int64Vector2 Mathematics::Int64Vector2 ::Perp() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto perp = impl->Perp();

    return Int64Vector2{ perp.GetX(), perp.GetY() };
}

const Mathematics::Int64Vector2 Mathematics::Int64Vector2::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto perp = -(*impl);

    return Int64Vector2{ perp.GetX(), perp.GetY() };
}

Mathematics::Int64Vector2& Mathematics::Int64Vector2::operator+=(const Int64Vector2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl += *rhs.impl;

    return *this;
}

Mathematics::Int64Vector2& Mathematics::Int64Vector2::operator-=(const Int64Vector2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl -= *rhs.impl;

    return *this;
}

Mathematics::Int64Vector2& Mathematics::Int64Vector2::operator*=(int64_t scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl *= scalar;

    return *this;
}

Mathematics::Int64Vector2& Mathematics::Int64Vector2::operator/=(int64_t scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl /= scalar;

    return *this;
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Mathematics, Int64Vector2, SquaredLength, int64_t)

int64_t Mathematics::Int64Vector2::Dot(const Int64Vector2& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Mathematics::Dot(*impl, *rhs.impl);
}

int64_t Mathematics::Int64Vector2::DotPerp(const Int64Vector2& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Mathematics::DotPerp(*impl, *rhs.impl);
}

bool Mathematics::Int64Vector2::operator==(const Int64Vector2& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *impl == *rhs.impl;
}

bool Mathematics::Int64Vector2::operator<(const Int64Vector2& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *impl < *rhs.impl;
}

ostream& Mathematics::operator<<(ostream& os, const Int64Vector2& rhs)
{
    os << "x = " << rhs.GetX() << " y = " << rhs.GetY();

    return os;
}
COPY_UNSHARED_CLONE_SELF_DEFINE(Mathematics, Int64Vector2)