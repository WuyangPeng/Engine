///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起测试版本：0.8.1.0 (2022/08/03 13:42)

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

RiseOfHistory::EngineTesting::EngineTesting(const OStreamShared& stream)
    : ParentType{ stream }, engineTestingName{ SYSTEM_TEXT("End"s) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RiseOfHistory, EngineTesting)

void RiseOfHistory::EngineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void RiseOfHistory::EngineTesting::MainTest()
{
    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    const auto isStreamSharedFile = IsStreamSharedFile();

    if (!isStreamSharedFile)
    {
        ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(EngineTest);
    }
}

bool RiseOfHistory::EngineTesting::EngineTest()
{
    engineTestingName.PrintSelect(GetStream());

    auto select = System::GetSystemInput<int>();

    return ExecuteEngineTesting(select);
}

bool RiseOfHistory::EngineTesting::ExecuteEngineTesting(int select)
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

void RiseOfHistory::EngineTesting::ExecuteSelectEngineTesting(const String& engineeringName)
{
    GetStream() << "正在执行单元测试工程：" << CoreTools::StringConversion::StandardConversionMultiByte(engineeringName) << "\n";

    ASSERT_TRUE(System::CreateSystemProcess(engineeringName));
}