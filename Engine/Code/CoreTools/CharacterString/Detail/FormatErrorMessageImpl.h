// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 10:21)

// ��ʽ��Windows������Ϣ�ڲ��ӿ���
#ifndef CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
#define CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "CoreTools/DynamicLink/DynamicLinkFwd.h"

#include <boost/noncopyable.hpp> 
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE FormatErrorMessageImpl : private boost::noncopyable
	{
	public:
		using ClassType = FormatErrorMessageImpl;
		using WindowError = System::WindowError;

	public:
		explicit FormatErrorMessageImpl(WindowError lastError);
		~FormatErrorMessageImpl();

		CLASS_INVARIANT_DECLARE;

		const System::String GetErrorMessage() const;

	private:
		using LoadingLibraryPtr = std::shared_ptr<LoadingLibrary>;
		using Local = System::WindowHLocal;
		using DynamicLinkModule = System::DynamicLinkModule;

	private:
		void InitMessage();
		void AgainInitMessage();
		void InitNetworkMessage(DynamicLinkModule module);
		void LoadedModuleSucceed(DynamicLinkModule module);
		void LoadedModuleFailure();
		void ReleaseMemory();	

	private:
		WindowError m_LastError;
		Local m_ErrorMessage; 
	};
}

#endif // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
