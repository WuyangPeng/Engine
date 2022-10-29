///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/14 1:17)

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
        NODISCARD std::string GetUTF8();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H