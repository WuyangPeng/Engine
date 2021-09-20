// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/StaticPropertyGetSetDetail.h"
#include "CoreTools/Properties/StaticPropertyGetExternalDetail.h"
#include "CoreTools/Properties/StaticPropertySetExternalDetail.h"
#include "CoreTools/Properties/StaticPropertyGetSetExternalDetail.h"

#include <string>

namespace CoreTools
{
	class StaticPropertyExternal
	{
	public:
		using ClassType = StaticPropertyExternal;

		CLASS_INVARIANT_DECLARE;

		StaticPropertyExternal() noexcept;

	private:
		static std::string sm_Value;

		static const std::string& GetValue() noexcept;
		static void SetValue(const std::string& value);

	public:
		using GetExternalType = StaticPropertyGetExternal<const std::string&, &GetValue>;
		using SetExternalType = StaticPropertySetExternal<const std::string&, &SetValue>;
		using GetSetExternalType = StaticPropertyGetSetExternal<const std::string&, const std::string&, &GetValue, &SetValue>;
		using GetSetType = StaticPropertyGetSet<std::string, const std::string&, const std::string&, ClassType, &GetValue, &SetValue>;

		GetExternalType sm_GetExternalType;
		SetExternalType sm_SetExternalType;
		GetSetExternalType sm_GetSetExternalType;
		GetSetType m_GetSetType;
	};
}

#endif // CORE_TOOLS_PROPERTIES_SUITE_STATIC_PROPERTY_EXTERNAL_H


