/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 16:52)

#include "PropertiesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::PropertiesTesting::PropertiesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PropertiesTesting)

void CoreTools::PropertiesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::PropertiesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PropertiesTest);
}

void CoreTools::PropertiesTesting::PropertiesTest()
{
    const auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    document->SetProperty(SimpleCSV::Property::Title, "TCRE");

    ASSERT_EQUAL(document->GetProperty(SimpleCSV::Property::Title), "TCRE");

    document->DeleteProperty(SimpleCSV::Property::Title);

    ASSERT_EQUAL(document->GetProperty(SimpleCSV::Property::Title), "");
}
