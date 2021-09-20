///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/22 21:59)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "EnumClass.h"
#include "EnumClassMain.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

#define ENUM_CLASS_COMPILER_ERROR
#undef ENUM_CLASS_COMPILER_ERROR

BookAdvanced::CleanCppSustainableSoftwareDevelopment::EnumClassMain::EnumClassMain() noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, EnumClassMain)

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::EnumClassMain::Main() const noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)
    constexpr Animal1 animal1 = Dog;
#include STSTEM_WARNING_POP

    MAYBE_UNUSED constexpr int aNumber1 = animal1;  // Implicit conversion:works

#ifdef ENUM_CLASS_COMPILER_ERROR
    constexpr Animal2 animal2 = Animal2::Dog;
    MAYBE_UNUSED constexpr int aNumber2 = animal2;  // Compiler error;
#endif  // ENUM_CLASS_COMPILER_ERROR
}
