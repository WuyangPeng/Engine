// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:55)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CommandArgumentImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CommandArgument
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(CommandArgument);

	public:
		CommandArgument(int index, const std::string& arguments, const std::string& value);
		CommandArgument(int index, const std::string& arguments);

		CLASS_INVARIANT_DECLARE;

		int GetIndex() const noexcept;
		const std::string GetName() const;

		int GetInteger() const;
		float GetFloat() const;
		double GetDouble() const;
		const std::string GetString() const;

		bool IsInteger() const noexcept;
		bool IsFloat() const noexcept;
		bool IsDouble() const noexcept;
		bool IsString() const noexcept;
		bool IsNoValue() const noexcept;

		bool IsUsed() const noexcept;
		void SetUsed();

		void AddEndArgumentValue(const std::string& value);

	private:
		IMPL_TYPE_DECLARE(CommandArgument);
	};
}

#endif // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H
