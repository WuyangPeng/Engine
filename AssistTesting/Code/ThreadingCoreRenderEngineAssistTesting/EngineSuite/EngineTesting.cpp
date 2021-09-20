///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 16:12)

#include "EngineTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;
using namespace std::literals;

ThreadingCoreRenderEngineAssist::EngineTesting::EngineTesting(const OStreamShared& stream)
    : ParentType{ stream }, m_EngineTestingName{ SYSTEM_TEXT("End"s) }
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

    const auto isStreamSharedFile = IsStreamSharedFile();

    if (!isStreamSharedFile)
    {
        ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(EngineTest);
    }
}

bool ThreadingCoreRenderEngineAssist::EngineTesting::EngineTest()
{
    m_EngineTestingName.PrintSelect(GetStream());

    const auto select = System::GetSystemInput<int>();

    return ExecuteEngineTesting(select);
}

bool ThreadingCoreRenderEngineAssist::EngineTesting::ExecuteEngineTesting(int select)
{
    if (m_EngineTestingName.IsSelectValid(select))
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ExecuteSelectEngineTesting, m_EngineTestingName.GetEngineTestingName(select));

        return true;
    }
    else
    {
        return false;
    }
}

void ThreadingCoreRenderEngineAssist::EngineTesting::ExecuteSelectEngineTesting(const String& engineeringName)
{
    GetStream() << "正在执行辅助单元测试工程：" << CoreTools::StringConversion::StandardConversionMultiByte(engineeringName) << "\n";

    ASSERT_TRUE(System::CreateSystemProcess(engineeringName));
}
