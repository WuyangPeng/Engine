///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/19 16:57)

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
    COUT << SYSTEM_TEXT("����ִ�й��̣�") << engineeringName << SYSTEM_TEXT("\n");
}
