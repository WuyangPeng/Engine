// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 10:21)

// 格式化Windows错误消息内部接口类
#ifndef CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
#define CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "CoreTools/DynamicLink/DynamicLinkFwd.h"

#include <string>
#include <memory>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE FormatErrorMessageImpl  
	{
	public:
		using ClassType = FormatErrorMessageImpl;
		using WindowError = System::WindowError;

	public:
		explicit FormatErrorMessageImpl(WindowError lastError);
		~FormatErrorMessageImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		const System::String GetErrorMessage() const;

		FormatErrorMessageImpl(const FormatErrorMessageImpl&) = delete;
		FormatErrorMessageImpl& operator=(const FormatErrorMessageImpl&) = delete;

		FormatErrorMessageImpl(FormatErrorMessageImpl&&) noexcept = delete;
		FormatErrorMessageImpl& operator=(FormatErrorMessageImpl&&) noexcept = delete;

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
		void ReleaseMemory() noexcept;

	private:
		WindowError m_LastError;
		Local m_ErrorMessage; 
	};
}

#endif // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
