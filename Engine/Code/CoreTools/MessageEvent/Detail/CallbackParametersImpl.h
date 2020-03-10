// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:55)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/any.hpp> 
#include <boost/call_traits.hpp>
#include <vector>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CallbackParametersImpl
	{
	public:
		using ClassType = CallbackParametersImpl;

	public:
		explicit CallbackParametersImpl(int count);

		CLASS_INVARIANT_DECLARE;

		template<typename T>
		void SetValue(int index, typename boost::call_traits<T>::param_type value);

		template<typename T>
		const T GetValue(int index);

		int GetContainerSize() const;

	private:
		using Container = std::vector<boost::any>;

	private:
		Container m_Container;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_H
