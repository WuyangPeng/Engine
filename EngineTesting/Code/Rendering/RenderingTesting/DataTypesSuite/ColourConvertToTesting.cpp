///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:57)

#include "ColourConvertToTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/ColourConvertTo.h"
#include "Rendering/DataTypes/ColourTextureFormatTraits.h"

#include <boost/numeric/conversion/cast.hpp>
#include <random>
#include <vector>

Rendering::ColourConvertToTesting::ColourConvertToTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ColourConvertToTesting)

void Rendering::ColourConvertToTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ColourConvertToTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(R5G6B5ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A1R5G5B5ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A4R4G4B4ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A8ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(L8ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A8L8ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(R8G8B8ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A8R8G8B8ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A8B8G8R8ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(L16ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(G16R16ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A16B16G16R16ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(R16FConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(G16R16FConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A16B16G16R16FConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(R32FConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(G32R32FConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A32B32G32R32FConvertTest);
}

void Rendering::ColourConvertToTesting::R5G6B5ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A1R5G5B5ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A4R4G4B4ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A8ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::L8ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A8L8ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::R8G8B8ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A8R8G8B8ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A8B8G8R8ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::L16ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::G16R16ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A16B16G16R16ConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::R16FConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::G16R16FConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A16B16G16R16FConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::R32FConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::G32R32FConvertTest() noexcept
{
}

void Rendering::ColourConvertToTesting::A32B32G32R32FConvertTest() noexcept
{
}
