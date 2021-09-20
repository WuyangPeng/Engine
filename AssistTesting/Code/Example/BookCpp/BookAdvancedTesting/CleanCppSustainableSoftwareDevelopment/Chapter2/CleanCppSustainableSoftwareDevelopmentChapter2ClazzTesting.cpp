///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/11 13:40)

#include "CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h" 
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/Chapter2Clazz.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting::CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting)

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting::MainTest() noexcept
{
    MAYBE_UNUSED const Chapter2Clazz clazz{ 1 };
}
