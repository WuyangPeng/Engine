///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/19 16:57)

#include "GUIMiddleLayer.h"
#include "TheLastOverlord/Core/ProjectName.h"
#include "TheLastOverlord/Helper/TheLastOverlordClassInvariantMacro.h"

#include <iostream>

TheLastOverlord::GUIMiddleLayer::GUIMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    THE_LAST_OVERLORD_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlord, GUIMiddleLayer)

void TheLastOverlord::GUIMiddleLayer::PrintSelect(const ProjectName& projectName)
{
    THE_LAST_OVERLORD_CLASS_IS_VALID_1;

    projectName.PrintSelect();
}

void TheLastOverlord::GUIMiddleLayer::PrintEngineering(const String& engineeringName)
{
    COUT << SYSTEM_TEXT("正在执行工程：") << engineeringName << SYSTEM_TEXT("\n");
}
