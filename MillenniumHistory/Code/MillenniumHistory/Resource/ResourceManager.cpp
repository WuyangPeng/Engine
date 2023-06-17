///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/15 22:58)

#include "MillenniumHistory/GUI/GUIManager.h"
#include "MillenniumHistory/Helper/MillenniumHistoryClassInvariantMacro.h"
#include "ResourceManager.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

MillenniumHistory::ResourceManager::ResourceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, directory{ System::GetEngineeringDirectory() }, projectName{}
{
    MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MillenniumHistory, ResourceManager)

bool MillenniumHistory::ResourceManager::Create(const EnvironmentParameter& environmentParameter)
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_1;

    if (ParentType::Create(environmentParameter))
    {
        projectName = make_unique<ProjectName>(SYSTEM_TEXT("Project.json"s), GetEnvironmentDirectory());

        return true;
    }
    else
    {
        return false;
    }
}

bool MillenniumHistory::ResourceManager::Initialize()
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_1;

    if (ParentType::Initialize() && projectName != nullptr)
    {
        const auto gui = GetGUIManager<GUIManager>();

        gui->PrintSelect(*projectName);

        return true;
    }
    else
    {
        return false;
    }
}

bool MillenniumHistory::ResourceManager::IsSelectValid(int select) const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1;

    CheckProjectName();

    return projectName->IsSelectValid(select);
}

System::String MillenniumHistory::ResourceManager::GetEngineeringName(int select) const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1;

    CheckProjectName();

    return projectName->GetEngineeringName(select);
}

void MillenniumHistory::ResourceManager::PrintEngineering(const String& engineeringName)
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_1;

    CheckProjectName();

    const auto gui = GetGUIManager<GUIManager>();

    gui->PrintEngineering(engineeringName);
    gui->PrintSelect(*projectName);
}

void MillenniumHistory::ResourceManager::CheckProjectName() const
{
    if (projectName == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未正确调用Create初始化工程名。"s))
    }
}

int MillenniumHistory::ResourceManager::GetContainerPrintWidth() const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1;

    return projectName->GetContainerPrintWidth();
}
