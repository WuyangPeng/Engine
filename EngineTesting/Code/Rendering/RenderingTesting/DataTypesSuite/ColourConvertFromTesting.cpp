///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 14:32)

#include "ColourConvertFromTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourConvertFrom.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/TextureColourDetail.h"

#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ColourConvertFromTesting)

void Rendering::ColourConvertFromTesting::MainTest()
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

void Rendering::ColourConvertFromTesting::R5G6B5ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A1R5G5B5ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A4R4G4B4ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A8ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::L8ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A8L8ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::R8G8B8ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A8R8G8B8ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A8B8G8R8ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::L16ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::G16R16ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A16B16G16R16ConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::R16FConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::G16R16FConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A16B16G16R16FConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::R32FConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::G32R32FConvertTest() noexcept
{
}

void Rendering::ColourConvertFromTesting::A32B32G32R32FConvertTest() noexcept
{
}
