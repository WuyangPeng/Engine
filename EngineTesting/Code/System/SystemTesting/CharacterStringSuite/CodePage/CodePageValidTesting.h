///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 0:49)

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
        void DoRunUnitTest() final;
        void MainTest();

        void ValidTest();

    private:
        using CodePageFlagsContainer = std::vector<CodePage>;

    private:
        CodePageFlagsContainer codePageFlags;
    };
}

#endif  // SYSTEM_TESTING_CHARACTER_STRING_SUITE_CODE_PAGE_VALID_TESTING_H