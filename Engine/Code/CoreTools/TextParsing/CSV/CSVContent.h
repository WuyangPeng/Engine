/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:27)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CONTENT_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CONTENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(CSVContentImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CSVContent final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CSVContent);

        using String = System::String;

    public:
        explicit CSVContent(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CSVHead GetCSVHead() const;
        NODISCARD int GetCount() const;
        NODISCARD String GetContent(int index) const;
        NODISCARD String GetCSVClassName() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CONTENT_H