// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 09:59)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_H
#define DATABASE_SQL_INTERFACE_SCHEMA_H

#include "Database/DatabaseDll.h" 

#include "CoreTools/Helper/ExportMacro.h"  
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"

DATABASE_EXPORT_SHARED_PTR(SchemaImpl);
EXPORT_NONCOPYABLE_CLASS(DATABASE);

namespace Database
{
	class Session;

	class DATABASE_DEFAULT_DECLARE Schema : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Schema);

	public:
		explicit Schema(const Session& session);
		Schema(const Session& session,int dbIndex);

		CLASS_INVARIANT_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy() const;

	private:
		IMPL_TYPE_DECLARE(Schema);

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	public:
		using SchemaWeakPtr = std::weak_ptr<ImplType>;

	public:
		SchemaWeakPtr GetImplType() const;
		Schema(const ConfigurationStrategy& configurationStrategy,const MysqlxSchema& mysqlxSchema);
#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	};
}

#endif // DATABASE_SQL_INTERFACE_SCHEMA_H
