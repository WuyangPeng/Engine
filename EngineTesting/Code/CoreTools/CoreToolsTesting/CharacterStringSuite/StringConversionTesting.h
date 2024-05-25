/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 14:48)

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
        void ChineseMultiByteConversionWideCharTest();
        void WideCharConversionMultiByteTest();
        void ChineseWideCharConversionMultiByteTest();

        void StandardConversionWideCharTest();
        void ChineseStandardConversionWideCharTest();
        void StandardConversionMultiByteTest();
        void ChineseStandardConversionMultiByteTest();
        void MultiByteConversionStandardTest();
        void ChineseMultiByteConversionStandardTest();
        void WideCharConversionStandardTest();
        void ChineseWideCharConversionStandardTest();

        void StandardConversionDynamicLinkStringTest();
        void ChineseStandardConversionDynamicLinkStringTest();
        void DynamicLinkStringConversionMultiByteTest();
        void ChineseDynamicLinkStringConversionMultiByteTest();
        void DynamicLinkStringConversionStandardTest();
        void ChineseDynamicLinkStringConversionStandardTest();

        void StandardConversionCFileStringTest();
        void ChineseStandardConversionCFileStringTest();

        void Utf8ConversionWideCharTest();
        void ChineseUtf8ConversionWideCharTest();
        void Utf8ConversionStandardTest();
        void ChineseUtf8ConversionStandardTest();
        void Utf8ConversionMultiByteTest();
        void ChineseUtf8ConversionMultiByteTest();

        void WideCharUtf8ConversionStandardTest();
        void WideCharUtf8ConversionStandardEnglishTest();
        void WideCharUtf8ConversionStandardChineseTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_CONVERSION_TESTING_H