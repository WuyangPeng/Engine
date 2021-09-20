///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 11:00)

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
    COUT << SYSTEM_TEXT("正在执行工程：") << engineeringName << SYSTEM_TEXT("\n");
}
