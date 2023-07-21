/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_$ClassUppercaseSeparator$_H
#define DATABASE_ENTITY_$ClassUppercaseSeparator$_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace $Namespace$
{
    class $Class$ final : public Database::DatabaseEntity
    {
    public:
        using ClassType = $Class$;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        explicit $Class$(const BasisDatabaseManager& entity);
        Chapter(WrappersStrategy wrappersStrategy,
                boost::call_traits<Database::Traits::$KeyType$>::param_type $KeyName$);

        CLASS_INVARIANT_FINAL_DECLARE;

$GetDeclaration$

$SetDeclaration$

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy,
                                                        boost::call_traits<Database::Traits::$KeyType$>::param_type $KeyName$);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "$DatabaseName$" };

$Describe$

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(boost::call_traits<Database::Traits::$KeyType$>::param_type $KeyName$);

    private:
$Field$
    };
}

#endif  // DATABASE_ENTITY_$ClassUppercaseSeparator$_H