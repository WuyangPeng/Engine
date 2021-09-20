///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/02 22:59)

#include "CppHowToProgramSeventhEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppHowToProgramSeventhEdition/Helper/CppHowToProgramSeventhEditionClassInvariantMacro.h"

BookPrimary::CppHowToProgram::CppHowToProgramSeventhEditionPlaceholderTesting::CppHowToProgramSeventhEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_HOW_TO_PROGRAM_SEVENTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CppHowToProgram, CppHowToProgramSeventhEditionPlaceholderTesting)

void BookPrimary::CppHowToProgram::CppHowToProgramSeventhEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CppHowToProgram::CppHowToProgramSeventhEditionPlaceholderTesting::MainTest() noexcept
{
}
