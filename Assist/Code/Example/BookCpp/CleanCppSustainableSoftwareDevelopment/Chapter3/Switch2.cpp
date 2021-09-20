///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/22 21:59)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "Switch2.h"
#include "Switchable.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, Switch2)

BookAdvanced::CleanCppSustainableSoftwareDevelopment::Switch2::Switch2(Switchable& switchable) noexcept
    : switchable(switchable)
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Switch2::Toggle()
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;

    if (state)
    {
        state = false;
        switchable.Off();
    }
    else
    {
        state = true;
        switchable.On();
    }
}