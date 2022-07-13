///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 14:10)

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
        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineeringName(int select) const;
        NODISCARD String GetEngineeringNameOrEmpty(int select) const;

    private:
        using ProjectNameContainer = std::vector<String>;

    private:
        NODISCARD static std::string GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);
        NODISCARD static ProjectNameContainer GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory);

    private:
        ProjectNameContainer container;
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_PROJECT_NAME_H