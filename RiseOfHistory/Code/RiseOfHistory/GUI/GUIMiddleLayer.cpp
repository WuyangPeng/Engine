///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.0 (2022/08/03 11:01)

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
    COUT << SYSTEM_TEXT("����ִ�й��̣�") << engineeringName << SYSTEM_TEXT("\n");
}