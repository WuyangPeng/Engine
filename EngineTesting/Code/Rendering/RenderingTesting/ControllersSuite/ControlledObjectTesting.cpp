///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:04)

#include "ControlledObjectTesting.h"
#include "Detail/ControlledObjectTest.h"
#include "Detail/ControllerTest.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

Rendering::ControlledObjectTesting::ControlledObjectTesting(const OStreamShared& stream)
    : ParentType{ stream }, controlledObjectTestName{ " controlledObject" }, controllerTestName{ "controller" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControlledObjectTesting)

void Rendering::ControlledObjectTesting::DoRunUnitTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::ControlledObjectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SearchSelfTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SearchChildTest);
    ASSERT_THROW_EXCEPTION_0(ControllerSetExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ControllersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void Rendering::ControlledObjectTesting::NameTest()
{
    const auto controlledObjectTest = ControlledObjectTest::Create(controlledObjectTestName);

    ASSERT_EQUAL(controlledObjectTest->GetName(), controlledObjectTestName);

    controlledObjectTest->SetName(controllerTestName);
    ASSERT_EQUAL(controlledObjectTest->GetName(), controllerTestName);
}

void Rendering::ControlledObjectTesting::SearchSelfTest()
{
    const auto controlledObjectTest = ControlledObjectTest::Create(controlledObjectTestName);

    ASSERT_EQUAL(controlledObjectTest->GetConstObjectByName(controlledObjectTestName), controlledObjectTest);
    ASSERT_EQUAL(controlledObjectTest->GetObjectByName(controlledObjectTestName), controlledObjectTest);

    const auto objects0 = controlledObjectTest->GetAllConstObjectsByName(controlledObjectTestName);
    const auto objects1 = controlledObjectTest->GetAllObjectsByName(controlledObjectTestName);
    ASSERT_EQUAL_FAILURE_THROW(1u, objects0.size(), "对象未找到。");
    ASSERT_EQUAL_FAILURE_THROW(1u, objects1.size(), "对象未找到。");
    ASSERT_EQUAL(objects0.at(0), objects1.at(0));

    const auto nullName = "null";
    ASSERT_EQUAL(controlledObjectTest->GetConstObjectByName(nullName), ControlledObjectTest::GetNullObject());
    ASSERT_EQUAL(controlledObjectTest->GetObjectByName(nullName), ControlledObjectTest::GetNullObject());
    ASSERT_TRUE(controlledObjectTest->GetAllConstObjectsByName(nullName).empty());
    ASSERT_TRUE(controlledObjectTest->GetAllObjectsByName(nullName).empty());
}

void Rendering::ControlledObjectTesting::SearchChildTest()
{
    const auto controlledObjectTest = ControlledObjectTest::Create(controlledObjectTestName);

    const auto controllerTest0 = ControllerTest::Create(controllerTestName + "0");
    const auto controllerTest1 = ControllerTest::Create(controllerTestName + "1");
    const auto controllerTest2 = ControllerTest::Create(controllerTestName + "1");

    controlledObjectTest->AttachController(controllerTest0);
    controlledObjectTest->AttachController(controllerTest1);
    controlledObjectTest->AttachController(controllerTest2);

    ASSERT_EQUAL(controlledObjectTest->GetConstObjectByName(controllerTestName + "0"), controllerTest0);
    ASSERT_EQUAL(controlledObjectTest->GetObjectByName(controllerTestName + "0"), controllerTest0);

    const auto objects0 = controlledObjectTest->GetAllConstObjectsByName(controllerTestName + "0");
    const auto objects1 = controlledObjectTest->GetAllObjectsByName(controllerTestName + "0");
    ASSERT_EQUAL_FAILURE_THROW(1u, objects0.size(), "对象未找到。");
    ASSERT_EQUAL_FAILURE_THROW(1u, objects1.size(), "对象未找到。");
    ASSERT_EQUAL(objects0.at(0), objects1.at(0));

    const auto objects2 = controlledObjectTest->GetAllConstObjectsByName(controllerTestName + "1");
    const auto objects3 = controlledObjectTest->GetAllObjectsByName(controllerTestName + "1");
    ASSERT_EQUAL_FAILURE_THROW(2u, objects2.size(), "对象未找到。");
    ASSERT_EQUAL_FAILURE_THROW(2u, objects3.size(), "对象未找到。");
    ASSERT_EQUAL(objects2.at(0), objects3.at(0));
    ASSERT_EQUAL(objects2.at(1), objects3.at(1));
}

void Rendering::ControlledObjectTesting::ControllerSetExceptionTest()
{
    const auto controlledObjectTest = ControlledObjectTest::Create(controlledObjectTestName);
    const auto controllerTest = ControllerTest::Create(controllerTestName);

    controlledObjectTest->SetController(controllerTest);
}

void Rendering::ControlledObjectTesting::UpdateTest()
{
    constexpr auto applicationTime = 1000.0;

    const auto controlledObjectTest = ControlledObjectTest::Create(controlledObjectTestName);
    ASSERT_FALSE(controlledObjectTest->Update(applicationTime));

    const auto controllerTest = ControllerTest::Create(controllerTestName);

    controlledObjectTest->AttachController(controllerTest);

    ASSERT_TRUE(controlledObjectTest->Update(applicationTime));
}

void Rendering::ControlledObjectTesting::ControllersTest()
{
    const auto controlledObjectTest = ControlledObjectTest::Create(controlledObjectTestName);

    const auto controllerTest0 = ControllerTest::Create(controllerTestName + "0");
    const auto controllerTest1 = ControllerTest::Create(controllerTestName + "1");
    const auto controllerTest2 = ControllerTest::Create(controllerTestName + "2");

    ASSERT_EQUAL(controlledObjectTest->GetNumControllers(), 0);

    controlledObjectTest->AttachController(controllerTest0);
    ASSERT_EQUAL(controlledObjectTest->GetNumControllers(), 1);

    controlledObjectTest->AttachController(controllerTest1);
    ASSERT_EQUAL(controlledObjectTest->GetNumControllers(), 2);

    controlledObjectTest->AttachController(controllerTest2);
    ASSERT_EQUAL(controlledObjectTest->GetNumControllers(), 3);

    ASSERT_EQUAL(controlledObjectTest->GetConstController(0), controllerTest0);
    ASSERT_EQUAL(controlledObjectTest->GetConstController(1), controllerTest1);
    ASSERT_EQUAL(controlledObjectTest->GetConstController(2), controllerTest2);

    ASSERT_EQUAL(controlledObjectTest->GetController(0), controllerTest0);
    ASSERT_EQUAL(controlledObjectTest->GetController(1), controllerTest1);
    ASSERT_EQUAL(controlledObjectTest->GetController(2), controllerTest2);

    controlledObjectTest->DetachController(controllerTest0);
    ASSERT_EQUAL(controlledObjectTest->GetNumControllers(), 2);

    ASSERT_EQUAL(controlledObjectTest->GetConstController(0), controllerTest1);
    ASSERT_EQUAL(controlledObjectTest->GetConstController(1), controllerTest2);

    ASSERT_EQUAL(controlledObjectTest->GetController(0), controllerTest1);
    ASSERT_EQUAL(controlledObjectTest->GetController(1), controllerTest2);

    controlledObjectTest->DetachAllControllers();
    ASSERT_EQUAL(controlledObjectTest->GetNumControllers(), 0);
}

void Rendering::ControlledObjectTesting::StreamTest()
{
    const auto controlledObjectTest = ControlledObjectTest::Create(controlledObjectTestName);

    const auto controllerTest0 = ControllerTest::Create(controllerTestName + "0");
    controllerTest0->SetRepeat(ControllerRepeatType::Wrap);
    controllerTest0->SetTime(1.0, 5.0);
    controllerTest0->SetPhase(2.0);
    controllerTest0->SetFrequency(4.0);
    controllerTest0->SetActive(false);

    const auto controllerTest1 = ControllerTest::Create(controllerTestName + "1");
    controllerTest1->SetRepeat(ControllerRepeatType::Clamp);
    controllerTest1->SetTime(3.0, 7.0);
    controllerTest1->SetPhase(8.0);
    controllerTest1->SetFrequency(6.0);
    controllerTest1->SetActive(true);

    const auto controllerTest2 = ControllerTest::Create(controllerTestName + "2");
    controllerTest2->SetRepeat(ControllerRepeatType::ClampCycle);
    controllerTest2->SetTime(13.0, 17.0);
    controllerTest2->SetPhase(18.0);
    controllerTest2->SetFrequency(16.0);
    controllerTest2->SetActive(false);

    controlledObjectTest->AttachController(controllerTest0);
    controlledObjectTest->AttachController(controllerTest1);
    controlledObjectTest->AttachController(controllerTest2);

    auto outTopLevel = CoreTools::OutTopLevel::Create();
    outTopLevel.Insert(controlledObjectTest);

    const CoreTools::BufferOutStream bufferOutStream{ outTopLevel };
    const auto buffer = bufferOutStream.GetBufferOutStreamInformation();

    const CoreTools::BufferInStream bufferInStream{ buffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "流读取失败。");

    const auto begin = boost::polymorphic_pointer_cast<ControlledObjectTest>(*inTopLevel.begin());
    ASSERT_EQUAL_FAILURE_THROW(begin->GetNumControllers(), 3, "流读取失败。");

    const auto controllerTest3 = boost::polymorphic_pointer_cast<ControllerTest>(begin->GetController(0));
    const auto controllerTest4 = boost::polymorphic_pointer_cast<ControllerTest>(begin->GetController(1));
    const auto controllerTest5 = boost::polymorphic_pointer_cast<ControllerTest>(begin->GetController(2));

    ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *controllerTest0, *controllerTest3);
    ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *controllerTest1, *controllerTest4);
    ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, *controllerTest2, *controllerTest5);
}

void Rendering::ControlledObjectTesting::EqualTest(const ControllerTest& lhs, const ControllerTest& rhs)
{
    ASSERT_ENUM_EQUAL(lhs.GetRepeat(), rhs.GetRepeat());
    ASSERT_APPROXIMATE(lhs.GetMinTime(), rhs.GetMinTime(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(lhs.GetMaxTime(), rhs.GetMaxTime(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(lhs.GetPhase(), rhs.GetPhase(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(lhs.GetFrequency(), rhs.GetFrequency(), Mathematics::MathD::GetZeroTolerance());
    ASSERT_EQUAL(lhs.GetName(), rhs.GetName());
    ASSERT_EQUAL(lhs.IsActive(), rhs.IsActive());
}
