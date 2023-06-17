///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߲��԰汾��0.9.0.12 (2023/06/13 22:39)

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

MillenniumHistory::EngineTesting::EngineTesting(const OStreamShared& stream)
    : ParentType{ stream }, engineTestingName{ SYSTEM_TEXT("End"s) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MillenniumHistory, EngineTesting)

void MillenniumHistory::EngineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void MillenniumHistory::EngineTesting::MainTest()
{
    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    const auto isStreamSharedFile = IsStreamSharedFile();

    if (!isStreamSharedFile)
    {
        ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(EngineTest);
    }
}

bool MillenniumHistory::EngineTesting::EngineTest()
{
    engineTestingName.PrintSelect(GetStream());

    const auto select = System::GetSystemInput<int>();

    return ExecuteEngineTesting(select);
}

bool MillenniumHistory::EngineTesting::ExecuteEngineTesting(int select)
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

void MillenniumHistory::EngineTesting::ExecuteSelectEngineTesting(const String& engineeringName)
{
    GetStream() << "����ִ�е�Ԫ���Թ��̣�" << CoreTools::StringConversion::StandardConversionMultiByte(engineeringName) << "\n";

    ASSERT_TRUE(System::CreateSystemProcess(engineeringName));
}