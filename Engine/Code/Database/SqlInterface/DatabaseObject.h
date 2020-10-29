//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:01)

#ifndef DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H
#define DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"

DATABASE_EXPORT_SHARED_PTR(DatabaseObjectImpl);
EXPORT_NONCOPYABLE_CLASS(DATABASE);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseObject final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(DatabaseObject);

    public:
        explicit DatabaseObject(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

    private:
        IMPL_TYPE_DECLARE(DatabaseObject);

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    public:
        using DatabaseObjectWeakPtr = std::weak_ptr<ImplType>;

    public:
        [[nodiscard]] DatabaseObjectWeakPtr GetImplType() const noexcept;
#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    };
}

#endif  // DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H
