///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/29 22:17)

#include "FormatStringMessageUseArgumentTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::FormatStringMessageUseArgumentTestingBase::FormatStringMessageUseArgumentTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      arguments{ boost::numeric_cast<WindowsDWordPtrSizeType>(4),
                 boost::numeric_cast<WindowsDWordPtrSizeType>(3),
                 ReinterpretCast(SYSTEM_TEXT("Bill")),
                 ReinterpretCast(SYSTEM_TEXT("Bob")),
                 boost::numeric_cast<WindowsDWordPtrSizeType>(6),
                 ReinterpretCast(SYSTEM_TEXT("Bill")) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::WindowsDWordPtrSizeType System::FormatStringMessageUseArgumentTestingBase::ReinterpretCast(const TChar* argument) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<WindowsDWordPtrSizeType>(argument);

#include STSTEM_WARNING_POP
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatStringMessageUseArgumentTestingBase)

System::String System::FormatStringMessageUseArgumentTestingBase::GetMessageFormat()
{
    return SYSTEM_TEXT("%1!*.*s! %4 %5!*s!"s);
}

System::String System::FormatStringMessageUseArgumentTestingBase::GetMessageFormatResult()
{
    // "%1!*.*s!"，根据4 3 "Bill"格式化" Bil"
    // "%5!*s!"，根据6 "Bill"格式化"  Bill"
    return SYSTEM_TEXT(" Bil Bob   Bill"s);
}

System::String System::FormatStringMessageUseArgumentTestingBase::GetMessageVaList()
{
    return SYSTEM_TEXT("%1!*.*s! %3 %4!*s!"s);
}

System::String System::FormatStringMessageUseArgumentTestingBase::GetMessageVaListResult()
{
    return SYSTEM_TEXT("  Bi Bob   Bill"s);
}

System::WindowsDWordPtrSizeType* System::FormatStringMessageUseArgumentTestingBase::GetArgumentsData() noexcept
{
    SYSTEM_CLASS_IS_VALID_1;

    return arguments.data();
}
