///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/09 21:29)

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
