///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/09 21:20)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "Customer4.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, Customer4)

BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer4::Customer4(DataAccessObject& dataAccessObject) noexcept
    : dataAccessObject{ dataAccessObject }
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer4::Save() noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;

    // ...use dataAccessObject to save this customer...
}
