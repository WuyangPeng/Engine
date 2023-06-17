///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.9.0.12 (2023/06/17 15:02)

#include "ResourceMiddleLayer.h"
#include "TheLastOverlord/GUI/GUIMiddleLayer.h"
#include "TheLastOverlord/Helper/TheLastOverlordClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

TheLastOverlord::ResourceMiddleLayer::ResourceMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, directory{ System::GetEngineeringDirectory() }, projectName{}
{
    THE_LAST_OVERLORD_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlord, ResourceMiddleLayer)

bool TheLastOverlord::ResourceMiddleLayer::PreCreate()
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_1;

    projectName = make_unique<ProjectName>(SYSTEM_TEXT("Project.json"s), GetEnvironmentDirectory());

    return true;
}

bool TheLastOverlord::ResourceMiddleLayer::Initialize()
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_1;

    if (projectName != nullptr)
    {
        auto gui = boost::polymorphic_pointer_downcast<GUIMiddleLayer>(GetGUIManager());

        gui->PrintSelect(*projectName);

        return true;
    }
    else
    {
        return false;
    }
}

bool TheLastOverlord::ResourceMiddleLayer::IsSelectValid(int select) const
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_CONST_1;

    if (projectName != nullptr)
    {
        return projectName->IsSelectValid(select);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ��ȷ����PreCreate��ʼ����������"s));
    }
}

System::String TheLastOverlord::ResourceMiddleLayer::GetEngineeringName(int select) const
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_CONST_1;

    if (projectName != nullptr)
    {
        return projectName->GetEngineeringName(select);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ��ȷ����PreCreate��ʼ����������"s));
    }
}

void TheLastOverlord::ResourceMiddleLayer::PrintEngineering(const String& engineeringName)
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_1;

    if (projectName != nullptr)
    {
        auto gui = boost::polymorphic_pointer_downcast<GUIMiddleLayer>(GetGUIManager());

        gui->PrintEngineering(engineeringName);
        gui->PrintSelect(*projectName);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("δ��ȷ����PreCreate��ʼ����������"s));
    }
}
