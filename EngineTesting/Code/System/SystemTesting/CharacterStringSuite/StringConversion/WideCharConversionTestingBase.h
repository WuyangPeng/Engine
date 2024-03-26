/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:06)

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
        explicit WideCharConversionTestingBase(const OStreamShared& stream, int conversionMinLength, std::string multiByteConversionResult);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void ResultChecking(const MultiByteType& multiByte, int multiByteActualLength, int multiByteLength);

    private:
        std::string multiByteConversionResult;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_TESTING_BASE_H