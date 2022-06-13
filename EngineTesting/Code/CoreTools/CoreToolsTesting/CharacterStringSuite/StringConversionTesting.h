///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:41)

#ifndef CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_CONVERSION_TESTING_H
#define CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_CONVERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StringConversionTesting final : public UnitTest
    {
    public:
        using ClassType = StringConversionTesting;
        using ParentType = UnitTest;

    public:
        explicit StringConversionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MultiByteConversionWideCharTest();
        void WideCharConversionMultiByteTest();
        void StandardConversionWideCharTest();
        void StandardConversionMultiByteTest();
        void MultiByteConversionStandardTest();
        void WideCharConversionStandardTest();

        void StandardConversionDynamicLinkStringTest();
        void DynamicLinkStringConversionMultiByteTest();
        void DynamicLinkStringConversionStandardTest();

        void StandardConversionCFileStringTest();

        void UTF8ConversionWideCharTest();
        void UTF8ConversionStandardTest();
        void UTF8ConversionMultiByteTest();
        void WideCharUTF8ConversionStandardTest();

        void ToFirstLetterUpperTest();
        void ToFirstLetterLowerTest();
        void ToUpperMacroTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_CONVERSION_TESTING_H