///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/19 16:58)

#ifndef THE_LAST_OVERLORD_PROJECT_NAME_H
#define THE_LAST_OVERLORD_PROJECT_NAME_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <vector>

namespace TheLastOverlord
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

    private:
        using ProjectNameContainer = std::vector<String>;

    private:
        NODISCARD static std::string GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);
        NODISCARD static ProjectNameContainer GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory);

    private:
        ProjectNameContainer container;
    };
}

#endif  // THE_LAST_OVERLORD_PROJECT_NAME_H