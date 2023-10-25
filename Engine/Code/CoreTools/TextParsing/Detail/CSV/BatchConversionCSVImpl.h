///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:11)

#ifndef CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BatchConversionCSVImpl final
    {
    public:
        using ClassType = BatchConversionCSVImpl;

        using String = System::String;

    public:
        BatchConversionCSVImpl(const String& nativeFileName, const String& outputDirectory);

        CLASS_INVARIANT_DECLARE;

    private:
        void ExecutionFile(const String& nativeFileName, const String& outputDirectory);

        NODISCARD static String GetOutputFile(const String& nativeFileName, const String& outputDirectory);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H