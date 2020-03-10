// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 11:23)

#ifndef NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_IMPL_H

#include "Network/NetworkDll.h" 

#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "Network/Configuration/ConfigurationStrategy.h"

#include <string>
#include <map>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE AnalysisNetworkConfigurationImpl
	{
	public:
		using ClassType = AnalysisNetworkConfigurationImpl;
		using String = System::String;
		using Container = std::map<String, ConfigurationStrategy>;
		using ContainerConstIter = Container::const_iterator;

	public:
		explicit AnalysisNetworkConfigurationImpl(const std::string& fileName);

		CLASS_INVARIANT_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy(const String& name) const;
		ContainerConstIter GetBegin() const;
		ContainerConstIter GetEnd() const;
		int GetSize() const;

	private:
		using BasicTree = boost::property_tree::basic_ptree<String, String>;

	private:
		void Analysis();
		void AnalysisJson();
		void AnalysisMain();
		void InsertStrategy(const String& name, const BasicTree& basicTree);
		static WrappersStrategy GetWrappersStrategy(const String& wrappers);
		static ConnectStrategy GetConnectStrategy(const String& connect);
		static ConfigurationSubStrategy GetConfigurationSubStrategy(const BasicTree& basicTree);
		static ConfigurationParameter GetConfigurationParameter(const BasicTree& basicTree);

	private:
		Container m_Container;
		std::string m_FileName;
		BasicTree m_MainTree;
	};
}

#endif // NETWORK_NETWORK_CONFIGURATION_ANALYSIS_NETWORK_CONFIGURATION_IMPL_H


