/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:23)

#include "ProcessTestingBase.h"
#include "System/Threading/Process.h"
#include "System/Threading/Thread.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ProcessTestingBase::ProcessTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      processFullPath{ GetEngineeringDirectory() + SYSTEM_TEXT("ProcessTest") + GetEngineeringSuffix() + GetEngineeringExeSuffix() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ProcessTestingBase)

void System::ProcessTestingBase::CloseProcessTest(const ProcessInformation& processInformation)
{
    ASSERT_TRUE(CloseSystemThread(processInformation.hThread));
    ASSERT_TRUE(CloseSystemProcess(processInformation.hProcess));
}

System::String System::ProcessTestingBase::GetProcessFullPath() const
{
    return processFullPath;
}
