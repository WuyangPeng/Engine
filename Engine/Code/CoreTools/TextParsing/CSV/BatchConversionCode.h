///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/26 13:44)

#ifndef CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_H
#define CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BatchConversionCode final
    {
    public:
        using ClassType = BatchConversionCode;

        using String = System::String;

    public:
        explicit BatchConversionCode(const String& inputDirectory, const String& codeDirectory, const String& outputDirectory);

        CLASS_INVARIANT_DECLARE;

    private:
        void LoadConfigure(const String& inputDirectory, const String& codeDirectory, const String& outputDirectory);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_H