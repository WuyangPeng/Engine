/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.1 (2025/04/30 11:31)

#include "EngineTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite//UnitTestDetail.h"

ThreadingCoreRenderEngine::EngineTesting::EngineTesting(const OStreamShared& stream)
    : ParentType{ stream }, engineTestingName{ SYSTEM_TEXT("End") }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngine, EngineTesting)

void ThreadingCoreRenderEngine::EngineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void ThreadingCoreRenderEngine::EngineTesting::MainTest()
{
    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    if (const auto isStreamSharedFile = IsStreamSharedFile();
        !isStreamSharedFile)
    {
        ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(EngineTest);
    }
}

bool ThreadingCoreRenderEngine::EngineTesting::EngineTest()
{
    engineTestingName.PrintSelect(GetStream());

    const auto select = System::GetSystemInput<int>();

    return ExecuteEngineTesting(select);
}

bool ThreadingCoreRenderEngine::EngineTesting::ExecuteEngineTesting(int select)
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

void ThreadingCoreRenderEngine::EngineTesting::ExecuteSelectEngineTesting(const String& engineeringName)
{
    GetStream() << "正在执行单元测试工程：" << CoreTools::StringConversion::StandardConversionMultiByte(engineeringName) << "\n";

    ASSERT_TRUE(System::CreateSystemProcess(engineeringName));
}