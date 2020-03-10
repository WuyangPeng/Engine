// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:57)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/ResultRow.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE ResultImpl
	{
	public:
		using ClassType = ResultImpl;
		using ImplTypePtr = std::shared_ptr<ClassType>;
		using ResultRowPtr = std::unique_ptr<ResultRow>;
		using ResultRowContainer = std::vector<ResultRowPtr>;

	public:
		explicit ResultImpl(const ConfigurationStrategy& configurationStrategy);
		virtual ~ResultImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;	

		virtual ResultRowPtr FetchOne();
		virtual ResultRowContainer FetchAll(); 
		ConfigurationStrategy GetConfigurationStrategy() const; 

	private:
		ConfigurationStrategy m_ConfigurationStrategy;
	};
}

#endif // DATABASE_SQL_INTERFACE_DOC_RESULT_IMPL_H
