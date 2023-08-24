///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 16:12)

#include "Framework/FrameworkExport.h"

#include "GenerateProjectName.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::GenerateProjectName::GenerateProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
    : projectName{ CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(UpperDirectory::Configuration) + fileName) },
      container{}
{
    ReadProjectName();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void Framework::GenerateProjectName::ReadProjectName()
{
    using TreeType = boost::property_tree::basic_ptree<String, String>;

    TreeType mainTree{};
    read_json(projectName, mainTree);

    for (const auto& [name, isOpen] : mainTree)
    {
        if (0 < isOpen.get_value<int>())
        {
            container.emplace_back(name);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(Framework, GenerateProjectName)

Framework::GenerateProjectName::ProjectNameContainer Framework::GenerateProjectName::GetProjectNameContainer() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return container;
}

Framework::GenerateProjectName::ProjectNameContainer Framework::GenerateProjectName::GenerateProjectNameContainer(const String& fileName, const EnvironmentDirectory& environmentDirectory)
{
    const GenerateProjectName generateEngineName{ fileName, environmentDirectory };

    return generateEngineName.GetProjectNameContainer();
}
