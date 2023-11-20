///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:39)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_MIDDLE_LAYER_MODULE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_MIDDLE_LAYER_MODULE_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(MiddleLayerModuleImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE MiddleLayerModule
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(MiddleLayerModule);

        using String = System::String;

    public:
        MiddleLayerModule(const String& middleLayerName, const String& uppercaseName, bool isManager);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetMiddleLayerName() const;
        NODISCARD String GetUppercaseName() const;
        NODISCARD bool IsManager() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_MIDDLE_LAYER_MODULE_H
