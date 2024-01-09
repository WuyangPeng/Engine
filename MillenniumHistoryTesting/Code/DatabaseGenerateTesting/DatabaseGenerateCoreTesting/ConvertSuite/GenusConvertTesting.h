/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 22:16)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GENUS_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GENUS_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GenusContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class GenusConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = GenusConvertTesting;
        using ParentType = ConvertTesting;

        using GenusContainer = AncientBooks::GenusContainer;

    public:
        GenusConvertTesting(const OStreamShared& stream, GenusContainer genusContainer);

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

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GENUS_CONVERT_TESTING_H