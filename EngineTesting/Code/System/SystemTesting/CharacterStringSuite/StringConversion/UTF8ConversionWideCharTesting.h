///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:03)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H

#include "ConversionWideCharTestingBase.h"

namespace System
{
    class Utf8ConversionWideCharTesting final : public ConversionWideCharTestingBase
    {
    public:
        using ClassType = Utf8ConversionWideCharTesting;
        using ParentType = ConversionWideCharTestingBase;

    public:
        explicit Utf8ConversionWideCharTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void Utf8ConversionWideCharTest();

    private:
        std::string multiByteInitial;
        int multiByteInitialLength;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H