// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 10:05)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibraryImpl.h"
#include "System/DynamicLink/DynamicLink.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::LoadingLibraryImpl
	::LoadingLibraryImpl(const String& fileName, LoadLibrary flags)
	:m_FileName{ StringConversion::StandardConversionDynamicLinkString(fileName) },
	 m_Library{ System::LoadDynamicLibrary(m_FileName.c_str(),flags) }
{
	if (m_Library == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("加载（") + m_FileName + SYSTEM_TEXT("）动态链接库失败。"));
	}
	   
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::LoadingLibraryImpl
	::~LoadingLibraryImpl() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	if (m_Library != nullptr && !System::FreeDynamicLibrary(m_Library))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("释放已加载的（")
			<< m_FileName
			<< SYSTEM_TEXT("）动态链接库失败。")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LoadingLibraryImpl)

CoreTools::LoadingLibraryImpl::DynamicLinkModule CoreTools::LoadingLibraryImpl
	::GetLoadedModule() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Library;
}

CoreTools::LoadingLibraryImpl::DynamicLinkProcess CoreTools::LoadingLibraryImpl
	::GetProcessAddress(const string& processName)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto process = System::GetProcessAddress(m_Library, processName.c_str());

	if (process != nullptr)
	{
		return process;
	}
	else
	{		
		THROW_EXCEPTION(SYSTEM_TEXT("获取函数（") + StringConversion::MultiByteConversionStandard(processName) + SYSTEM_TEXT("）地址失败失败。"));
	}
}