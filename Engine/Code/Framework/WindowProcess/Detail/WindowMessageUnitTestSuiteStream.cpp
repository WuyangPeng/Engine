/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:29)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteStream.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowMessageUnitTestSuiteStream::WindowMessageUnitTestSuiteStream(bool useCommand)
    : oStreamShared{ GenerateStreamShared(useCommand) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowMessageUnitTestSuiteStream::CommandSharedPtr Framework::WindowMessageUnitTestSuiteStream::GenerateCommandSharedPtr(bool useCommand)
{
    if (useCommand)
    {
        const auto commandLine = GetMultiByteCommandLine();

        return std::make_shared<Command>(commandLine.c_str());
    }
    else
    {
        return nullptr;
    }
}

Framework::WindowMessageUnitTestSuiteStream::OStreamShared Framework::WindowMessageUnitTestSuiteStream::GenerateStreamShared(bool useCommand)
{
    const auto command = GenerateCommandSharedPtr(useCommand);

    if (const auto isFile = (command != nullptr) && (command->GetExcessArgumentsCount() != 0);
        isFile)
    {
        return OStreamShared{ command->GetFileName() };
    }
    else
    {
        return OStreamShared{ true };
    }
}

std::string Framework::WindowMessageUnitTestSuiteStream::GetMultiByteCommandLine()
{
    const auto commandLine = System::GetSystemCommandLine();

    return CoreTools::StringConversion::StandardConversionMultiByte(commandLine);
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageUnitTestSuiteStream)

CoreTools::OStreamShared Framework::WindowMessageUnitTestSuiteStream::GetStreamShared() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return oStreamShared;
}
