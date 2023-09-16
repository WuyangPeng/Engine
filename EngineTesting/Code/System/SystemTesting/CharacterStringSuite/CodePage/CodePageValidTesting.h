///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:47)

#ifndef SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_VALID_TESTING_H
#define SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_VALID_TESTING_H

#include "System/CharacterString/CharacterStringFwd.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void ValidTest();

    private:
        using CodePageContainer = std::vector<CodePage>;

    private:
        CodePageContainer codePages;
    };
}

#endif  // SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_VALID_TESTING_H