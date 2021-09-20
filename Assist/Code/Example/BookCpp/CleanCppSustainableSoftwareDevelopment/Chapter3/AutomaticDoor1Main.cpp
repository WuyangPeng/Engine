///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/22 21:59)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "AutomaticDoor1.h"
#include "AutomaticDoor1Main.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

BookAdvanced::CleanCppSustainableSoftwareDevelopment::AutomaticDoor1Main::AutomaticDoor1Main() noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, AutomaticDoor1Main)

int BookAdvanced::CleanCppSustainableSoftwareDevelopment::AutomaticDoor1Main::Main() const noexcept
{
    AutomaticDoor1 automaticDoor{};
    const AutomaticDoor1::State doorsState = automaticDoor.GetState();
    if (doorsState == AutomaticDoor1::State::Closed)
    {
        // do something...
    }

    return 0;
}
