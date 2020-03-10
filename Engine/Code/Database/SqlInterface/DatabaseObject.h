// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:59)

#ifndef DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H
#define DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"  

DATABASE_EXPORT_SHARED_PTR(DatabaseObjectImpl);
EXPORT_NONCOPYABLE_CLASS(DATABASE);

namespace Database
{
	class ConfigurationStrategy;

	class DATABASE_DEFAULT_DECLARE DatabaseObject : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(DatabaseObject);

	public:
		explicit DatabaseObject(const ConfigurationStrategy& configurationStrategy);

		CLASS_INVARIANT_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy() const;

	private:
		IMPL_TYPE_DECLARE(DatabaseObject);

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	public:
		using DatabaseObjectWeakPtr = std::weak_ptr<ImplType>;

	public:
		DatabaseObjectWeakPtr GetImplType() const;
#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
	};
}

#endif // DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H
