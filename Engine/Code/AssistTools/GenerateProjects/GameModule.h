///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 10:49)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GameModuleImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GameModule
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GameModule);

        using String = System::String;

    public:
        GameModule(const String& moduleName, const String& chineseName, bool isClient, const String& uppercaseName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetModuleName() const;
        NODISCARD String GetChineseName() const;
        NODISCARD bool IsClient() const noexcept;
        NODISCARD String GetUppercaseName() const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_H