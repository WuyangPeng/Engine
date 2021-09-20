///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	最后的霸王版本：0.7.0.1 (2021/02/18 15:16)

#include "ProjectName.h"
#include "TheLastOverlord/Helper/TheLastOverlordClassInvariantMacro.h"
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

TheLastOverlord::ProjectName::ProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
    : container{ GenerateEngineName(fileName, environmentDirectory) }
{
    THE_LAST_OVERLORD_SELF_CLASS_IS_VALID_9;
}

// static
// private
string TheLastOverlord::ProjectName::GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
{
    return CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(Framework::UpperDirectory::Configuration) + fileName);
}

// static
// private
TheLastOverlord::ProjectName::ProjectNameContainer TheLastOverlord::ProjectName::GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
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

CLASS_INVARIANT_STUB_DEFINE(TheLastOverlord, ProjectName)

void TheLastOverlord::ProjectName::PrintSelect() const
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_CONST_9;

    auto index = 1;
    COUT << SYSTEM_TEXT("请选择要执行的工程：\n");
    const auto width = container.size() / 10 + 1;

    for (auto value : container)
    {
        COUT << setw(width) << setfill(SYSTEM_TEXT('0')) << (index++) << SYSTEM_TEXT("：") << value << SYSTEM_TEXT("\n");
    }
}

bool TheLastOverlord::ProjectName::IsSelectValid(int select) const
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_CONST_9;

    return 0 <= select && select < boost::numeric_cast<int>(container.size());
}

const System::String TheLastOverlord::ProjectName::GetEngineeringName(int select) const
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_CONST_9;

    return container.at(select);
}
