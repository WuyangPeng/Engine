///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:58)

#include "TextureColourTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/TextureColourDetail.h"

Rendering::TextureColourTesting::TextureColourTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureColourTesting)

void Rendering::TextureColourTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::TextureColourTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(R5G6B5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(A1R5G5B5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(A4R4G4B4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(A8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(L8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(A8L8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(R8G8B8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(A8R8G8B8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(A8B8G8R8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(L16Test);
    ASSERT_NOT_THROW_EXCEPTION_0(G16R16Test);
    ASSERT_NOT_THROW_EXCEPTION_0(A16B16G16R16Test);
    ASSERT_NOT_THROW_EXCEPTION_0(R16FTest);
    ASSERT_NOT_THROW_EXCEPTION_0(G16R16FTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A16B16G16R16FTest);
    ASSERT_NOT_THROW_EXCEPTION_0(R32FTest);
    ASSERT_NOT_THROW_EXCEPTION_0(G32R32FTest);
    ASSERT_NOT_THROW_EXCEPTION_0(A32B32G32R32FTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
}

void Rendering::TextureColourTesting::R5G6B5Test()
{
    TextureColour<TextureFormat::R5G6B5> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    const TextureColour<TextureFormat::R5G6B5> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 0x1F);

    firstTextureColour.SetColour(22u, 11u, 33u);

    ASSERT_EQUAL(firstTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0x1F);
}

void Rendering::TextureColourTesting::A1R5G5B5Test()
{
    TextureColour<TextureFormat::A1R5G5B5> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    const TextureColour<TextureFormat::A1R5G5B5> secondTextureColour(22u, 33u, 11u, 1u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 0x1F);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 11u);

    const TextureColour<TextureFormat::A1R5G5B5> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 0x1F);

    firstTextureColour.SetColour(22u, 33u, 11u, 1u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0x1F);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 11u);

    firstTextureColour.SetColour(22u, 11u, 33u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0x1F);
}

void Rendering::TextureColourTesting::A4R4G4B4Test()
{
    TextureColour<TextureFormat::A4R4G4B4> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    const TextureColour<TextureFormat::A4R4G4B4> secondTextureColour(22u, 255u, 11u, 1u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 0x0F);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 0x0F);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 11u);

    const TextureColour<TextureFormat::A4R4G4B4> thirdTextureColour(22u, 255u, 11u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 0x0F);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 0x0F);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 0x0F);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 11u);

    firstTextureColour.SetColour(22u, 255u, 11u, 1u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 11u);

    firstTextureColour.SetColour(22u, 255u, 11u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0x01);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 11u);
}

void Rendering::TextureColourTesting::A8Test()
{
    TextureColour<TextureFormat::A8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);

    const TextureColour<TextureFormat::A8> fourthTextureColour(22u);

    ASSERT_EQUAL(fourthTextureColour.GetAlpha(), 22u);

    firstTextureColour.SetColour(8u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 8u);
}

void Rendering::TextureColourTesting::L8Test()
{
    TextureColour<TextureFormat::L8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 0u);

    const TextureColour<TextureFormat::L8> fourthTextureColour(22u);

    ASSERT_EQUAL(fourthTextureColour.GetLuminance(), 22u);

    firstTextureColour.SetColour(8u);

    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 8u);
}

void Rendering::TextureColourTesting::A8L8Test()
{
    TextureColour<TextureFormat::A8L8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 0u);

    const TextureColour<TextureFormat::A8L8> fifthTextureColour(22u, 12u);

    ASSERT_EQUAL(fifthTextureColour.GetAlpha(), 22u);
    ASSERT_EQUAL(fifthTextureColour.GetLuminance(), 12u);

    firstTextureColour.SetColour(8u, 18u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 18u);
}

void Rendering::TextureColourTesting::R8G8B8Test()
{
    TextureColour<TextureFormat::R8G8B8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    const TextureColour<TextureFormat::R8G8B8> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 33u);

    firstTextureColour.SetColour(8u, 18u, 28u);

    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 18u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 28u);

    const auto ptr = thirdTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_EQUAL(ptr[0], 22u);
        ASSERT_EQUAL(ptr[1], 11u);
        ASSERT_EQUAL(ptr[2], 33u);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::A8R8G8B8Test()
{
    TextureColour<TextureFormat::A8R8G8B8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    const TextureColour<TextureFormat::A8R8G8B8> secondTextureColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 233u);

    const TextureColour<TextureFormat::A8R8G8B8> thirdTextureColour(8u, 22u, 233u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 255u);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 233u);

    firstTextureColour.SetColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    firstTextureColour.SetColour(8u, 22u, 233u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    const auto ptr = secondTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_EQUAL(ptr[0], 11u);
        ASSERT_EQUAL(ptr[1], 8u);
        ASSERT_EQUAL(ptr[2], 22u);
        ASSERT_EQUAL(ptr[3], 233u);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::A8B8G8R8Test()
{
    TextureColour<TextureFormat::A8B8G8R8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);

    const TextureColour<TextureFormat::A8B8G8R8> secondTextureColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 233u);

    const TextureColour<TextureFormat::A8B8G8R8> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 255u);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 33u);

    firstTextureColour.SetColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    firstTextureColour.SetColour(8u, 22u, 233u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    const auto ptr = secondTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_EQUAL(ptr[0], 11u);
        ASSERT_EQUAL(ptr[1], 233u);
        ASSERT_EQUAL(ptr[2], 22u);
        ASSERT_EQUAL(ptr[3], 8u);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::L16Test()
{
    TextureColour<TextureFormat::L16> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 0u);

    const TextureColour<TextureFormat::L16> fourthTextureColour(22u);

    ASSERT_EQUAL(fourthTextureColour.GetLuminance(), 22u);

    firstTextureColour.SetColour(8u);

    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 8u);

    const auto ptr = fourthTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_EQUAL(ptr[0], 22u);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::G16R16Test()
{
    TextureColour<TextureFormat::G16R16> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);

    const TextureColour<TextureFormat::G16R16> fifthTextureColour(11u, 56u);

    ASSERT_EQUAL(fifthTextureColour.GetRed(), 56u);
    ASSERT_EQUAL(fifthTextureColour.GetGreen(), 11u);

    firstTextureColour.SetColour(8u, 18u);

    ASSERT_EQUAL(firstTextureColour.GetRed(), 18u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 8u);

    const auto ptr = fifthTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_EQUAL(ptr[0], 11u);
        ASSERT_EQUAL(ptr[1], 56u);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::A16B16G16R16Test()
{
    TextureColour<TextureFormat::A16B16G16R16> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);

    const TextureColour<TextureFormat::A16B16G16R16> secondTextureColour(8u, 322u, 277u, 11u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 322u);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 277u);

    const TextureColour<TextureFormat::A16B16G16R16> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 0xFFFF);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 33u);

    firstTextureColour.SetColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    firstTextureColour.SetColour(8u, 22u, 233u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    const auto ptr = secondTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_EQUAL(ptr[0], 11u);
        ASSERT_EQUAL(ptr[1], 277u);
        ASSERT_EQUAL(ptr[2], 322u);
        ASSERT_EQUAL(ptr[3], 8u);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::R16FTest() noexcept
{
}

void Rendering::TextureColourTesting::G16R16FTest() noexcept
{
}

void Rendering::TextureColourTesting::A16B16G16R16FTest() noexcept
{
}

void Rendering::TextureColourTesting::R32FTest()
{
    TextureColour<TextureFormat::R32F> firstTextureColour;

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 0.0f, 1e-8f);

    const TextureColour<TextureFormat::R32F> fourthTextureColour(0.1f);

    ASSERT_APPROXIMATE(fourthTextureColour.GetRed(), 0.1f, 1e-8f);

    firstTextureColour.SetColour(1.2f);

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 1.0f, 1e-8f);

    const auto ptr = fourthTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_APPROXIMATE(ptr[0], 0.1f, 1e-8f);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::G32R32FTest()
{
    TextureColour<TextureFormat::G32R32F> firstTextureColour;

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.0f, 1e-8f);

    const TextureColour<TextureFormat::G32R32F> fifthTextureColour(0.2f, 0.5f);

    ASSERT_APPROXIMATE(fifthTextureColour.GetRed(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(fifthTextureColour.GetGreen(), 0.2f, 1e-8f);

    firstTextureColour.SetColour(0.2f, 0.01f);

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.2f, 1e-8f);

    const auto ptr = fifthTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_APPROXIMATE(ptr[0], 0.2f, 1e-8f);
        ASSERT_APPROXIMATE(ptr[1], 0.5f, 1e-8f);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::A32B32G32R32FTest()
{
    TextureColour<TextureFormat::A32B32G32R32F> firstTextureColour;

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetBlue(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(), 0.0f, 1e-8f);

    const TextureColour<TextureFormat::A32B32G32R32F> secondTextureColour(0.01f, 0.1f, 0.5f, 1.66f);

    ASSERT_APPROXIMATE(secondTextureColour.GetRed(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(secondTextureColour.GetGreen(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondTextureColour.GetBlue(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(secondTextureColour.GetAlpha(), 1.0f, 1e-8f);

    const TextureColour<TextureFormat::A32B32G32R32F> thirdTextureColour(0.01f, 0.1f, 0.5f);

    ASSERT_APPROXIMATE(thirdTextureColour.GetRed(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(thirdTextureColour.GetGreen(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(thirdTextureColour.GetBlue(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(thirdTextureColour.GetAlpha(), 1.0f, 1e-8f);

    firstTextureColour.SetColour(1.0f, 0.1f, 0.01f, 0.02f);

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetBlue(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(), 0.02f, 1e-8f);

    firstTextureColour.SetColour(1.0f, 0.1f, 0.01f);

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetBlue(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(), 0.02f, 1e-8f);

    const auto ptr = secondTextureColour.GetPoint();

    if (ptr != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_APPROXIMATE(ptr[0], 1.0f, 1e-8f);
        ASSERT_APPROXIMATE(ptr[1], 0.5f, 1e-8f);
        ASSERT_APPROXIMATE(ptr[2], 0.1f, 1e-8f);
        ASSERT_APPROXIMATE(ptr[3], 0.01f, 1e-8f);

#include SYSTEM_WARNING_POP
    }
}

void Rendering::TextureColourTesting::ConvertingTest() noexcept
{
}

void Rendering::TextureColourTesting::OperatorTest() noexcept
{
}