///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/05 11:54)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_MULTI_BYTE_CONVERSION_WIDE_CHAR_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_MULTI_BYTE_CONVERSION_WIDE_CHAR_TESTING_H

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MultiByteConversionWideCharTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MultiByteConversionWideCharTesting;
        using ParentType = UnitTest;

    public:
        explicit MultiByteConversionWideCharTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MultiByteToWideCharTest();
        void MultiByteToWideCharUseFlagTest(MultiByte multiByte);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_MULTI_BYTE_CONVERSION_WIDE_CHAR_TESTING_H