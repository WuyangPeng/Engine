/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:51)

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