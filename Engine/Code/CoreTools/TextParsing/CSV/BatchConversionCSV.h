/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 13:18)

#ifndef CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_H
#define CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <filesystem>

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
        using DirectoryEntry = std::filesystem::directory_entry;

    private:
        static void Execution(const String& inputDirectory, const String& outputDirectory);
        static void Execution(const String& outputDirectory, const DirectoryEntry& inputPath);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CSV_H