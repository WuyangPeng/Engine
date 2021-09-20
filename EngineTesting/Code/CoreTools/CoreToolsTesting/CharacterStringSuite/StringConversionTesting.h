///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/30 14:03)

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
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_CONVERSION_TESTING_H