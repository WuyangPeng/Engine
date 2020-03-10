// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 12:29)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h" 

#include <string>
#include <set>

NETWORK_EXPORT_SHARED_PTR(ConfigurationParameterImpl);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE ConfigurationParameter
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ConfigurationParameter);
		using String = System::String;
		using Parameter = std::set<System::String>;

	public:
		ConfigurationParameter();

		IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(ConfigurationParameter);

		void AddParameter(const String& key, const String& parameter);
		bool IsParameterExist(const String& key, const String& parameter) const;
		const Parameter GetParameter(const String& key) const;

	private:
		IMPL_TYPE_DECLARE(ConfigurationParameter);
	};
}

#endif // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_H
