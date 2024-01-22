/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:51)

#ifndef FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H
#define FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/FileManager/Directory.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/Project/ProjectFwd.h"
#include "Framework/Project/ProjectName.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ResourceProjectManagerImpl final
    {
    public:
        using ClassType = ResourceProjectManagerImpl;

        using String = System::String;
        using Directory = CoreTools::Directory;

    public:
        explicit ResourceProjectManagerImpl(const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Create();
        NODISCARD bool Initialize(const GUIProjectManager& gui) const;

        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineeringName(int select) const;

        void PrintEngineering(const String& engineeringName, const GUIProjectManager& gui) const;

        NODISCARD int GetContainerPrintWidth() const;

    private:
        using ProjectNameUniquePtr = std::unique_ptr<ProjectName>;

    private:
        void CheckProjectName() const;

    private:
        EnvironmentDirectory environmentDirectory;
        Directory directory;
        ProjectNameUniquePtr projectName;
    };
}

#endif  // FRAMEWORK_PROJECT_RESOURCE_PROJECT_MANAGER_IMPL_H
