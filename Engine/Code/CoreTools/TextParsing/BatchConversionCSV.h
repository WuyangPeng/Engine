///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/28 18:07)

#ifndef CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_H
#define CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BatchConversionCSV final
    {
    public:
        using ClassType = BatchConversionCSV;
        using String = System::String;

    public:
        BatchConversionCSV(const String& inputDirectory, const String& outputDirectory);

        CLASS_INVARIANT_DECLARE;

    private:
        void Execution(const String& inputDirectory, const String& outputDirectory);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_H