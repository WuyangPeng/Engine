///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 11:01)

#include "ProjectName.h"
#include "ThreadingCoreRenderEngineAssist/Helper/AssistClassInvariantMacro.h"
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

ThreadingCoreRenderEngineAssist::ProjectName::ProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
    : container{ GenerateEngineName(fileName, environmentDirectory) }
{
    ASSIST_SELF_CLASS_IS_VALID_9;
}

// static
// private
string ThreadingCoreRenderEngineAssist::ProjectName::GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
{
    return CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(Framework::UpperDirectory::Configuration) + fileName);
}

// static
// private
ThreadingCoreRenderEngineAssist::ProjectName::ProjectNameContainer ThreadingCoreRenderEngineAssist::ProjectName::GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
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

CLASS_INVARIANT_STUB_DEFINE(ThreadingCoreRenderEngineAssist, ProjectName)

void ThreadingCoreRenderEngineAssist::ProjectName::PrintSelect() const
{
    ASSIST_CLASS_IS_VALID_CONST_9;

    auto index = 1;
    COUT << SYSTEM_TEXT("��ѡ��Ҫִ�еĸ������̣�\n");
    const auto width = container.size() / 10 + 1;

    for (const auto& projectName : container)
    {
        COUT << setw(width) << setfill(SYSTEM_TEXT('0')) << (index++) << SYSTEM_TEXT("��") << projectName << SYSTEM_TEXT("\n");
    }
}

bool ThreadingCoreRenderEngineAssist::ProjectName::IsSelectValid(int select) const
{
    ASSIST_CLASS_IS_VALID_CONST_9;

    return 0 <= select && select < boost::numeric_cast<int>(container.size());
}

const System::String ThreadingCoreRenderEngineAssist::ProjectName::GetEngineeringName(int select) const
{
    ASSIST_CLASS_IS_VALID_CONST_9;

    return container.at(select);
}

const System::String ThreadingCoreRenderEngineAssist::ProjectName::GetEngineeringNameOrEmpty(int select) const
{
    ASSIST_CLASS_IS_VALID_CONST_9;

    if (IsSelectValid(select))
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return container[select];

#include STSTEM_WARNING_POP
    }
    else
    {
        return String{};
    }
}
