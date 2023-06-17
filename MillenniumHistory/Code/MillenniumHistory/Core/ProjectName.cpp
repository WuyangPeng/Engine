///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/16 21:55)

#include "MillenniumHistory/Helper/MillenniumHistoryClassInvariantMacro.h"
#include "ProjectName.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

#include <iostream>

MillenniumHistory::ProjectName::ProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
    : container{ GenerateEngineName(fileName, environmentDirectory) }
{
    MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_9;
}

std::string MillenniumHistory::ProjectName::GetProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
{
    return CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(Framework::UpperDirectory::Configuration) + fileName);
}

MillenniumHistory::ProjectName::ProjectNameContainer MillenniumHistory::ProjectName::GenerateEngineName(const TreeType& mainTree)
{
    ProjectNameContainer engineTestingName{};

    for (const auto& [first, second] : mainTree)
    {
        if (0 < second.get_value<int>())
        {
            engineTestingName.emplace_back(first);
        }
    }

    return engineTestingName;
}

MillenniumHistory::ProjectName::ProjectNameContainer MillenniumHistory::ProjectName::GenerateEngineName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
{
    const auto projectTestingName = GetProjectName(fileName, environmentDirectory);

    TreeType mainTree{};
    read_json(projectTestingName, mainTree);

    return GenerateEngineName(mainTree);
}

CLASS_INVARIANT_STUB_DEFINE(MillenniumHistory, ProjectName)

void MillenniumHistory::ProjectName::PrintSelect() const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_9;

    auto index = 1;
    COUT << SYSTEM_TEXT("请选择要执行的工程：\n");

    for (const auto& element : container)
    {
        PrintSelect(element, index);

        ++index;
    }
}

void MillenniumHistory::ProjectName::PrintSelect(const String& element, int index) const
{
    const auto width = GetContainerPrintWidth();

    COUT << std::setw(width) << std::setfill(SYSTEM_TEXT('0')) << (index++) << SYSTEM_TEXT("：") << element << SYSTEM_TEXT("\n");
}

bool MillenniumHistory::ProjectName::IsSelectValid(int select) const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_9;

    return 0 <= select && select < boost::numeric_cast<int>(container.size());
}

System::String MillenniumHistory::ProjectName::GetEngineeringName(int select) const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_9;

    return container.at(select);
}

int MillenniumHistory::ProjectName::GetContainerPrintWidth() const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_9;

    auto result = 0;
    auto size = boost::numeric_cast<int>(container.size());
    while (0 < size)
    {
        constexpr auto base = 10;

        size /= base;
        ++result;
    }

    return result;
}
