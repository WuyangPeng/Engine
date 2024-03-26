/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 00:00)

#include "Mathematics/MathematicsExport.h"

#include "UIntegerArbitraryPrecision32.h"
#include "Detail/UIntegerArbitraryPrecision32Impl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Mathematics, UIntegerArbitraryPrecision32)

Mathematics::UIntegerArbitraryPrecision32 Mathematics::UIntegerArbitraryPrecision32::CreateZero()
{
    return UIntegerArbitraryPrecision32{ CoreTools::DisableNotThrow::Disable };
}

Mathematics::UIntegerArbitraryPrecision32::UIntegerArbitraryPrecision32(uint32_t number)
    : ParentType{}, impl{ number }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::UIntegerArbitraryPrecision32::UIntegerArbitraryPrecision32(uint64_t number)
    : ParentType{}, impl{ number }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::UIntegerArbitraryPrecision32::UIntegerArbitraryPrecision32(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, UIntegerArbitraryPrecision32)

void Mathematics::UIntegerArbitraryPrecision32::SetNumBits(int numBits)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return impl->SetNumBits(numBits);
}

int Mathematics::UIntegerArbitraryPrecision32::GetNumBits() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetNumBits();
}

const Mathematics::UIntegerArbitraryPrecision32::BitsType& Mathematics::UIntegerArbitraryPrecision32::GetBits() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetBits();
}

Mathematics::UIntegerArbitraryPrecision32::BitsType& Mathematics::UIntegerArbitraryPrecision32::GetBits()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return impl->GetBits();
}

void Mathematics::UIntegerArbitraryPrecision32::SetBack(uint32_t value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return impl->SetBack(value);
}

uint32_t Mathematics::UIntegerArbitraryPrecision32::GetBack() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetBack();
}

int Mathematics::UIntegerArbitraryPrecision32::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetSize();
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26497)

int Mathematics::UIntegerArbitraryPrecision32::GetMaxSize() noexcept
{
    return ImplType::GetMaxSize();
}

#include SYSTEM_WARNING_POP

void Mathematics::UIntegerArbitraryPrecision32::SetAllBitsToZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return impl->SetAllBitsToZero();
}

bool Mathematics::UIntegerArbitraryPrecision32::Write(std::ostream& output) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->Write(output);
}

bool Mathematics::UIntegerArbitraryPrecision32::Read(std::istream& input)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return impl->Read(input);
}

const Mathematics::UIntegerArbitraryPrecision32& Mathematics::UIntegerArbitraryPrecision32::GetSelf() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this;
}

Mathematics::UIntegerArbitraryPrecision32& Mathematics::UIntegerArbitraryPrecision32::GetSelf() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return *this;
}
