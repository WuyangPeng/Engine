///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/17 23:44)

#include "Framework/FrameworkExport.h"

#include "GUIProjectManager.h"
#include "ResourceProjectManager.h"
#include "Detail/ResourceProjectManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::ResourceProjectManager::ResourceProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ResourceProjectManager)

bool Framework::ResourceProjectManager::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Create(environmentParameter))
    {
        return impl->Create();
    }
    else
    {
        return false;
    }
}

bool Framework::ResourceProjectManager::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Initialize())
    {
        const auto gui = GetGUIManager<GUIProjectManager>();

        return impl->Initialize(*gui);
    }
    else
    {
        return false;
    }
}

bool Framework::ResourceProjectManager::IsSelectValid(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsSelectValid(select);
}

System::String Framework::ResourceProjectManager::GetEngineeringName(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetEngineeringName(select);
}

void Framework::ResourceProjectManager::PrintEngineering(const String& engineeringName) const
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto gui = GetGUIManager<GUIProjectManager>();

    impl->PrintEngineering(engineeringName, *gui);
}

int Framework::ResourceProjectManager::GetContainerPrintWidth() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetContainerPrintWidth();
}