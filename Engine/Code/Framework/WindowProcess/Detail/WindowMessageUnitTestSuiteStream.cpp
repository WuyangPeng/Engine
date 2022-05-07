///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 16:43)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteStream.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;
using std::string;

Framework::WindowMessageUnitTestSuiteStream::WindowMessageUnitTestSuiteStream(bool usecommand)
    : oStreamShared{ GenerateStreamShared(usecommand) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// static
// private
Framework::WindowMessageUnitTestSuiteStream::CommandSharedPtr Framework::WindowMessageUnitTestSuiteStream::GenerateCommandSharedPtr(bool usecommand)
{
    if (usecommand)
    {
        auto commandLine = GetMultiByteCommandLine();

        return make_shared<Command>(commandLine.c_str());
    }
    else
    {
        return nullptr;
    }
}

// static
// private
Framework::WindowMessageUnitTestSuiteStream::OStreamShared Framework::WindowMessageUnitTestSuiteStream::GenerateStreamShared(bool usecommand)
{
    auto command = GenerateCommandSharedPtr(usecommand);

    const auto isFile = (command != nullptr) && (command->GetExcessArgumentsCount() != 0);

    if (isFile)
    {
        return OStreamShared{ command->GetFileName() };
    }
    else
    {
        return OStreamShared{ true };
    }
}

// static
// private
string Framework::WindowMessageUnitTestSuiteStream::GetMultiByteCommandLine()
{
    auto commandLine = System::GetSystemCommandLine();
    return CoreTools::StringConversion::StandardConversionMultiByte(commandLine);
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageUnitTestSuiteStream)

CoreTools::OStreamShared Framework::WindowMessageUnitTestSuiteStream::GetStreamShared() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return oStreamShared;
}
