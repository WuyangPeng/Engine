///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.9.0.12 (2023/06/17 12:43)

#include "GUIMiddleLayer.h"
#include "RiseOfHistory/Core/ProjectName.h"
#include "RiseOfHistory/Helper/RiseOfHistoryClassInvariantMacro.h"

#include <iostream>

RiseOfHistory::GUIMiddleLayer::GUIMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    RISE_OF_HISTORY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RiseOfHistory, GUIMiddleLayer)

void RiseOfHistory::GUIMiddleLayer::PrintSelect(const ProjectName& projectName)
{
    RISE_OF_HISTORY_CLASS_IS_VALID_1;

    projectName.PrintSelect();
}

void RiseOfHistory::GUIMiddleLayer::PrintEngineering(const String& engineeringName)
{
    COUT << SYSTEM_TEXT("正在执行工程：") << engineeringName << SYSTEM_TEXT("\n");
}
