///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 11:01)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_PROJECT_NAME_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_PROJECT_NAME_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <vector>

namespace ThreadingCoreRenderEngineAssist
{
    class ProjectName final
    {
    public:
        using ClassType = ProjectName;
        using String = System::String;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        explicit ProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        void PrintSelect() const;
        [[nodiscard]] bool IsSelectValid(int select) const;
        [[nodiscard]] const String GetEngineeringName(int select) const;
        [[nodiscard]] const String GetEngineeringNameOrEmpty(int select) const;

    private:
        using ProjectNameContainer = std::vector<String>;

    private:
        [[nodiscard]] static std::string GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);
        [[nodiscard]] static ProjectNameContainer GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory);

    private:
        ProjectNameContainer container;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_PROJECT_NAME_H