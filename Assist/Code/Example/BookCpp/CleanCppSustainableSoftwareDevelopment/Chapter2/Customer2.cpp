///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/09 21:20)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "Customer2.h"
#include "CustomerDAO.h"
#include "FakeDAOForTest.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, Customer2)

BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer2::Customer2() noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer2::Customer2(bool testMode) noexcept
    : inTestMode(testMode)
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer2::Save()
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;

    DataAccessObjectPtr dataAccessObject = GetDataAccessObject();
    // ... use dataAccessObject to save this customer...
}

BookAdvanced::CleanCppSustainableSoftwareDevelopment::DataAccessObjectPtr BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer2::GetDataAccessObject() const
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    if (inTestMode)
    {
        return std::make_unique<FakeDAOForTest>();
    }
    else
    {
        return std::make_unique<CustomerDAO>();
    }
}
