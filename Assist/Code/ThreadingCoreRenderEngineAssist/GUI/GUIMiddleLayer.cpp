///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 14:10)

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
