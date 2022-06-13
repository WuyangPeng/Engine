///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:06)

#ifndef SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_VALID_TESTING_H
#define SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_VALID_TESTING_H

#include "System/CharacterString/Flags/CodePageFlags.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CodePageValidTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CodePageValidTesting;
        using ParentType = UnitTest;

    public:
        explicit CodePageValidTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ValidTest();

    private:
        using CodePageFlagsCollection = std::vector<CodePage>;

    private:
        CodePageFlagsCollection codePageFlags;
    };
}

#endif  // SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_VALID_TESTING_H