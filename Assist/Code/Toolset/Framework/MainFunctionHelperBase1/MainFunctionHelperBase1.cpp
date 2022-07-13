///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 10:50)

#include "MainFunctionHelperBase1.h"
#include "System/Time/DeltaTime.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <iostream>

Framework::MainFunctionHelperBase1::MainFunctionHelperBase1(MAYBE_UNUSED int argc, MAYBE_UNUSED char** argv, MAYBE_UNUSED const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainFunctionHelperBase1)

int Framework::MainFunctionHelperBase1::DoRun()
{
    COUT << SYSTEM_TEXT("���氲װĿ¼Ϊ��Ϊ�ձ�ʾ����ǰ·������")
         << GetEngineInstallationDirectory()
         << SYSTEM_TEXT('\n')
         << SYSTEM_TEXT("����IsDestroy����ֵӦ��Ϊfalse��")
         << std::boolalpha
         << IsDestroy()
         << std::noboolalpha
         << SYSTEM_TEXT("��\n");

    System::SystemPause();

    return 0;
}
