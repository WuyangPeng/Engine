///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/16 09:51)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_REPLACE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_REPLACE_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(ReplaceImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE Replace
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(Replace);

        using String = System::String;
        using StringView = System::StringView;

    public:
        Replace(const StringView& keyCode, const String& parameter);

        CLASS_INVARIANT_DECLARE;

        NODISCARD StringView GetKeyCode() const noexcept;
        NODISCARD String GetParameter() const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_REPLACE_H
