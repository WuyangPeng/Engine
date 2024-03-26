/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_MULTI_BYTE_CONVERSION_WIDE_CHAR_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_MULTI_BYTE_CONVERSION_WIDE_CHAR_TESTING_H

#include "ConversionWideCharTestingBase.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

#include <string>

namespace System
{
    class MultiByteConversionWideCharTesting final : public ConversionWideCharTestingBase
    {
    public:
        using ClassType = MultiByteConversionWideCharTesting;
        using ParentType = ConversionWideCharTestingBase;

    public:
        explicit MultiByteConversionWideCharTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MultiByteToWideCharTest();
        void MultiByteToWideCharUseFlagTest(MultiByte multiByte);

    private:
        std::string multiByteInitial;
        int multiByteInitialLength;
        CodePage codePage;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_MULTI_BYTE_CONVERSION_WIDE_CHAR_TESTING_H