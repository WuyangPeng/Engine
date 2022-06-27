///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 16:54)

#include "SpecializedIOTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SpecializedIOTesting)

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
