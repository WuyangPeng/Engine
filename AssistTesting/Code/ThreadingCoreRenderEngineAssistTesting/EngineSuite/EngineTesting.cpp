/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/21 15:30)

#include "EngineTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

ThreadingCoreRenderEngineAssist::EngineTesting::EngineTesting(const OStreamShared& stream)
    : ParentType{ stream }, engineTestingName{ SYSTEM_TEXT("End"s) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngineAssist, EngineTesting)

void ThreadingCoreRenderEngineAssist::EngineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void ThreadingCoreRenderEngineAssist::EngineTesting::MainTest()
{
    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    if (const auto isStreamSharedFile = IsStreamSharedFile();
        !isStreamSharedFile)
    {
        ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(EngineTest);
    }
}

bool ThreadingCoreRenderEngineAssist::EngineTesting::EngineTest()
{
    engineTestingName.PrintSelect(GetStream());

    const auto select = System::GetSystemInput<int>();

    return ExecuteEngineTesting(select);
}

bool ThreadingCoreRenderEngineAssist::EngineTesting::ExecuteEngineTesting(int select)
{
    if (engineTestingName.IsSelectValid(select))
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ExecuteSelectEngineTesting, engineTestingName.GetEngineTestingName(select));

        return true;
    }
    else
    {
        return false;
    }
}

void ThreadingCoreRenderEngineAssist::EngineTesting::ExecuteSelectEngineTesting(const String& engineeringName)
{
    GetStream() << "����ִ�и�����Ԫ���Թ��̣�" << CoreTools::StringConversion::StandardConversionMultiByte(engineeringName) << "\n";

    ASSERT_TRUE(System::CreateSystemProcess(engineeringName));
}
