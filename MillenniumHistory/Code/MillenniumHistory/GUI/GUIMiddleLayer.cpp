///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.5 (2023/04/03 09:35)

#include "GUIMiddleLayer.h"
#include "MillenniumHistory/Core/ProjectName.h"
#include "MillenniumHistory/Helper/MillenniumHistoryClassInvariantMacro.h"

#include <iostream>

MillenniumHistory::GUIMiddleLayer::GUIMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MillenniumHistory, GUIMiddleLayer)

void MillenniumHistory::GUIMiddleLayer::PrintSelect(const ProjectName& projectName)
{
    MILLENNIUM_HISTORY_CLASS_IS_VALID_1;

    projectName.PrintSelect();
}

void MillenniumHistory::GUIMiddleLayer::PrintEngineering(const String& engineeringName)
{
    COUT << SYSTEM_TEXT("正在执行工程：") << engineeringName << SYSTEM_TEXT("\n");
}
