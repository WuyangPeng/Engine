///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.12 (2023/06/16 22:02)

#ifndef MILLENNIUM_HISTORY_PROJECT_NAME_H
#define MILLENNIUM_HISTORY_PROJECT_NAME_H

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <vector>

namespace MillenniumHistory
{
    class ProjectName final
    {
    public:
        using ClassType = ProjectName;

        using String = System::String;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        void PrintSelect() const;
        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineeringName(int select) const;
        NODISCARD int GetContainerPrintWidth() const;

    private:
        using ProjectNameContainer = std::vector<String>;
        using TreeType = boost::property_tree::basic_ptree<String, String>;

    private:
        NODISCARD static std::string GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);
        NODISCARD static ProjectNameContainer GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory);
        NODISCARD static ProjectNameContainer GenerateEngineName(const TreeType& mainTree);
        void PrintSelect(const String& element, int index) const;

    private:
        ProjectNameContainer container;
    };
}

#endif  // MILLENNIUM_HISTORY_PROJECT_NAME_H