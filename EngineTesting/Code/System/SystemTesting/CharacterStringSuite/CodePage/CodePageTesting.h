///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/03 14:27)

#ifndef SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_TESTING_H
#define SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_TESTING_H

#include "System/CharacterString/Flags/CodePageFlags.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CodePageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CodePageTesting;
        using ParentType = UnitTest;

    public:
        explicit CodePageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ANSICodePageTest();
        void OEMCodePageTest();
    };
}

#endif  // SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_TESTING_H