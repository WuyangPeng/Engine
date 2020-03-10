// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:42)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_H  

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	template <typename T>
	class ValueScope : boost::noncopyable
	{
	public:
		using ValueType = T;
		using ClassType = ValueScope<T>;
		using Reference = ValueType&;

	public:
		template <typename V>
		ValueScope(Reference value, V const& set);

		template <typename V1, typename V2>
		ValueScope(Reference value, V1 const& set, V2 const& revert);

		~ValueScope();

		CLASS_INVARIANT_DECLARE;

	private:
		Reference m_Value;
		ValueType m_Revert;
	};
}

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_H

