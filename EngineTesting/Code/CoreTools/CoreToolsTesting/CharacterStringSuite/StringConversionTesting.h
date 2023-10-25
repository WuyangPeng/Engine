///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 17:27)

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
        void DoRunUnitTest() override;
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

        void Utf8ConversionWideCharTest();
        void Utf8ConversionStandardTest();
        void Utf8ConversionMultiByteTest();

        void WideCharUtf8ConversionStandardTest();
        void WideCharUtf8ConversionStandardEnglishTest();
        void WideCharUtf8ConversionStandardChineseTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_CONVERSION_TESTING_H