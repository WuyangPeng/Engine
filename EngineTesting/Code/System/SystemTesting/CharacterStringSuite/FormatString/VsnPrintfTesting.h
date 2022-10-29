///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 1:16)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINTF_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINTF_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class VsnPrintfTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = VsnPrintfTesting;
        using ParentType = UnitTest;

    public:
        explicit VsnPrintfTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void VsnprintfTest();

        void DoVsnprintfTest(int testStringSize, char* buffer, size_t size, const char* format, ...);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINTF_TESTING_H