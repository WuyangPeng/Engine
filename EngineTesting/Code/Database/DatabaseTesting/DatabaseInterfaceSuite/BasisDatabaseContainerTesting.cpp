///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/26 15:37)

#include "BasisDatabaseContainerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"

Database::BasisDatabaseContainerTesting::BasisDatabaseContainerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, BasisDatabaseContainerTesting)

void Database::BasisDatabaseContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::BasisDatabaseContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetAnyValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ObjectContainerTest);
}

void Database::BasisDatabaseContainerTesting::ContainerSizeTest()
{
    auto basisDatabaseContainer = BasisDatabaseContainer::Create();

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 0);

    ASSERT_EQUAL(basisDatabaseContainer.GetContainer().size(), 0u);

    basisDatabaseContainer.Modify(BasisDatabase{ "basis0" });

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 1);

    ASSERT_EQUAL(basisDatabaseContainer.GetContainer().size(), 1u);

    basisDatabaseContainer.Modify(BasisDatabase{ "basis0" });

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 1);

    ASSERT_EQUAL(basisDatabaseContainer.GetContainer().size(), 1u);

    basisDatabaseContainer.Modify(BasisDatabase{ "basis1" });

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 2);

    ASSERT_EQUAL(basisDatabaseContainer.GetContainer().size(), 2u);

    basisDatabaseContainer.Modify(BasisDatabase{ "basis2" });

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 3);

    ASSERT_EQUAL(basisDatabaseContainer.GetContainer().size(), 3u);

    basisDatabaseContainer.Clear();

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 0);

    ASSERT_EQUAL(basisDatabaseContainer.GetContainer().size(), 0u);
}

void Database::BasisDatabaseContainerTesting::GetAnyValueTest()
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabase{ "basis0", 7 } };

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 1);

    ASSERT_EQUAL(std::any_cast<int32_t>(basisDatabaseContainer.GetAnyValue("basis0")), 7);

    basisDatabaseContainer.Modify(BasisDatabase{ "basis1", 7 });

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 2);

    for (const auto& value : basisDatabaseContainer)
    {
        ASSERT_ENUM_EQUAL(value.GetDataType(), DataType::Int32);
        ASSERT_EQUAL(std::any_cast<int32_t>(value.GetAnyValue()), 7);
    }

    ASSERT_FALSE(basisDatabaseContainer.GetAnyValue("basis2").has_value());
}

void Database::BasisDatabaseContainerTesting::ObjectContainerTest()
{
    BasisDatabaseContainer basisDatabaseContainer{ BasisDatabaseContainer::ObjectContainer{ BasisDatabase{ "basis0", 7 },
                                                                                            BasisDatabase{ "basis1", 8 },
                                                                                            BasisDatabase{ "basis2", 9 } } };

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 3);

    basisDatabaseContainer.Set(BasisDatabaseContainer::ObjectContainer{ BasisDatabase{ "basis0", 7 },
                                                                        BasisDatabase{ "basis1", 8 } });

    ASSERT_EQUAL(basisDatabaseContainer.GetSize(), 2);
}
