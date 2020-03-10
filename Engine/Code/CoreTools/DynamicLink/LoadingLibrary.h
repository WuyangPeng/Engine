// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 10:04)

// 打开动态链接库
#ifndef CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_H
#define CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LoadingLibraryImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE LoadingLibrary : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(LoadingLibrary);
		using String = System::String;
		using LoadLibrary = System::LoadLibrary;
		using DynamicLinkModule = System::DynamicLinkModule;
		using DynamicLinkProcess = System::DynamicLinkProcess;

	public:
		LoadingLibrary(const String& fileName, LoadLibrary flags);

		CLASS_INVARIANT_DECLARE;

		DynamicLinkModule GetLoadedModule() noexcept;
		DynamicLinkProcess GetProcessAddress(const std::string& procName);

	private:
		IMPL_TYPE_DECLARE(LoadingLibrary);
	};
}

#endif // CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_H
