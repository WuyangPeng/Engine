///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/29 18:20)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "Chapter1Clazz.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

BookAdvanced::CleanCppSustainableSoftwareDevelopment::Chapter1Clazz::Chapter1Clazz() noexcept
    : attribute{}
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

BookAdvanced::CleanCppSustainableSoftwareDevelopment::Chapter1Clazz::~Chapter1Clazz() noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, Chapter1Clazz)

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Chapter1Clazz::DoSomething() noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Chapter1Clazz::Function() noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;
    // ...
}
