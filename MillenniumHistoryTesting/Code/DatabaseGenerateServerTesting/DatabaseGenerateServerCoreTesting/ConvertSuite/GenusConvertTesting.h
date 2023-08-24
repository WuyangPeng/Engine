///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 21:04)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_GENUS_CONVERT_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_GENUS_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/GenusContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateServerCoreTesting
{
    class GenusConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = GenusConvertTesting;
        using ParentType = ConvertTesting;

        using GenusContainer = AncientBooks::GenusContainer;

    public:
        GenusConvertTesting(const OStreamShared& stream, const GenusContainer& genusContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Genus = AncientBooks::GenusBase;
        using GenusEntity = DatabaseEntity::GenusEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Genus& genus, const GenusEntity& genusEntity);

    private:
        GenusContainer genusContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_GENUS_CONVERT_TESTING_H