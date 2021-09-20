// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/SimplePropertyGetExternalDetail.h"
#include "CoreTools/Properties/SimplePropertySetExternalDetail.h"

#include <string>

namespace CoreTools
{
	class SimplePropertyExternal
	{
	public:
		using ClassType = SimplePropertyExternal;
		using GetType = SimplePropertyGetExternal<std::string, const std::string&>;
		using SetType = SimplePropertySetExternal<std::string, std::string&>;

		CLASS_INVARIANT_DECLARE;

		SimplePropertyExternal() noexcept;

	private:
		std::string m_Value;

	public:
		GetType m_GetType{ m_Value };
		SetType m_SetType{ m_Value };
	};
}

#endif // CORE_TOOLS_PROPERTIES_SUITE_SIMPLE_PROPERTY_EXTERNAL_H


