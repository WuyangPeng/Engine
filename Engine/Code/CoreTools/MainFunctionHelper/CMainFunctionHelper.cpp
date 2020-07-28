// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:57)

#include "CoreTools/CoreToolsExport.h"

#include "CMainFunctionHelper.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/MemoryTools/MemoryManager.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "System/Helper/PragmaWarning.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
 

using std::cout;
using std::cerr;
using std::ostream;
using std::ofstream;
using std::exception;

CoreTools::CMainFunctionHelper
	::CMainFunctionHelper(int argc, char** argv)
	:m_Argc{ argc }, m_Argv{ argv }, m_OsPtr{ }, m_Schedule{ ScheduleType::Failure }
{
	try
	{
		InitSingleton();
	}
	catch (const Error& error)
	{
		CERR << error.GetError() << SYSTEM_TEXT('\n');
	}
	catch (const exception& error)
	{
		cerr << error.what() << '\n';
	}
	catch (...)
	{
		cerr << "Œ¥÷™¥ÌŒÛ\n";
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionHelper
	::CMainFunctionHelper(CMainFunctionHelper&& rhs) noexcept
	:m_Argc{ rhs.m_Argc }, m_Argv{ rhs.m_Argv }, m_OsPtr{ rhs.m_OsPtr }, m_Schedule{ rhs.m_Schedule }
{
	rhs.m_Argv = nullptr;
	rhs.m_OsPtr = OStreamShared{ };

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionHelper& CoreTools::CMainFunctionHelper
	::operator=(CMainFunctionHelper&& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Argc = rhs.m_Argc;
	m_Argv = rhs.m_Argv;
	m_OsPtr = rhs.m_OsPtr;
	m_Schedule = rhs.m_Schedule; 

	rhs.m_Argv = nullptr;
	rhs.m_OsPtr = OStreamShared{ };

	return *this;
}

CoreTools::CMainFunctionHelper
	::~CMainFunctionHelper()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	DestroySingleton();
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CMainFunctionHelper
	::IsValid() const noexcept
{
	if (m_Schedule < ScheduleType::Max)
		return true;
	else if (m_Argc < 1 || *m_Argv == nullptr)
		return false;
	else
		return true;
} 
#endif // OPEN_CLASS_INVARIANT

int CoreTools::CMainFunctionHelper
	::GetArgc() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Argc;
}

char** CoreTools::CMainFunctionHelper
	::GetArgv() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Argv;
}

ostream* CoreTools::CMainFunctionHelper
	::GetOStream() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return &m_OsPtr.GetStream();
}

int CoreTools::CMainFunctionHelper
	::Run()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		if (m_Schedule == ScheduleType::Max)
			return DoRun();
		else
			return -1;
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	return -1;
}

// private
void CoreTools::CMainFunctionHelper
	::InitSingleton()
{
	InitUniqueIDManager();
	InitLog();
	InitMemory();
	InitSmartPointer();
	GenerateOsPtr();
	InitStreamLocale();
}

// private
void CoreTools::CMainFunctionHelper
	::InitUniqueIDManager()
{
	UniqueIDManager::Create(UniqueIDSelect::Max);

	m_Schedule = ScheduleType::UniqueIDManager;
}

// private
void CoreTools::CMainFunctionHelper
	::InitLog()
{
	Log::Create();
	LOG_SINGLETON.LoadConfiguration("Configuration/Log.json");

	m_Schedule = ScheduleType::Log;
}

// private
void CoreTools::CMainFunctionHelper
	::InitMemory() noexcept(g_MemoryNoexcept)
{
	MEMORY_CREATE;

	m_Schedule = ScheduleType::Memory;
}

// private
void CoreTools::CMainFunctionHelper
	::InitSmartPointer()
{
	SmartPointerManager::Create();

	m_Schedule = ScheduleType::SmartPointer;
}

// private
void CoreTools::CMainFunctionHelper
	::GenerateOsPtr()
{
	if (m_Argc == 2)
	{

#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26481)
		m_OsPtr = OStreamShared{ std::string{ m_Argv[1] } };
		#include STSTEM_WARNING_POP
	}
	else if (2 < m_Argc)
	{
		CommandHandle command{ m_Argc,m_Argv };

		m_OsPtr = OStreamShared{ command.GetFileName() }; 
	}
	else
	{
		m_OsPtr = OStreamShared{ };
	}
	 
	m_Schedule = ScheduleType::Max;	 
}

// private
void CoreTools::CMainFunctionHelper
	::DestroySingleton() noexcept
{
	DestroyOsPtr();
	DestroySmartPointer();
	DestroyMemory();
	DestroyLog();
	DestroyUniqueIDManager();
}

// private
void CoreTools::CMainFunctionHelper
	::DestroyOsPtr() noexcept
{
	 
}

// private
void CoreTools::CMainFunctionHelper
	::DestroySmartPointer() noexcept
{
	if (ScheduleType::SmartPointer <= m_Schedule)
	{
		SmartPointerManager::Destroy();
	}
}

// private
void CoreTools::CMainFunctionHelper
	::DestroyMemory() noexcept
{
	if (ScheduleType::Memory <= m_Schedule)
	{
		MEMORY_DESTROY;
	}
}

// private
void CoreTools::CMainFunctionHelper
	::DestroyLog() noexcept
{
	if (ScheduleType::Log <= m_Schedule)
	{
		Log::Destroy();
	}
}

// private
void CoreTools::CMainFunctionHelper
	::DestroyUniqueIDManager() noexcept
{
	if (ScheduleType::UniqueIDManager <= m_Schedule)
	{
		UniqueIDManager::Destroy();
	}
}

void CoreTools::CMainFunctionHelper
	::SystemPause() noexcept
{
	System::SystemPause();
}

void CoreTools::CMainFunctionHelper
	::InitStreamLocale()
{
	std::locale nullLocale{ "" };

	COUT.imbue(nullLocale);
	CIN.imbue(nullLocale);
	CERR.imbue(nullLocale);
	CLOG.imbue(nullLocale);
}

CoreTools::OStreamShared CoreTools::CMainFunctionHelper
	::GetStreamShared() const noexcept
{
	return m_OsPtr;
}








