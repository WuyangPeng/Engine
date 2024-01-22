/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:53)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GameModuleImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GameModule
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GameModule);

        using String = System::String;
        static constexpr auto guidCount = 4;
        using GuidContainer = std::array<String, guidCount>;

    public:
        GameModule(const String& moduleName, const String& chineseName, ProjectServiceType projectServiceType, const String& uppercaseName, const GuidContainer& guid);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetModuleName() const;
        NODISCARD String GetChineseName() const;
        NODISCARD ProjectServiceType GetProjectServiceType() const noexcept;
        NODISCARD String GetUppercaseName() const;
        NODISCARD String GetGuid(int index) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_H