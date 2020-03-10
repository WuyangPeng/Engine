// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 17:55)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBase.h"
#include "Detail/MainFunctionHelperBaseImpl.h"

#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"

#include <iostream>
#include <stdexcept>
#include <type_traits>

using std::cerr;
using std::string;
using std::runtime_error;
using CoreTools::Error;
using CoreTools::Log;
using CoreTools::InitTerm;
using CoreTools::Environment;
using CoreTools::StringConversion;
using CoreTools::SmartPointerManager; 

Framework::MainFunctionHelperBase
	::MainFunctionHelperBase(const EnvironmentDirectory& environmentDirectory)
	:m_Impl{}, m_Destroy{ false }, m_EnvironmentDirectory{ environmentDirectory }
{
	MainFunctionHelperInit();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::MainFunctionHelperBase
	::MainFunctionHelperInit()
{
	try
	{
		System::String logFileName = m_EnvironmentDirectory.GetConfigurationPath() + SYSTEM_TEXT("Log.json");

		CoreTools::UniqueIDManager::Create(CoreTools::UniqueIDSelect::Max);

		Log::Create();
		LOG_SINGLETON.LoadConfiguration(StringConversion::StandardConversionMultiByte(logFileName));

		MemoryCreate();
		InitTerm::ExecuteInitializers();
		Environment::Create();	
		SmartPointerManager::Create();

		m_Impl.reset(new ImplType(m_EnvironmentDirectory));
	}
	catch (Error& error)
	{
		CERR << error.GetError() << SYSTEM_TEXT('\n');
	}
	catch(runtime_error& error)
	{
		cerr << error.what() << '\n';
	}
	catch(...)
	{
		CERR << SYSTEM_TEXT("未知错误\n");
	}
}

Framework::MainFunctionHelperBase
	::~MainFunctionHelperBase()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;

	Destroy();
}

void Framework::MainFunctionHelperBase
	::Destroy()
{
    static_assert(std::is_same<ClassShareType::NonConstMember,CoreTools::TrueType>::value,"");

	FRAMEWORK_CLASS_IS_VALID_9;

	if(!m_Destroy)
	{
		MainFunctionHelperDestroy();

		m_Destroy = true;
	}
}

// private
void Framework::MainFunctionHelperBase
	::MainFunctionHelperDestroy()
{	
	SmartPointerManager::Destroy();
	Environment::Destroy();
	InitTerm::ExecuteTerminators();	
	MEMORY_DESTROY;
	Log::Destroy();
	CoreTools::UniqueIDManager::Destroy();
}

CLASS_INVARIANT_STUB_DEFINE(Framework,MainFunctionHelperBase);

int Framework::MainFunctionHelperBase
	::Run()
{
    static_assert(std::is_same<ClassShareType::NonConstMember,CoreTools::TrueType>::value,"");

	FRAMEWORK_CLASS_IS_VALID_9;

	try
	{
		if (m_Impl != nullptr)
		{
			return DoRun();
		}
	}
	catch (Error& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, Framework)
			<< error
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
	catch(runtime_error& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, Framework)
			<< error.what()
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
	catch(...)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, Framework)
			<< SYSTEM_TEXT("未知错误")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}

	return -1;
}

System::String Framework::MainFunctionHelperBase
	::GetEngineInstallationDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if(m_Impl != nullptr)
		return m_Impl->GetEngineInstallationDirectory();
	else
		return System::String();
}

// protected
bool Framework::MainFunctionHelperBase
	::IsDestroy() const
{
	return m_Destroy;
}

// private
void Framework::MainFunctionHelperBase
	::MemoryCreate()
{
	// 要指定自己的分配器和释放器，
	// 使用宏MEMORY_CREATE_WITH_ALLOCATOR_AND_DEALLOCATOR(allocator,deallocator)
	MEMORY_CREATE;
}
