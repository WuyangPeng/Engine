/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 18:11)

#include "ControllerTesting.h"
#include "Detail/ControllerTest.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/Controller.h"

Rendering::ControllerTesting::ControllerTesting(const OStreamShared& stream)
    : ParentType{ stream }, controllerTestName{ "controller" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControllerTesting)

void Rendering::ControllerTesting::DoRunUnitTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::ControllerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SearchTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ControllerSetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void Rendering::ControllerTesting::NameTest()
{
    const auto changeControllerTestName = "changeController";

    const auto controllerTest = ControllerTest::Create(controllerTestName);

    ASSERT_EQUAL(controllerTest->GetName(), controllerTestName);

    controllerTest->SetName(changeControllerTestName);
    ASSERT_EQUAL(controllerTest->GetName(), changeControllerTestName);
}

void Rendering::ControllerTesting::SearchTest()
{
    const auto controllerTest = ControllerTest::Create(controllerTestName);

    ASSERT_EQUAL(controllerTest->GetConstObjectByName(controllerTestName), controllerTest);
    ASSERT_EQUAL(controllerTest->GetObjectByName(controllerTestName), controllerTest);

    const auto objects0 = controllerTest->GetAllConstObjectsByName(controllerTestName);
    const auto objects1 = controllerTest->GetAllObjectsByName(controllerTestName);
    ASSERT_EQUAL_FAILURE_THROW(1u, objects0.size(), "对象未找到。");
    ASSERT_EQUAL_FAILURE_THROW(1u, objects1.size(), "对象未找到。");
    ASSERT_EQUAL(objects0.at(0), objects1.at(0));

    const auto nullName = "null";
    ASSERT_EQUAL(controllerTest->GetConstObjectByName(nullName), ControllerTest::GetNullObject());
    ASSERT_EQUAL(controllerTest->GetObjectByName(nullName), ControllerTest::GetNullObject());
    ASSERT_TRUE(controllerTest->GetAllConstObjectsByName(nullName).empty());
    ASSERT_TRUE(controllerTest->GetAllObjectsByName(nullName).empty());
}

void Rendering::ControllerTesting::ControllerSetTest()
{
    const auto controllerTest0 = ControllerTest::Create(controllerTestName);
    const auto controllerTest1 = ControllerTest::Create(controllerTestName);

    controllerTest0->SetController(controllerTest1);
    ASSERT_EQUAL(controllerTest0->GetController(), controllerTest1);

    const auto controllerTest2 = std::static_pointer_cast<const ControllerTest>(controllerTest0);
    ASSERT_EQUAL(controllerTest2->GetController(), controllerTest1);
}

void Rendering::ControllerTesting::UpdateTest()
{
    const auto controllerTest = ControllerTest::Create(controllerTestName);

    constexpr auto applicationTime = 1000.0;

    ASSERT_TRUE(controllerTest->IsActive());
    ASSERT_TRUE(controllerTest->Update(applicationTime));
    ASSERT_APPROXIMATE(controllerTest->GetApplicationTime(), applicationTime, Mathematics::MathD::GetZeroTolerance());

    controllerTest->SetActive(false);

    ASSERT_FALSE(controllerTest->IsActive());
    ASSERT_FALSE(controllerTest->Update(applicationTime * 2));
    ASSERT_APPROXIMATE(controllerTest->GetApplicationTime(), applicationTime, Mathematics::MathD::GetZeroTolerance());
}

void Rendering::ControllerTesting::ValueTest()
{
    const auto controllerTest = ControllerTest::Create(controllerTestName);

    ASSERT_ENUM_EQUAL(controllerTest->GetRepeat(), ControllerRepeatType::Clamp);
    ASSERT_APPROXIMATE_DOUBLE_ZERO(controllerTest->GetMinTime());
    ASSERT_APPROXIMATE_DOUBLE_ZERO(controllerTest->GetMaxTime());
    ASSERT_APPROXIMATE_DOUBLE_ZERO(controllerTest->GetPhase());
    ASSERT_APPROXIMATE(controllerTest->GetFrequency(), 1.0, Mathematics::MathD::GetZeroTolerance());

    controllerTest->SetRepeat(ControllerRepeatType::Wrap);
    ASSERT_ENUM_EQUAL(controllerTest->GetRepeat(), ControllerRepeatType::Wrap);
    ASSERT_APPROXIMATE_DOUBLE_ZERO(controllerTest->GetMinTime());
    ASSERT_APPROXIMATE_DOUBLE_ZERO(controllerTest->GetMaxTime());
    ASSERT_APPROXIMATE_DOUBLE_ZERO(controllerTest->GetPhase());
    ASSERT_APPROXIMATE(controllerTest->GetFrequency(), 1.0, Mathematics::MathD::GetZeroTolerance());

    controllerTest->SetTime(1.0, 5.0);
    ASSERT_ENUM_EQUAL(controllerTest->GetRepeat(), ControllerRepeatType::Wrap);
    ASSERT_APPROXIMATE(controllerTest->GetMinTime(), 1.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetMaxTime(), 5.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE_DOUBLE_ZERO(controllerTest->GetPhase());
    ASSERT_APPROXIMATE(controllerTest->GetFrequency(), 1.0, Mathematics::MathD::GetZeroTolerance());

    controllerTest->SetPhase(2.0);
    ASSERT_ENUM_EQUAL(controllerTest->GetRepeat(), ControllerRepeatType::Wrap);
    ASSERT_APPROXIMATE(controllerTest->GetMinTime(), 1.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetMaxTime(), 5.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetPhase(), 2.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetFrequency(), 1.0, Mathematics::MathD::GetZeroTolerance());

    controllerTest->SetFrequency(4.0);
    ASSERT_ENUM_EQUAL(controllerTest->GetRepeat(), ControllerRepeatType::Wrap);
    ASSERT_APPROXIMATE(controllerTest->GetMinTime(), 1.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetMaxTime(), 5.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetPhase(), 2.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetFrequency(), 4.0, Mathematics::MathD::GetZeroTolerance());
}

void Rendering::ControllerTesting::StreamTest()
{
    const auto controllerTest = ControllerTest::Create(controllerTestName);

    controllerTest->SetRepeat(ControllerRepeatType::Wrap);
    controllerTest->SetTime(1.0, 5.0);
    controllerTest->SetPhase(2.0);
    controllerTest->SetFrequency(4.0);
    controllerTest->SetActive(false);

    auto outTopLevel = CoreTools::OutTopLevel::Create();
    outTopLevel.Insert(controllerTest);

    const CoreTools::BufferOutStream bufferOutStream{ outTopLevel };
    const auto buffer = bufferOutStream.GetBufferOutStreamInformation();

    const CoreTools::BufferInStream bufferInStream{ buffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "流读取失败。");

    const auto begin = boost::polymorphic_pointer_cast<ControllerTest>(*inTopLevel.begin());

    ASSERT_ENUM_EQUAL(controllerTest->GetRepeat(), begin->GetRepeat());
    ASSERT_APPROXIMATE(controllerTest->GetMinTime(), begin->GetMinTime(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetMaxTime(), begin->GetMaxTime(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetPhase(), begin->GetPhase(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(controllerTest->GetFrequency(), begin->GetFrequency(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_EQUAL(controllerTest->GetName(), begin->GetName());
    ASSERT_EQUAL(controllerTest->IsActive(), begin->IsActive());
}
