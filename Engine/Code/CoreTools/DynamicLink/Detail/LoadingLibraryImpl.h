// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 10:04)

// 打开动态链接库
#ifndef CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_IMPL_H
#define CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"

 
#include <string> 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE LoadingLibraryImpl  
	{
	public:
		using ClassType = LoadingLibraryImpl;
		using String = System::String;
		using LoadLibraryType = System::LoadLibraryType;
		using DynamicLinkString = System::DynamicLinkString;
		using DynamicLinkModule = System::DynamicLinkModule;
		using DynamicLinkProcess = System::DynamicLinkProcess;

	public:
		LoadingLibraryImpl(const String& fileName, LoadLibraryType flags);
		~LoadingLibraryImpl() noexcept;
		LoadingLibraryImpl(const LoadingLibraryImpl&) = delete;
		LoadingLibraryImpl& operator=(const LoadingLibraryImpl&) = delete;
		LoadingLibraryImpl(LoadingLibraryImpl&&) noexcept = delete;
		LoadingLibraryImpl& operator=(LoadingLibraryImpl&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		DynamicLinkModule GetLoadedModule() noexcept;
		DynamicLinkProcess GetProcessAddress(const std::string& processName);

	private:
		DynamicLinkString m_FileName;
		DynamicLinkModule m_Library;
	};
}

#endif // CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_IMPL_H
