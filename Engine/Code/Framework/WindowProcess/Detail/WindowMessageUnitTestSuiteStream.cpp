// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:52)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteStream.h"
#include "System/Helper/UnicodeUsing.h" 
#include "System/Helper/PragmaWarning.h"
#include "System/Window/WindowProcess.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;
using std::make_shared;

Framework::WindowMessageUnitTestSuiteStream
	::WindowMessageUnitTestSuiteStream(bool usecommand)
	: m_OStreamShared{ GenerateStreamShared(usecommand) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// static
// private
Framework::WindowMessageUnitTestSuiteStream::CommandSharedPtr Framework::WindowMessageUnitTestSuiteStream
	::GenerateCommandSharedPtr(bool usecommand)
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
Framework::WindowMessageUnitTestSuiteStream::OStreamShared Framework::WindowMessageUnitTestSuiteStream
	::GenerateStreamShared(bool usecommand)
{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26486)
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
	#include STSTEM_WARNING_POP
}

// static
// private
string Framework::WindowMessageUnitTestSuiteStream
	::GetMultiByteCommandLine()
{
	auto commandLine = System::GetSystemCommandLine();
	return CoreTools::StringConversion::StandardConversionMultiByte(commandLine);
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageUnitTestSuiteStream)

CoreTools::OStreamShared Framework::WindowMessageUnitTestSuiteStream
	::GetStreamShared() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_OStreamShared;
}



