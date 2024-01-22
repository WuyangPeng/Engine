/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:50)

#include "Framework/FrameworkExport.h"

#include "GUIProjectManager.h"
#include "ProjectName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

Framework::GUIProjectManager::GUIProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GUIProjectManager)

void Framework::GUIProjectManager::PrintSelect(const ProjectName& projectName) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    COUT << projectName.GetSelectDescribe();
}

void Framework::GUIProjectManager::PrintEngineering(const String& engineeringName) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    COUT << SYSTEM_TEXT("����ִ�й��̣�") << engineeringName << SYSTEM_TEXT("\n");
}
