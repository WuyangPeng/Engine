///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 14:39)

#include "ColourConvertToTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourConvertTo.h"
#include "Rendering/DataTypes/ColourTextureFormatTraits.h"

#include <boost/numeric/conversion/cast.hpp>
#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ColourConvertToTesting)

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
