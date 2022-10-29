///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/14 1:18)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WideCharConversionUTF8Testing final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WideCharConversionUTF8Testing;
        using ParentType = UnitTest;

    public:
        explicit WideCharConversionUTF8Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WideCharConversionUTF8Test();
        NODISCARD std::string GetUTF8();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H