/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_CONVERSION_WIDE_CHAR_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_CONVERSION_WIDE_CHAR_TESTING_BASE_H

#include "ConversionTestingBase.h"

namespace System
{
    class ConversionWideCharTestingBase : public ConversionTestingBase
    {
    public:
        using ClassType = ConversionWideCharTestingBase;
        using ParentType = ConversionTestingBase;

    public:
        explicit ConversionWideCharTestingBase(const OStreamShared& stream, int conversionMinLength, const std::wstring& wideCharConversionResult);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void ResultChecking(const WideCharType& wideChar, int wideCharActualLength, int wideCharLength);

    private:
        std::wstring wideCharConversionResult;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_CONVERSION_WIDE_CHAR_TESTING_BASE_H