// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:56)

#ifndef DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H
#define DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H

#include "Database/DatabaseDll.h"

#include "ResultRowImpl.h"
 
namespace Database
{
	class DATABASE_HIDDEN_DECLARE NullResultRow : public ResultRowImpl
	{
	public:
		using ClassType = NullResultRow;
		using ParentType = ResultRowImpl;

	public:
		explicit NullResultRow(const ConfigurationStrategy& configurationStrategy);
		virtual ~NullResultRow();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	};
}

#endif // DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H
