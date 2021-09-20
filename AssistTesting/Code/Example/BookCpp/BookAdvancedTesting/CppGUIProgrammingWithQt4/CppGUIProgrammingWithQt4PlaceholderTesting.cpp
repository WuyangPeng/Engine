///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:10)

#include "CppGUIProgrammingWithQt4PlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppGUIProgrammingWithQt4/Helper/CppGUIProgrammingWithQt4ClassInvariantMacro.h"

BookAdvanced::CppGUIProgrammingWithQt4::CppGUIProgrammingWithQt4PlaceholderTesting::CppGUIProgrammingWithQt4PlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_GUI_PROGRAMMING_WITH_QT4_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CppGUIProgrammingWithQt4, CppGUIProgrammingWithQt4PlaceholderTesting)

void BookAdvanced::CppGUIProgrammingWithQt4::CppGUIProgrammingWithQt4PlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::CppGUIProgrammingWithQt4::CppGUIProgrammingWithQt4PlaceholderTesting::MainTest() noexcept
{
}
