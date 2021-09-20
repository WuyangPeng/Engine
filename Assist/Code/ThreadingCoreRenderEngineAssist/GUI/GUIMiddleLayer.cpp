///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 11:00)

#include "GUIMiddleLayer.h"
#include "ThreadingCoreRenderEngineAssist/Core/ProjectName.h"
#include "ThreadingCoreRenderEngineAssist/Helper/AssistClassInvariantMacro.h"

#include <iostream>

ThreadingCoreRenderEngineAssist::GUIMiddleLayer::GUIMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    ASSIST_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngineAssist, GUIMiddleLayer)

void ThreadingCoreRenderEngineAssist::GUIMiddleLayer::PrintSelect(const ProjectName& projectName)
{
    ASSIST_CLASS_IS_VALID_1;

    projectName.PrintSelect();
}

void ThreadingCoreRenderEngineAssist::GUIMiddleLayer::PrintEngineering(const String& engineeringName)
{
    COUT << SYSTEM_TEXT("����ִ�й��̣�") << engineeringName << SYSTEM_TEXT("\n");
}
