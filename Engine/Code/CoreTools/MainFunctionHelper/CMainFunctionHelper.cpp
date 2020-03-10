// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 11:57)

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

#include <iostream>
#include <fstream>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::ostream;
using std::ofstream;
using std::exception;

CoreTools::CMainFunctionHelper
	::CMainFunctionHelper(int argc, char* argv[])
	:m_Argc{ argc }, m_Argv{ argv }, m_OsPtr{ nullptr }, m_Schedule{ ScheduleType::Failure }
{
	try
	{
		InitSingleton();
	}
	catch (Error& error)
	{
		CERR << error.GetError() << SYSTEM_TEXT('\n');
	}
	catch (exception& error)
	{
		cerr << error.what() << '\n';
	}
	catch (...)
	{
		cerr << "未知错误\n";
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
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
	else if (m_Argc < 1 || m_Argv[0] == nullptr || m_OsPtr == nullptr)
		return false;
	else if (m_Argc == 1)
		return ArgcEqualOneIsValid();
	else
		return ArgcUnequalOneIsValid();
}

bool CoreTools::CMainFunctionHelper
	::ArgcEqualOneIsValid() const noexcept
{
	if (m_OsPtr == &cout)
		return true;
	else
		return false;
}

bool CoreTools::CMainFunctionHelper
	::ArgcUnequalOneIsValid() const noexcept
{
	if (m_OsPtr != &cout)
		return true;
	else
		return false;
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
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_OsPtr;
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
	::InitMemory()
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
		m_OsPtr = NEW0 ofstream{ m_Argv[1],ofstream::out | ofstream::app };
	}
	else if (2 < m_Argc)
	{
		CommandHandle command{ m_Argc,m_Argv };

		m_OsPtr = NEW0 ofstream{ command.GetFileName().c_str(),ofstream::out | ofstream::app };
	}
	else
	{
		m_OsPtr = &cout;
	}

	if (m_OsPtr != nullptr)
	{
		m_Schedule = ScheduleType::Max;
	}
}

// private
void CoreTools::CMainFunctionHelper
	::DestroySingleton()
{
	DestroyOsPtr();
	DestroySmartPointer();
	DestroyMemory();
	DestroyLog();
	DestroyUniqueIDManager();
}

// private
void CoreTools::CMainFunctionHelper
	::DestroyOsPtr()
{
	if (1 < m_Argc)
	{
		// 在初始化失败的情况下，m_OsPtr可能是空指针，这里删除m_OsPtr是安全的。
		DELETE0(m_OsPtr);
	}
}

// private
void CoreTools::CMainFunctionHelper
	::DestroySmartPointer()
{
	if (ScheduleType::SmartPointer <= m_Schedule)
	{
		SmartPointerManager::Destroy();
	}
}

// private
void CoreTools::CMainFunctionHelper
	::DestroyMemory()
{
	if (ScheduleType::Memory <= m_Schedule)
	{
		MEMORY_DESTROY;
	}
}

// private
void CoreTools::CMainFunctionHelper
	::DestroyLog()
{
	if (ScheduleType::Log <= m_Schedule)
	{
		Log::Destroy();
	}
}

// private
void CoreTools::CMainFunctionHelper
	::DestroyUniqueIDManager()
{
	if (ScheduleType::UniqueIDManager <= m_Schedule)
	{
		UniqueIDManager::Destroy();
	}
}

void CoreTools::CMainFunctionHelper
	::SystemPause()
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









