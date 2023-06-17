///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.9.0.12 (2023/06/17 12:41)

#include "ResourceMiddleLayer.h"
#include "RiseOfHistory/GUI/GUIMiddleLayer.h"
#include "RiseOfHistory/Helper/RiseOfHistoryClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

RiseOfHistory::ResourceMiddleLayer::ResourceMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, directory{ System::GetEngineeringDirectory() }, projectName{}
{
    RISE_OF_HISTORY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RiseOfHistory, ResourceMiddleLayer)

bool RiseOfHistory::ResourceMiddleLayer::Create(const EnvironmentParameter& environmentParameter)
{
    RISE_OF_HISTORY_CLASS_IS_VALID_1;

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

bool RiseOfHistory::ResourceMiddleLayer::Initialize()
{
    RISE_OF_HISTORY_CLASS_IS_VALID_1;

    if (ParentType::Initialize() && projectName != nullptr)
    {
        auto gui = GetGUIMiddleLayer();

        gui->PrintSelect(*projectName);

        return true;
    }
    else
    {
        return false;
    }
}

bool RiseOfHistory::ResourceMiddleLayer::IsSelectValid(int select) const
{
    RISE_OF_HISTORY_CLASS_IS_VALID_CONST_1;

    CheckProjectName();

    return projectName->IsSelectValid(select);
}

System::String RiseOfHistory::ResourceMiddleLayer::GetEngineeringName(int select) const
{
    RISE_OF_HISTORY_CLASS_IS_VALID_CONST_1;

    CheckProjectName();

    return projectName->GetEngineeringName(select);
}

void RiseOfHistory::ResourceMiddleLayer::PrintEngineering(const String& engineeringName)
{
    RISE_OF_HISTORY_CLASS_IS_VALID_1;

    CheckProjectName();

    auto gui = GetGUIMiddleLayer();

    gui->PrintEngineering(engineeringName);
    gui->PrintSelect(*projectName);
}

RiseOfHistory::ResourceMiddleLayer::GUIMiddleLayerSharedPtr RiseOfHistory::ResourceMiddleLayer::GetGUIMiddleLayer()
{
    return boost::polymorphic_pointer_downcast<GUIMiddleLayer>(GetGUIManager());
}

void RiseOfHistory::ResourceMiddleLayer::CheckProjectName() const
{
    if (projectName == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未正确调用Create初始化工程名。"s));
    }
}

int RiseOfHistory::ResourceMiddleLayer::GetContainerPrintWidth() const
{
    RISE_OF_HISTORY_CLASS_IS_VALID_CONST_1;

    return projectName->GetContainerPrintWidth();
}
