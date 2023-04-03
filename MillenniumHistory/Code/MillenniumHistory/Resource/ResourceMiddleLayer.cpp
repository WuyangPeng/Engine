///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.5 (2023/04/03 09:27)

#include "MillenniumHistory/GUI/GUIMiddleLayer.h"
#include "MillenniumHistory/Helper/MillenniumHistoryClassInvariantMacro.h"
#include "ResourceMiddleLayer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

MillenniumHistory::ResourceMiddleLayer::ResourceMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, directory{ System::GetEngineeringDirectory() }, projectName{}
{
    MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MillenniumHistory, ResourceMiddleLayer)

bool MillenniumHistory::ResourceMiddleLayer::Create(const EnvironmentParameter& environmentParameter)
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

bool MillenniumHistory::ResourceMiddleLayer::Initialize()
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_1;

    if (ParentType::Initialize() && projectName != nullptr)
    {
        const auto gui = GetGUIMiddleLayer();

        gui->PrintSelect(*projectName);

        return true;
    }
    else
    {
        return false;
    }
}

bool MillenniumHistory::ResourceMiddleLayer::IsSelectValid(int select) const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1;

    CheckProjectName();

    return projectName->IsSelectValid(select);
}

System::String MillenniumHistory::ResourceMiddleLayer::GetEngineeringName(int select) const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1;

    CheckProjectName();

    return projectName->GetEngineeringName(select);
}

void MillenniumHistory::ResourceMiddleLayer::PrintEngineering(const String& engineeringName)
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_1;

    CheckProjectName();

    const auto gui = GetGUIMiddleLayer();

    gui->PrintEngineering(engineeringName);
    gui->PrintSelect(*projectName);
}

MillenniumHistory::ResourceMiddleLayer::GUIMiddleLayerSharedPtr MillenniumHistory::ResourceMiddleLayer::GetGUIMiddleLayer()
{
    return boost::polymorphic_pointer_downcast<GUIMiddleLayer>(GetGUIManager());
}

void MillenniumHistory::ResourceMiddleLayer::CheckProjectName() const
{
    if (projectName == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未正确调用Create初始化工程名。"s))
    }
}

int MillenniumHistory::ResourceMiddleLayer::GetContainerPrintWidth() const
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1;

    return projectName->GetContainerPrintWidth();
}
