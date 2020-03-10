// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:15)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_IMPL_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <map>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE StringReplacingImpl
	{
	public:
		using ClassType = StringReplacingImpl;

	public:
		explicit StringReplacingImpl(const std::string& configurationFileName);

		CLASS_INVARIANT_DECLARE;

		const System::String GetReplacing(const System::String& original) const;

	private:
		using Replacing = std::map<System::String, System::String>;

	private:
		void InitReplacing(const std::string& configurationFileName);

	private:
		Replacing m_Replacing;
	};
}

#endif // CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_IMPL_H
