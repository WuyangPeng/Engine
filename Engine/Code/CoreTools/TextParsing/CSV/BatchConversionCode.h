/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 13:18)

#ifndef CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_H
#define CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(BatchConversionCodeImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BatchConversionCode final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(BatchConversionCode);

        using String = System::String;

    public:
        explicit BatchConversionCode(const String& inputDirectory, const String& codeDirectory, const String& outputDirectory);

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_H