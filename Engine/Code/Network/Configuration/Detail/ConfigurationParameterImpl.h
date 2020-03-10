// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:18)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h" 

#include <map>
#include <set>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ConfigurationParameterImpl
	{
	public:
		using ClassType = ConfigurationParameterImpl;
		using String = System::String;
		using Parameter = std::set<String>;

	public:
		ConfigurationParameterImpl();

		CLASS_INVARIANT_DECLARE;

		void AddParameter(const String& key, const String& parameter);
		bool IsParameterExist(const String& key, const String& parameter) const;
		const Parameter GetParameter(const String& key) const;

	private:
		using Container = std::map<String, Parameter>;

	private:
		Container m_Container;
	};
}

#endif // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
