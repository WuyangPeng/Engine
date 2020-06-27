// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:02)

#ifndef DATABASE_DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H
#define DATABASE_DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H

#include "Database/DatabaseDll.h"

#include "ConfigurationStrategy.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h" 

#include <string>
#include <map>

DATABASE_EXPORT_SHARED_PTR(AnalysisDatabaseConfigurationImpl);

namespace Database
{
	class DATABASE_DEFAULT_DECLARE AnalysisDatabaseConfiguration
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(AnalysisDatabaseConfiguration);
		using Container = std::map<System::String, ConfigurationStrategy>;
		using ContainerConstIter = Container::const_iterator;

	public:
		explicit AnalysisDatabaseConfiguration(const std::string& fileName);

		CLASS_INVARIANT_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy(const System::String& name) const;
		ContainerConstIter GetBegin() const;
		ContainerConstIter GetEnd() const;
		int GetSize() const;

	private:
		IMPL_TYPE_DECLARE(AnalysisDatabaseConfiguration);
	};
}

#endif // DATABASE_DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H
