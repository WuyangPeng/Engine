// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H 

#include "CoreTools/CoreToolsDll.h"

#include "SimpleDecrementer.h"
#include "SimpleIncrementer.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	template< typename T, typename Aquire = SimpleIncrementer<T>, typename Release = SimpleDecrementer<T>>
	class IncrementScope : private boost::noncopyable
	{
	public:
		using ValueType = T;
		using AquireType = Aquire;
		using ReleaseType = Release;
		using ClassType = IncrementScope<T, Aquire, Release>;
		using Reference = ValueType&;

	public:
		explicit IncrementScope(Reference value);
		~IncrementScope();

		CLASS_INVARIANT_DECLARE;

	private:
		Reference m_Vaule;
	};
}

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H

