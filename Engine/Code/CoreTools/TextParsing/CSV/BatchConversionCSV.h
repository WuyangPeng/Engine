///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 21:30)

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