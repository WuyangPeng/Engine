/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:30)

#include "Mathematics/MathematicsExport.h"

#include "Int64Vector3.h"
#include "Detail/Int64Vector3Impl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

COPY_UNSHARED_CLONE_SELF_DEFINE(Mathematics, Int64Vector3)

Mathematics::Int64Vector3 Mathematics::Int64Vector3::CreateDefault()
{
    return Int64Vector3{ CoreTools::DisableNotThrow::Disable };
}

Mathematics::Int64Vector3::Int64Vector3(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector3::Int64Vector3(const Int64Vector<3>& rhs)
    : impl{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

Mathematics::Int64Vector3::Int64Vector3(int64_t x, int64_t y, int64_t z)
    : impl{ x, y, z }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

Mathematics::Int64Vector3& Mathematics::Int64Vector3::operator=(const Int64Vector<3>& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl = rhs;

    return *this;
}

#include SYSTEM_WARNING_POP

CLASS_INVARIANT_STUB_DEFINE(Mathematics, Int64Vector3)

int64_t Mathematics::Int64Vector3::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetX();
}

void Mathematics::Int64Vector3::SetX(int64_t x)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return impl->SetX(x);
}

int64_t Mathematics::Int64Vector3::GetY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetY();
}

void Mathematics::Int64Vector3::SetY(int64_t y)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return impl->SetY(y);
}

int64_t Mathematics::Int64Vector3::GetZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetZ();
}

void Mathematics::Int64Vector3::SetZ(int64_t z)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return impl->SetZ(z);
}

Mathematics::Int64Vector3 Mathematics::Int64Vector3::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto perp = -(*impl);

    return Int64Vector3{ perp.GetX(), perp.GetY(), perp.GetZ() };
}

Mathematics::Int64Vector3& Mathematics::Int64Vector3::operator+=(const Int64Vector3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl += *rhs.impl;

    return *this;
}

Mathematics::Int64Vector3& Mathematics::Int64Vector3::operator-=(const Int64Vector3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl -= *rhs.impl;

    return *this;
}

Mathematics::Int64Vector3& Mathematics::Int64Vector3::operator*=(int64_t scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl *= scalar;

    return *this;
}

Mathematics::Int64Vector3& Mathematics::Int64Vector3::operator/=(int64_t scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *impl /= scalar;

    return *this;
}

int64_t Mathematics::Int64Vector3::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->SquaredLength();
}

int64_t Mathematics::Int64Vector3::Dot(const Int64Vector3& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Mathematics::Dot(*impl, *rhs.impl);
}

bool Mathematics::Int64Vector3::operator==(const Int64Vector3& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *impl == *rhs.impl;
}

bool Mathematics::Int64Vector3::operator<(const Int64Vector3& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *impl < *rhs.impl;
}

Mathematics::Int64Vector3 Mathematics::Int64Vector3::Cross(const Int64Vector3& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto perp = Mathematics::Cross(*impl, *rhs.impl);

    return Int64Vector3{ perp.GetX(), perp.GetY(), perp.GetZ() };
}

int64_t Mathematics::Int64Vector3::TripleScalar(const Int64Vector3& mhs, const Int64Vector3& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Mathematics::TripleScalar(*impl, *mhs.impl, *rhs.impl);
}

std::ostream& Mathematics::operator<<(std::ostream& os, const Int64Vector3& rhs)
{
    os << "x = " << rhs.GetX() << " y = " << rhs.GetY() << " z = " << rhs.GetZ();

    return os;
}
