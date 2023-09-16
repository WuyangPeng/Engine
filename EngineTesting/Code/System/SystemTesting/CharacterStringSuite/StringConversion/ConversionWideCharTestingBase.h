///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:03)

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