///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.5 (2023/04/03 09:35)

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
    COUT << SYSTEM_TEXT("����ִ�й��̣�") << engineeringName << SYSTEM_TEXT("\n");
}
