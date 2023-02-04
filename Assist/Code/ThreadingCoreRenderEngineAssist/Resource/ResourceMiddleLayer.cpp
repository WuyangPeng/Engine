///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 14:00)

#include "ResourceMiddleLayer.h"
#include "ThreadingCoreRenderEngineAssist/GUI/GUIMiddleLayer.h"
#include "ThreadingCoreRenderEngineAssist/Helper/AssistClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_unique;
using namespace std::literals;

ThreadingCoreRenderEngineAssist::ResourceMiddleLayer::ResourceMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, directory{ System::GetEngineeringDirectory() }, projectName{}
{
    ASSIST_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngineAssist, ResourceMiddleLayer)

bool ThreadingCoreRenderEngineAssist::ResourceMiddleLayer::PreCreate()
{
    ASSIST_CLASS_IS_VALID_1;

    projectName = make_unique<ProjectName>(SYSTEM_TEXT("Project.json"s), GetEnvironmentDirectory());

    return true;
}

bool ThreadingCoreRenderEngineAssist::ResourceMiddleLayer::Initialize()
{
    ASSIST_CLASS_IS_VALID_1;

    if (projectName != nullptr)
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

bool ThreadingCoreRenderEngineAssist::ResourceMiddleLayer::IsSelectValid(int select) const
{
    ASSIST_CLASS_IS_VALID_CONST_1;

    if (projectName != nullptr)
    {
        return projectName->IsSelectValid(select);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ��ȷ����PreCreate��ʼ����������"s));
    }
}

const System::String ThreadingCoreRenderEngineAssist::ResourceMiddleLayer::GetEngineeringNameOrEmpty(int select) const
{
    ASSIST_CLASS_IS_VALID_CONST_1;

    if (projectName != nullptr)
    {
        return projectName->GetEngineeringNameOrEmpty(select);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ��ȷ����PreCreate��ʼ����������"s));
    }
}

void ThreadingCoreRenderEngineAssist::ResourceMiddleLayer::PrintEngineering(const String& engineeringName)
{
    ASSIST_CLASS_IS_VALID_1;

    if (projectName != nullptr)
    {
        auto gui = GetGUIMiddleLayer();

        gui->PrintEngineering(engineeringName);
        gui->PrintSelect(*projectName);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ��ȷ����PreCreate��ʼ����������"s));
    }
}

ThreadingCoreRenderEngineAssist::ResourceMiddleLayer::GUIMiddleLayerSharedPtr ThreadingCoreRenderEngineAssist::ResourceMiddleLayer::GetGUIMiddleLayer()
{
    return boost::polymorphic_pointer_downcast<GUIMiddleLayer>(GetGUIManager());
}
