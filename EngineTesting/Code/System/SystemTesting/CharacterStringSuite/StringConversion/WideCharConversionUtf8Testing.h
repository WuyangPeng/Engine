/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:06)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H

#include "WideCharConversionTestingBase.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

namespace System
{
    /// @brief WideChar字符串转换为Utf8测试
    /// 测试资源在StringConversionTesting目录下
    class WideCharConversionUtf8Testing final : public WideCharConversionTestingBase
    {
    public:
        using ClassType = WideCharConversionUtf8Testing;
        using ParentType = WideCharConversionTestingBase;

    public:
        explicit WideCharConversionUtf8Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WideCharConversionUtf8Test();

    private:
        std::wstring wideCharInitial;
        int wideCharInitialLength;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H