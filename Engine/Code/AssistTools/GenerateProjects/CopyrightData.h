///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:41)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(CopyrightDataImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE CopyrightData
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CopyrightData);

    public:
        CopyrightData(int endYear, const System::String& versions, const System::String& projectChineseName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetEndYear() const noexcept;
        NODISCARD System::String GetVersions() const;
        NODISCARD System::String GetProjectChineseName() const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H
