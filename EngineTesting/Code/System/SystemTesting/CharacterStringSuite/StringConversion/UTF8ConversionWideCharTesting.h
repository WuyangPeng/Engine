///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/01 13:14)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H

#include "ConversionWideCharTestingBase.h"

namespace System
{
    class UTF8ConversionWideCharTesting final : public ConversionWideCharTestingBase
    {
    public:
        using ClassType = UTF8ConversionWideCharTesting;
        using ParentType = ConversionWideCharTestingBase;

    public:
        explicit UTF8ConversionWideCharTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void UTF8ConversionWideCharTest();

    private:
        std::string multiByteInitial;
        int multiByteInitialLength;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H