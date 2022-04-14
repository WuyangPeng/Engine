// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 17:02)

#include "FloatArrayTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/CurvesSurfaces/FloatArray.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26481)
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, FloatArrayTesting)

void Rendering::FloatArrayTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::FloatArrayTesting::InitTest()
{
    vector<float> value;
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
        ASSERT_APPROXIMATE(data[i], static_cast<float>(i), 1e-8f);
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
    vector<float> value;
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
    vector<float> value;
    constexpr int size = 100;

    for (int i = 0; i < size; ++i)
    {
        value.push_back(static_cast<float>(i));
    }

    // 	CoreTools::OutTopLevel outTopLevel;
    // 	CoreTools::ObjectInterfaceSharedPtr firstFloatArray(new FloatArray(value));
    //
    // 	firstFloatArray->SetUniqueID(5);
    //
    // 	outTopLevel.Insert(firstFloatArray);
    //
    // 	CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	FloatArraySharedPtr secondFloatArray = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<FloatArraySharedPtr>();
    //
    // 	ASSERT_EQUAL(secondFloatArray->GetNumElements(), size);
    //
    // 	 for (int i = 0; i < size;++i)
    // 	 {
    // 		 ASSERT_APPROXIMATE((*secondFloatArray)[i], static_cast<float>(i), 1e-8f);
    // 	 }
}