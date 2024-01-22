/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:49)

#include "Framework/FrameworkExport.h"

#include "GUIProjectManager.h"
#include "ResourceProjectManager.h"
#include "Detail/ResourceProjectManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::ResourceProjectManager::ResourceProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ResourceProjectManager)

bool Framework::ResourceProjectManager::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_9;

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
    FRAMEWORK_CLASS_IS_VALID_9;

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
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsSelectValid(select);
}

System::String Framework::ResourceProjectManager::GetEngineeringName(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetEngineeringName(select);
}

void Framework::ResourceProjectManager::PrintEngineering(const String& engineeringName) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const auto gui = GetGUIManager<GUIProjectManager>();

    impl->PrintEngineering(engineeringName, *gui);
}

int Framework::ResourceProjectManager::GetContainerPrintWidth() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetContainerPrintWidth();
}
