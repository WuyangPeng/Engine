// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:25)

#ifndef DATABASE_SQL_INTERFACE_NULL_SESSION_H
#define DATABASE_SQL_INTERFACE_NULL_SESSION_H

#include "Database/DatabaseDll.h"

#include "SessionImpl.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE NullSession : public SessionImpl
	{
	public:
		using ClassType = NullSession;
		using ParentType = SessionImpl;

	public:
		explicit NullSession(const ConfigurationStrategy& configurationStrategy);
		virtual ~NullSession();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	};
}

#endif // DATABASE_SQL_INTERFACE_NULL_SESSION_H
