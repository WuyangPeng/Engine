///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 16:14)

#ifndef FRAMEWORK_PROJECT_GENERATE_PROJECT_NAME_H
#define FRAMEWORK_PROJECT_GENERATE_PROJECT_NAME_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <vector>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE GenerateProjectName final
    {
    public:
        using ClassType = GenerateProjectName;

        using String = System::String;
        using ProjectNameContainer = std::vector<String>;

    public:
        NODISCARD static ProjectNameContainer GenerateProjectNameContainer(const String& fileName, const EnvironmentDirectory& environmentDirectory);

        GenerateProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ProjectNameContainer GetProjectNameContainer() const;

    private:
        void ReadProjectName();

    private:
        std::string projectName;
        ProjectNameContainer container;
    };
}

#endif  // FRAMEWORK_PROJECT_GENERATE_PROJECT_NAME_H