// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:39)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/DirectPropertyGetInternalDetail.h"
#include "CoreTools/Properties/DirectPropertySetInternalDetail.h" 

#include <string>

namespace CoreTools
{
	class DirectPropertyInternal
	{
	public:
		using ClassType = DirectPropertyInternal;

		CLASS_INVARIANT_DECLARE;

		DirectPropertyInternal();

		void SetValue(const std::string& value);
		std::string GetValue() const;

	public:
		using GetType = DirectPropertyGetInternal<std::string, const std::string&, ClassType>;
		using SetType = DirectPropertySetInternal<std::string, const std::string&, ClassType>;

		GetType m_GetType;
		SetType m_SetType;
	};
}

#endif // CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_H


