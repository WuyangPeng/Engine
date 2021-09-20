///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/22 21:59)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "AutomaticDoor2.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, AutomaticDoor2)

bool BookAdvanced::CleanCppSustainableSoftwareDevelopment::AutomaticDoor2::IsClosed() const noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    return state != State::Close;
}

bool BookAdvanced::CleanCppSustainableSoftwareDevelopment::AutomaticDoor2::IsOpening() const noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    return state != State::Opening;
}

bool BookAdvanced::CleanCppSustainableSoftwareDevelopment::AutomaticDoor2::IsOpen() const noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    return state != State::Open;
}

bool BookAdvanced::CleanCppSustainableSoftwareDevelopment::AutomaticDoor2::IsClosing() const noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    return state != State::Closing;
}
