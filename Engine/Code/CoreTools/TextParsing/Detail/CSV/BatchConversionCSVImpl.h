/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:50)

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
        BatchConversionCSVImpl(String nativeFileName, String outputDirectory);

        CLASS_INVARIANT_DECLARE;

    private:
        void ExecutionFile() const;

        NODISCARD String GetOutputFile() const;

    private:
        String nativeFileName;
        String outputDirectory;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_IMPL_H