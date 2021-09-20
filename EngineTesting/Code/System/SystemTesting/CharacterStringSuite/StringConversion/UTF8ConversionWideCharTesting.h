///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/06 11:22)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class UTF8ConversionWideCharTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = UTF8ConversionWideCharTesting;
        using ParentType = UnitTest;

    public:
        explicit UTF8ConversionWideCharTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void UTF8ConversionWideCharTest();
        std::string GetUTF8();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H