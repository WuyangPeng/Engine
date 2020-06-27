// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:24)

#ifndef DATABASE_SQL_INTERFACE_COLLECTION_FACTORY_H
#define DATABASE_SQL_INTERFACE_COLLECTION_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
	class DATABASE_HIDDEN_DECLARE CollectionFactory
	{
	public:
		using ClassType = CollectionFactory;
		using ImplType = CollectionImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		CollectionFactory();

		CLASS_INVARIANT_DECLARE;

		static ImplTypePtr Create(const Schema& schema, const std::string& collectionName);
	};
}

#endif // DATABASE_SQL_INTERFACE_COLLECTION_FACTORY_H
