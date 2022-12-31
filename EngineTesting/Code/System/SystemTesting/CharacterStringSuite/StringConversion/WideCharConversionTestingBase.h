///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/01 22:20)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_TESTING_BASE_H

#include "ConversionTestingBase.h"

namespace System
{
    class WideCharConversionTestingBase : public ConversionTestingBase
    {
    public:
        using ClassType = WideCharConversionTestingBase;
        using ParentType = ConversionTestingBase;

    public:
        explicit WideCharConversionTestingBase(const OStreamShared& stream, int conversionMinLength, const std::string& multiByteConversionResult);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void ResultChecking(const MultiByteType& multiByte, int multiByteActualLength, int multiByteLength);

    private:
        std::string multiByteConversionResult;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_TESTING_BASE_H