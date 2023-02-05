///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.2 (2022/09/11 22:01)

#include "ProjectName.h"
#include "RiseOfHistory/Helper/RiseOfHistoryClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

#include <iostream>

using std::setfill;
using std::setw;
using std::string;
using namespace std::literals;

RiseOfHistory::ProjectName::ProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
    : container{ GenerateEngineName(fileName, environmentDirectory) }
{
    RISE_OF_HISTORY_SELF_CLASS_IS_VALID_9;
}

// static
// private
string RiseOfHistory::ProjectName::GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
{
    return CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(Framework::UpperDirectory::Configuration) + fileName);
}

// static
// private
RiseOfHistory::ProjectName::ProjectNameContainer RiseOfHistory::ProjectName::GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
{
    auto projectTestingName = GetProjectName(fileName, environmentDirectory);

    boost::property_tree::basic_ptree<String, String> mainTree{};
    read_json(projectTestingName, mainTree);

    ProjectNameContainer engineTestingName{};

    for (const auto& tree : mainTree)
    {
        if (0 < tree.second.get_value<int>())
        {
            engineTestingName.emplace_back(tree.first);
        }
    }

    return engineTestingName;
}

CLASS_INVARIANT_STUB_DEFINE(RiseOfHistory, ProjectName)

void RiseOfHistory::ProjectName::PrintSelect() const
{
    RISE_OF_HISTORY_CLASS_IS_VALID_CONST_9;

    auto index = 1;
    COUT << SYSTEM_TEXT("��ѡ��Ҫִ�еĹ��̣�\n");
    const auto width = GetContainerPrintWidth();

    for (const auto& value : container)
    {
        COUT << setw(width) << setfill(SYSTEM_TEXT('0')) << (index++) << SYSTEM_TEXT("��") << value << SYSTEM_TEXT("\n");
    }
}

bool RiseOfHistory::ProjectName::IsSelectValid(int select) const
{
    RISE_OF_HISTORY_CLASS_IS_VALID_CONST_9;

    return 0 <= select && select < boost::numeric_cast<int>(container.size());
}

System::String RiseOfHistory::ProjectName::GetEngineeringName(int select) const
{
    RISE_OF_HISTORY_CLASS_IS_VALID_CONST_9;

    return container.at(select);
}

int RiseOfHistory::ProjectName::GetContainerPrintWidth() const
{
    RISE_OF_HISTORY_CLASS_IS_VALID_CONST_9;

    auto result = 0;
    auto size = boost::numeric_cast<int>(container.size());
    while (0 < size)
    {
        size /= 10;
        ++result;
    }

    return result;
}
