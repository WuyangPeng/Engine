// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/20 11:53)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBase.h"
#include "Flags/Directory.h"
#include "Flags/MainFunctionSchedule.h"
#include "Detail/DirectoryDefaultName.h"
#include "Detail/MainFunctionHelperBaseImpl.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/ClassInvariant/NoexceptDetail.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"
#include "CoreTools/CharacterString/StringConversion.h"

using std::move;
using std::make_shared;
using namespace std::literals;

Framework::MainFunctionHelperBase
	::MainFunctionHelperBase(const EnvironmentDirectory& environmentDirectory)
	:m_Impl{ }, m_MainFunctionSchedule{ MainFunctionSchedule::Failure }
{
	MainFunctionHelperInit(environmentDirectory);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::MainFunctionHelperBase
	::MainFunctionHelperBase(MainFunctionHelperBase&& rhs) noexcept
	:m_Impl{ move(rhs.m_Impl) }, m_MainFunctionSchedule{ rhs.m_MainFunctionSchedule }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::MainFunctionHelperBase& Framework::MainFunctionHelperBase
	::operator=(MainFunctionHelperBase&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Impl = move(rhs.m_Impl);
	m_MainFunctionSchedule = rhs.m_MainFunctionSchedule;

	return *this;
}

Framework::MainFunctionHelperBase
	::~MainFunctionHelperBase() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;

	CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::MainFunctionHelperBase
	::IsValid() const noexcept
{
	if ((m_MainFunctionSchedule == MainFunctionSchedule::Max) ^ (m_Impl == nullptr))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::String Framework::MainFunctionHelperBase
	::GetEngineInstallationDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if (m_Impl != nullptr)
		return m_Impl->GetEngineInstallationDirectory();
	else
		return DirectoryDefaultName::GetDefaultNullName();
}

void Framework::MainFunctionHelperBase
	::Destroy()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (MainFunctionSchedule::Failure < m_MainFunctionSchedule)
	{
		MainFunctionHelperDestroy();
	}
}

int Framework::MainFunctionHelperBase
	::Run()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	EXCEPTION_TRY
	{
		if (m_Impl != nullptr)
		{
			return DoRun();
		}
	}
	EXCEPTION_ALL_CATCH(Framework)

	return -1;
}

// private
void Framework::MainFunctionHelperBase
	::MainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory)
{
	EXCEPTION_TRY
	{
		DoMainFunctionHelperInit(environmentDirectory);
	}
	EXCEPTION_ENTRY_POINT_CATCH
}

// private
void Framework::MainFunctionHelperBase
	::DoMainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory)
{
	InitUniqueIDManager();
	InitLog(environmentDirectory);
	InitMemory();
	InitInitTerm();
	InitEnvironment();
	InitSmartPointer();
	InitImpl(environmentDirectory);
}

// private
void Framework::MainFunctionHelperBase
	::InitUniqueIDManager()
{
	CoreTools::UniqueIDManager::Create(CoreTools::UniqueIDSelect::Max);
	m_MainFunctionSchedule = MainFunctionSchedule::UniqueID;
}

void Framework::MainFunctionHelperBase
	::InitLog(const EnvironmentDirectory& environmentDirectory)
{
	CoreTools::Log::Create();
	auto logFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Log.json"s);
	LOG_SINGLETON.LoadConfiguration(CoreTools::StringConversion::StandardConversionMultiByte(logFileName));
	m_MainFunctionSchedule = MainFunctionSchedule::Log;
}

void Framework::MainFunctionHelperBase
	::InitMemory() noexcept(CoreTools::g_MemoryNoexcept)
{
	MemoryCreate();
	m_MainFunctionSchedule = MainFunctionSchedule::Memory;
}

void Framework::MainFunctionHelperBase
	::InitInitTerm()
{
	CoreTools::InitTerm::ExecuteInitializers();
	m_MainFunctionSchedule = MainFunctionSchedule::InitTerm;
}

void Framework::MainFunctionHelperBase
	::InitEnvironment()
{
	CoreTools::Environment::Create();
	m_MainFunctionSchedule = MainFunctionSchedule::Environment;
}

void Framework::MainFunctionHelperBase
	::InitSmartPointer()
{
	CoreTools::SmartPointerManager::Create();
	m_MainFunctionSchedule = MainFunctionSchedule::SmartPointer;
}

void Framework::MainFunctionHelperBase
	::InitImpl(const EnvironmentDirectory& environmentDirectory)
{
	m_Impl = make_shared<ImplType>(environmentDirectory);
	m_MainFunctionSchedule = MainFunctionSchedule::Max;
}

// private
void Framework::MainFunctionHelperBase
	::MainFunctionHelperDestroy()
{
	DestroyImpl();
	DestroySmartPointer();
	DestroyEnvironment();
	DestroyInitTerm();
	DestroyMemory();
	DestroyLog();
	DestroyUniqueIDManager();
}

void Framework::MainFunctionHelperBase
	::DestroyImpl() noexcept
{
	if (MainFunctionSchedule::Max <= m_MainFunctionSchedule)
	{
		m_Impl.reset();
		m_MainFunctionSchedule = MainFunctionSchedule::SmartPointer;
	}
}

void Framework::MainFunctionHelperBase
	::DestroySmartPointer() noexcept
{
	if (MainFunctionSchedule::SmartPointer <= m_MainFunctionSchedule)
	{
		CoreTools::SmartPointerManager::Destroy();
		m_MainFunctionSchedule = MainFunctionSchedule::Environment;
	}
}

void Framework::MainFunctionHelperBase
	::DestroyEnvironment() noexcept
{
	if (MainFunctionSchedule::Environment <= m_MainFunctionSchedule)
	{
		CoreTools::Environment::Destroy();
		m_MainFunctionSchedule = MainFunctionSchedule::InitTerm;
	}
}

void Framework::MainFunctionHelperBase
	::DestroyInitTerm()
{
	if (MainFunctionSchedule::InitTerm <= m_MainFunctionSchedule)
	{
		CoreTools::InitTerm::ExecuteTerminators();
		m_MainFunctionSchedule = MainFunctionSchedule::Memory;
	}
}

void Framework::MainFunctionHelperBase
	::DestroyMemory() noexcept(CoreTools::g_MemoryNoexcept)
{
	if (MainFunctionSchedule::Memory <= m_MainFunctionSchedule)
	{
		MEMORY_DESTROY;
		m_MainFunctionSchedule = MainFunctionSchedule::Log;
	}
}

void Framework::MainFunctionHelperBase
	::DestroyLog() noexcept
{
	if (MainFunctionSchedule::Log <= m_MainFunctionSchedule)
	{
		CoreTools::Log::Destroy();
		m_MainFunctionSchedule = MainFunctionSchedule::UniqueID;
	}
}

void Framework::MainFunctionHelperBase
	::DestroyUniqueIDManager()
{
	if (MainFunctionSchedule::UniqueID <= m_MainFunctionSchedule)
	{
		CoreTools::UniqueIDManager::Destroy();
		m_MainFunctionSchedule = MainFunctionSchedule::Failure;
	}
}

// private
void Framework::MainFunctionHelperBase
	::MemoryCreate() noexcept(CoreTools::g_MemoryNoexcept)
{
	// 要指定自己的分配器和释放器，
	// 使用宏MEMORY_CREATE_WITH_ALLOCATOR_AND_DEALLOCATOR(allocator,deallocator)
	MEMORY_CREATE;
}

// protected
bool Framework::MainFunctionHelperBase
	::IsDestroy() const noexcept
{
	return (MainFunctionSchedule::Failure == m_MainFunctionSchedule);
}

// protected
Framework::EnvironmentDirectory Framework::MainFunctionHelperBase
	::GetEnvironmentDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if (m_Impl != nullptr)
	{
		return m_Impl->GetEnvironmentDirectory();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("获取环境目录失败！"s));
	}
}

