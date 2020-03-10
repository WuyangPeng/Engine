// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:45)

#ifndef CORE_TOOLS_EXCEPTION_ERROR_IMPL_H
#define CORE_TOOLS_EXCEPTION_ERROR_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/ClassInvariant/FunctionDescribed.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ErrorImpl
	{
	public:
		using ClassType = ErrorImpl;
		using String = System::String;

	public:
		ErrorImpl(const FunctionDescribed& functionDescribed, const String& message);
		virtual ~ErrorImpl() = 0;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		const char* GetCurrentFunction() const noexcept;
		const char* GetFileName() const noexcept;
		int GetLine() const noexcept;
		const FunctionDescribed& GetFunctionDescribed() const noexcept;

		virtual const String GetError() const;

	private:
		FunctionDescribed m_FunctionDescribed;
		String m_ErrorMessage;
	};
}

#endif // CORE_TOOLS_EXCEPTION_ERROR_IMPL_H