///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/09 21:29)

#include "HackersDelightPrintItselfTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/HackersDelight/Helper/HackersDelightClassInvariantMacro.h"
#include "Example/BookCpp/HackersDelight/Preface/PrintItself.h"

BookAlgorithm::HackersDelight::HackersDelightPrintItselfTesting::HackersDelightPrintItselfTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    HACKERS_DELIGHT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::HackersDelight, HackersDelightPrintItselfTesting)

void BookAlgorithm::HackersDelight::HackersDelightPrintItselfTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::HackersDelight::HackersDelightPrintItselfTesting::MainTest() noexcept
{
    const PrintItself printItself{};

    printItself.Main();
}
