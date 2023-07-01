///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:09)

#include "Framework/FrameworkExport.h"

#include "GUIProjectManager.h"
#include "ProjectName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

Framework::GUIProjectManager::GUIProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GUIProjectManager)

void Framework::GUIProjectManager::PrintSelect(const ProjectName& projectName) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    COUT << projectName.GetSelectDescribe();
}

void Framework::GUIProjectManager::PrintEngineering(const String& engineeringName) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    COUT << SYSTEM_TEXT("正在执行工程：") << engineeringName << SYSTEM_TEXT("\n");
}
