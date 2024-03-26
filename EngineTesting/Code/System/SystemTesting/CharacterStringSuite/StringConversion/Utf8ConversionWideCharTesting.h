/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_UTF8_CONVERSION_WIDE_CHAR_TESTING_H

#include "ConversionWideCharTestingBase.h"

namespace System
{
    /// @brief Utf8字符串转换为WideChar测试
    /// 测试资源在StringConversionTesting目录下
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