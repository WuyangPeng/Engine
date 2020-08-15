// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:28)

#ifndef DATABASE_SQL_INTERFACE_COLLECTION_H
#define DATABASE_SQL_INTERFACE_COLLECTION_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"  
#include "Database/SqlInterface/SqlInterfaceFwd.h"

#include <map>
#include <string>

DATABASE_EXPORT_SHARED_PTR(CollectionImpl);
EXPORT_NONCOPYABLE_CLASS(DATABASE);

namespace Database
{
	class DATABASE_DEFAULT_DECLARE Collection : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Collection);
		using DocResultPtr = std::shared_ptr<Result>;
		using BindStatementType = std::map<std::string, std::string>;

	public:
		explicit Collection(const Schema& schema, const std::string& collectionName);

		CLASS_INVARIANT_DECLARE;

		  DocResultPtr ExecuteDoc(const std::string& findStatement, const BindStatementType& bindStatement, int limitStatement);

	private:
		IMPL_TYPE_DECLARE(Collection);
	};
}

#endif // DATABASE_SQL_INTERFACE_COLLECTION_H
