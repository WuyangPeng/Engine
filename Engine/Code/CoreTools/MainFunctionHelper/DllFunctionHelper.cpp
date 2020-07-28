// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:59)

#include "CoreTools/CoreToolsExport.h"

#include "DllFunctionHelper.h"
#include "System/Window/WindowSystem.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "CoreTools/Threading/DllMutex.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <stdexcept>

using std::runtime_error;
using std::string;

void CoreTools::DllFunctionHelper
	::InitializeMutex(DllMutex* mutex)
{
	CORE_TOOLS_ASSERTION_0(mutex != nullptr, "DllMutex÷∏’ÎŒ™ø’£°");

	try
	{
		mutex->Initialize();
	}
	catch (const Error& error)
	{
		JudgeUserSelectionWithTChar(error.GetError().c_str());
	}
	catch (const runtime_error& error)
	{
		JudgeUserSelectionWithChar(error.what());
	}
	catch (...)
	{
		JudgeUserSelectionWithTChar(SYSTEM_TEXT("Œ¥÷™¥ÌŒÛ£°"));
	}
}

void CoreTools::DllFunctionHelper
	::DeleteMutex(DllMutex* mutex)
{
	CORE_TOOLS_ASSERTION_0(mutex != nullptr, "DllMutex÷∏’ÎŒ™ø’£°");

	mutex->Delete();
}

void CoreTools::DllFunctionHelper
	::JudgeUserSelectionWithTChar(const System::String& message) noexcept
{
	const System::DialogBoxCommand type = System::MessageBoxSelectionWithTChar(message.c_str(), SYSTEM_TEXT("¥ÌŒÛ"));

	JudgeSelection(type);
}

void CoreTools::DllFunctionHelper
	::JudgeSelection(System::DialogBoxCommand selection) noexcept
{
	switch (selection)
	{
		case System::DialogBoxCommand::IDYes:
		{
			// µ˜ ‘∂œµ„°£
			System::DebugBreak();

			break;
		}
		case System::DialogBoxCommand::IDNo:
		{
			// ºÃ–¯÷¥––°£
			break;
		}
		case System::DialogBoxCommand::IDCancel:
		default:
		{
			// ÷’÷π÷¥––°£
			System::Exit();
			break;
		}
	}
}

void CoreTools::DllFunctionHelper
	::JudgeUserSelectionWithChar(const string& message) noexcept
{
	const auto type = System::MessageBoxSelectionWithChar(message.c_str(), "¥ÌŒÛ");

	JudgeSelection(type);
}

