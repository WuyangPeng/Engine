///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:39)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_HEAD_H
#define CORE_TOOLS_TEXT_PARSING_JSON_HEAD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(JsonHeadImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE JsonHead final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(JsonHead);
        using String = System::String;
        using JsonNodeSharedPtr = std::shared_ptr<JsonNode>;
        using Container = std::vector<JsonNodeSharedPtr>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit JsonHead(const String& path);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetNameSpace() const;
        NODISCARD String GetJsonClassName() const;
        NODISCARD String GetCompleteClassName() const;

        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;

        NODISCARD bool HasNested() const noexcept;
        NODISCARD bool HasArray() const noexcept;
        NODISCARD bool HasBoolArray() const noexcept;

        NODISCARD int GetSize() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_HEAD_H