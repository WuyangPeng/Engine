// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 10:04)

// �򿪶�̬���ӿ�
#ifndef CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_IMPL_H
#define CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"

#include <boost/noncopyable.hpp>
#include <string> 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE LoadingLibraryImpl : private boost::noncopyable
	{
	public:
		using ClassType = LoadingLibraryImpl;
		using String = System::String;
		using LoadLibrary = System::LoadLibrary;
		using DynamicLinkString = System::DynamicLinkString;
		using DynamicLinkModule = System::DynamicLinkModule;
		using DynamicLinkProcess = System::DynamicLinkProcess;

	public:
		LoadingLibraryImpl(const String& fileName, LoadLibrary flags);
		~LoadingLibraryImpl();

		CLASS_INVARIANT_DECLARE;

		DynamicLinkModule GetLoadedModule() noexcept;
		DynamicLinkProcess GetProcessAddress(const std::string& processName);

	private:
		DynamicLinkString m_FileName;
		DynamicLinkModule m_Library;
	};
}

#endif // CORE_TOOLS_DLL_TOOLS_LOADING_LIBRARY_IMPL_H
