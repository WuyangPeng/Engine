// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 18:05)

#ifndef CORE_TOOLS_CLASS_INVARIANT_FUNCTION_DESCRIBED_H
#define CORE_TOOLS_CLASS_INVARIANT_FUNCTION_DESCRIBED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE FunctionDescribed
	{
	public:
		using ClassType = FunctionDescribed;

	public:
		FunctionDescribed(const char* currentFunction, const char* fileName, int line) noexcept;

		const char* GetCurrentFunction() const noexcept;
		const char* GetFileName() const noexcept;
		int GetLine() const noexcept;

	private:
		const char* m_CurrentFunction;
		const char* m_FileName;
		int m_Line;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_FUNCTION_DESCRIBED_H
