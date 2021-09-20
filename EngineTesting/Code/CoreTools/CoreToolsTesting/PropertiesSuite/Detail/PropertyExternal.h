// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H

#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/PropertyGetExternalDetail.h"
#include "CoreTools/Properties/PropertySetExternalDetail.h"
#include "CoreTools/Properties/PropertyGetSetExternalDetail.h"

#include <string>

namespace CoreTools
{
	class PropertyExternal
	{
	public:
		using ClassType = PropertyExternal;

		CLASS_INVARIANT_DECLARE;

		PropertyExternal() noexcept;

	private:
		std::string m_Value;

		const std::string& GetValue() const noexcept;
		void SetValue(const std::string& value);

	public:
		using GetType = PropertyGetExternal<ClassType, const std::string&, &GetValue>;
		using SetType = PropertySetExternal<ClassType, const std::string&, &SetValue>;
		using GetSetType = PropertyGetSetExternal<ClassType, const std::string&, &GetValue, const std::string&, &SetValue>;

		GetType m_GetType;
		SetType m_SetType;
		GetSetType m_GetSetType;
	};
}

#endif // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_H


