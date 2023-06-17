///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:58)

#include "SpecializedIOTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

#include <random>

Rendering::SpecializedIOTesting::SpecializedIOTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SpecializedIOTesting)

void Rendering::SpecializedIOTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::SpecializedIOTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoundTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntColourTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatColourTest);
}

void Rendering::SpecializedIOTesting::StreamSizeTest() noexcept
{
}

void Rendering::SpecializedIOTesting::TransformTest() noexcept
{
}

void Rendering::SpecializedIOTesting::BoundTest() noexcept
{
}

void Rendering::SpecializedIOTesting::IntColourTest() noexcept
{
}

void Rendering::SpecializedIOTesting::FloatColourTest() noexcept
{
}
