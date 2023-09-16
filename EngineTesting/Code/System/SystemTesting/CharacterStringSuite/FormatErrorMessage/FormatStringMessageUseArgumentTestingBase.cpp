///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:10)

#include "FormatStringMessageUseArgumentTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<WindowsDWordPtrSizeType>(argument);

#include SYSTEM_WARNING_POP
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatStringMessageUseArgumentTestingBase)

System::String System::FormatStringMessageUseArgumentTestingBase::GetMessageFormat()
{
    return SYSTEM_TEXT("%1!*.*s! %4 %5!*s!");
}

System::String System::FormatStringMessageUseArgumentTestingBase::GetMessageFormatResult()
{
    // "%1!*.*s!"������4 3 "Bill"��ʽ��" Bil"
    // "%5!*s!"������6 "Bill"��ʽ��"  Bill"
    return SYSTEM_TEXT(" Bil Bob   Bill");
}

System::String System::FormatStringMessageUseArgumentTestingBase::GetMessageVaList()
{
    return SYSTEM_TEXT("%1!*.*s! %3 %4!*s!");
}

System::String System::FormatStringMessageUseArgumentTestingBase::GetMessageVaListResult()
{
    return SYSTEM_TEXT("  Bi Bob   Bill");
}

System::WindowsDWordPtrSizeType* System::FormatStringMessageUseArgumentTestingBase::GetArgumentsData() noexcept
{
    SYSTEM_CLASS_IS_VALID_1;

    return arguments.data();
}
