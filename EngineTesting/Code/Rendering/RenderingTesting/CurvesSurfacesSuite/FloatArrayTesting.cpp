///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:00)

#include "FloatArrayTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/CurvesSurfaces/FloatArray.h"

Rendering::FloatArrayTesting::FloatArrayTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, FloatArrayTesting)

void Rendering::FloatArrayTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::FloatArrayTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::FloatArrayTesting::InitTest()
{
    std::vector<float> value;
    constexpr int size = 100;

    for (int i = 0; i < size; ++i)
    {
        value.push_back(static_cast<float>(i));
    }

    const FloatArray firstFloatArray(value);

    ASSERT_EQUAL(firstFloatArray.GetNumElements(), size);

    const float* data = firstFloatArray.GetData();

    if (data == nullptr)
        return;

    for (int i = 0; i < size; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_APPROXIMATE(data[i], static_cast<float>(i), 1e-8f);

#include SYSTEM_WARNING_POP

        ASSERT_APPROXIMATE(firstFloatArray[i], static_cast<float>(i), 1e-8f);
    }

    FloatArray secondFloatArray(value);

    for (int i = 0; i < size; ++i)
    {
        secondFloatArray[i] = static_cast<float>(i + size);
    }

    for (int i = 0; i < size; ++i)
    {
        ASSERT_APPROXIMATE(secondFloatArray[i], static_cast<float>(i + size), 1e-8f);
    }
}

void Rendering::FloatArrayTesting::CopyTest()
{
    std::vector<float> value;
    constexpr int size = 100;

    for (int i = 0; i < size; ++i)
    {
        value.push_back(static_cast<float>(i));
    }

    FloatArray firstFloatArray(value);
    FloatArray secondFloatArray(firstFloatArray);

    for (int i = 0; i < size; ++i)
    {
        secondFloatArray[i] = static_cast<float>(i + size);
    }

    for (int i = 0; i < size; ++i)
    {
        ASSERT_APPROXIMATE(firstFloatArray[i], static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(secondFloatArray[i], static_cast<float>(i + size), 1e-8f);
    }

    FloatArray thirdFloatArray(value);

    secondFloatArray = thirdFloatArray;

    for (int i = 0; i < size; ++i)
    {
        secondFloatArray[i] = static_cast<float>(i + size);
    }

    for (int i = 0; i < size; ++i)
    {
        ASSERT_APPROXIMATE(firstFloatArray[i], static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(secondFloatArray[i], static_cast<float>(i + size), 1e-8f);
        ASSERT_APPROXIMATE(thirdFloatArray[i], static_cast<float>(i), 1e-8f);
    }
}

void Rendering::FloatArrayTesting::StreamTest()
{
    std::vector<float> value;
    constexpr int size = 100;

    for (int i = 0; i < size; ++i)
    {
        value.push_back(static_cast<float>(i));
    }
}