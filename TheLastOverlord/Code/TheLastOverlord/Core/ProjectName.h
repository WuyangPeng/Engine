///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���İ����汾��0.7.0.1 (2021/02/18 15:15)

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
        [[nodiscard]] bool IsSelectValid(int select) const;
        [[nodiscard]] const String GetEngineeringName(int select) const;

    private:
        using ProjectNameContainer = std::vector<String>;

    private:
        [[nodiscard]] static std::string GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);
        [[nodiscard]] static ProjectNameContainer GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory);

    private:
        ProjectNameContainer container;
    };
}

#endif  // THE_LAST_OVERLORD_PROJECT_NAME_H