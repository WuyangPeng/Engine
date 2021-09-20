///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "Customer1.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, Customer1)

std::string BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer1::GetForename() const
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    return forename;
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Customer1::SetForename(const std::string& forename0)
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;

    this->forename = forename0;
}
