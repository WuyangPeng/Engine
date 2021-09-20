// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.3 (2019/09/03 15:25)

#include "TextureColourTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/TextureColourDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TextureColourTesting)

void Rendering::TextureColourTesting ::MainTest()
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

void Rendering::TextureColourTesting ::R5G6B5Test()
{
    TextureColour<TextureFormat::R5G6B5> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::R5G6B5> secondTextureColour(8u,22u,33u,11u);

    TextureColour<TextureFormat::R5G6B5> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 0x1F);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(thirdTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(thirdTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    //  TextureColour<TextureFormat::R5G6B5> fourthTextureColour(22u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::R5G6B5> fifthTextureColour(22u,12u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,22u,33u,11u);

    firstTextureColour.SetColour(22u, 11u, 33u);

    ASSERT_EQUAL(firstTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0x1F);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,22u);

    // 	const TextureColour<TextureFormat::R5G6B5>::BitType* ptr = thirdTextureColour.GetPoint();
    //
    // 	ASSERT_EQUAL(ptr[0],22u);
    // 	ASSERT_EQUAL(ptr[1],11u);
    // 	ASSERT_EQUAL(ptr[2],0x1F);
}

void Rendering::TextureColourTesting ::A1R5G5B5Test()
{
    TextureColour<TextureFormat::A1R5G5B5> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    TextureColour<TextureFormat::A1R5G5B5> secondTextureColour(22u, 33u, 11u, 1u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 0x1F);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 11u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(secondTextureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A1R5G5B5> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 0x1F);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(thirdTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A1R5G5B5> fourthTextureColour(22u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A1R5G5B5> fifthTextureColour(22u,12u);

    firstTextureColour.SetColour(22u, 33u, 11u, 1u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0x1F);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 11u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    firstTextureColour.SetColour(22u, 11u, 33u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0x1F);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,22u);

    // 	const TextureColour<TextureFormat::A1R5G5B5>::BitType* ptr = secondTextureColour.GetPoint();
    //
    // 	ASSERT_EQUAL(ptr[0],1u);
    // 	ASSERT_EQUAL(ptr[1],22u);
    // 	ASSERT_EQUAL(ptr[2],0x1F);
    // 	ASSERT_EQUAL(ptr[3],11u);
}

void Rendering::TextureColourTesting ::A4R4G4B4Test()
{
    TextureColour<TextureFormat::A4R4G4B4> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A4R4G4B4> secondTextureColour(22u, 255u, 11u, 1u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 0x0F);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 0x0F);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 11u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(secondTextureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A4R4G4B4> thirdTextureColour(22u, 255u, 11u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 0x0F);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 0x0F);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 0x0F);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 11u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(thirdTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A4R4G4B4> fourthTextureColour(22u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A4R4G4B4> fifthTextureColour(22u,12u);

    firstTextureColour.SetColour(22u, 255u, 11u, 1u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 1u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 11u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    firstTextureColour.SetColour(22u, 255u, 11u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0x0F);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 11u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,22u);

    // 	const TextureColour<TextureFormat::A4R4G4B4>::BitType* ptr = secondTextureColour.GetPoint();
    //
    // 	ASSERT_EQUAL(ptr[0],1u);
    // 	ASSERT_EQUAL(ptr[1],0x0F);
    // 	ASSERT_EQUAL(ptr[2],0x0F);
    // 	ASSERT_EQUAL(ptr[3],11u);
}

void Rendering::TextureColourTesting ::A8Test()
{
    TextureColour<TextureFormat::A8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8> secondTextureColour(8u,22u,33u,11u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8> thirdTextureColour(22u,11u,33u);

    TextureColour<TextureFormat::A8> fourthTextureColour(22u);

    ASSERT_EQUAL(fourthTextureColour.GetAlpha(), 22u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(fourthTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetBlue(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8> fifthTextureColour(22u,12u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u,8u,8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u,8u);

    firstTextureColour.SetColour(8u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 8u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u);

    // 	const TextureColour<TextureFormat::A8>::BitType* ptr = fourthTextureColour.GetPoint();
    //
    // 	ASSERT_EQUAL(ptr[0],22u);
}

void Rendering::TextureColourTesting ::L8Test()
{
    TextureColour<TextureFormat::L8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::L8> secondTextureColour(8u,22u,33u,11u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::L8> thirdTextureColour(22u,11u,33u);

    TextureColour<TextureFormat::L8> fourthTextureColour(22u);

    ASSERT_EQUAL(fourthTextureColour.GetLuminance(), 22u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(fourthTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetBlue(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::L8> fifthTextureColour(22u,12u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u,8u,8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u,8u);

    firstTextureColour.SetColour(8u);

    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 8u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u);

    // 	const TextureColour<TextureFormat::L8>::BitType* ptr = fourthTextureColour.GetPoint();
    //
    // 	ASSERT_EQUAL(ptr[0],22u);
}

void Rendering::TextureColourTesting ::A8L8Test()
{
    TextureColour<TextureFormat::A8L8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8L8> secondTextureColour(8u,22u,33u,11u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8L8> thirdTextureColour(22u,11u,33u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8L8> fourthTextureColour(22u);

    TextureColour<TextureFormat::A8L8> fifthTextureColour(22u, 12u);

    ASSERT_EQUAL(fifthTextureColour.GetAlpha(), 22u);
    ASSERT_EQUAL(fifthTextureColour.GetLuminance(), 12u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(fifthTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(fifthTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(fifthTextureColour.GetBlue(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u,8u,8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u,8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    firstTextureColour.SetColour(8u, 18u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 18u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);

    // 	const TextureColour<TextureFormat::A8L8>::BitType* ptr = fifthTextureColour.GetPoint();
    //
    // 	ASSERT_EQUAL(ptr[0],22u);
    // 	ASSERT_EQUAL(ptr[1],12u);
}

void Rendering::TextureColourTesting ::R8G8B8Test()
{
    TextureColour<TextureFormat::R8G8B8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::R8G8B8> secondTextureColour(8u,22u,33u,11u);

    TextureColour<TextureFormat::R8G8B8> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 33u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(thirdTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(thirdTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::R8G8B8> fourthTextureColour(22u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::R8G8B8> fifthTextureColour(22u,12u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,8u,8u,8u);

    firstTextureColour.SetColour(8u, 18u, 28u);

    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 18u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 28u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,18u);

    const auto ptr = thirdTextureColour.GetPoint();

    ASSERT_EQUAL(ptr[0], 22u);
    ASSERT_EQUAL(ptr[1], 11u);
    ASSERT_EQUAL(ptr[2], 33u);
}

void Rendering::TextureColourTesting ::A8R8G8B8Test()
{
    TextureColour<TextureFormat::A8R8G8B8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(textureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A8R8G8B8> secondTextureColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(secondTextureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A8R8G8B8> thirdTextureColour(8u, 22u, 233u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 255u);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(thirdTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8R8G8B8> fourthTextureColour(22u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8R8G8B8> fifthTextureColour(22u,12u);

    firstTextureColour.SetColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    firstTextureColour.SetColour(8u, 22u, 233u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 255u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,18u);

    const auto ptr = secondTextureColour.GetPoint();

    ASSERT_EQUAL(ptr[0], 11u);
    ASSERT_EQUAL(ptr[1], 8u);
    ASSERT_EQUAL(ptr[2], 22u);
    ASSERT_EQUAL(ptr[3], 233u);
}

void Rendering::TextureColourTesting ::A8B8G8R8Test()
{
    TextureColour<TextureFormat::A8B8G8R8> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A8B8G8R8> secondTextureColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(secondTextureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A8B8G8R8> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 255u);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 33u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(thirdTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8B8G8R8> fourthTextureColour(22u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A8B8G8R8> fifthTextureColour(22u,12u);

    firstTextureColour.SetColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    firstTextureColour.SetColour(8u, 22u, 233u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 255u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,18u);

    const auto ptr = secondTextureColour.GetPoint();

    ASSERT_EQUAL(ptr[0], 11u);
    ASSERT_EQUAL(ptr[1], 233u);
    ASSERT_EQUAL(ptr[2], 22u);
    ASSERT_EQUAL(ptr[3], 8u);
}

void Rendering::TextureColourTesting ::L16Test()
{
    TextureColour<TextureFormat::L16> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::L16> secondTextureColour(8u,22u,33u,11u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::L16> thirdTextureColour(22u,11u,33u);

    TextureColour<TextureFormat::L16> fourthTextureColour(22u);

    ASSERT_EQUAL(fourthTextureColour.GetLuminance(), 22u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(fourthTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(fourthTextureColour.GetBlue(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::L16> fifthTextureColour(22u,12u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,22u,233u,11u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,22u,233u);

    firstTextureColour.SetColour(8u);

    ASSERT_EQUAL(firstTextureColour.GetLuminance(), 8u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetRed(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetGreen(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,18u);

    const auto ptr =
        fourthTextureColour.GetPoint();

    ASSERT_EQUAL(ptr[0], 22u);
}

void Rendering::TextureColourTesting ::G16R16Test()
{
    TextureColour<TextureFormat::G16R16> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // TextureColour<TextureFormat::G16R16> secondTextureColour(8u,22u,33u,11u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::G16R16> thirdTextureColour(22u,11u,33u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::G16R16> fourthTextureColour(22u);

    TextureColour<TextureFormat::G16R16> fifthTextureColour(11u, 56u);

    ASSERT_EQUAL(fifthTextureColour.GetRed(), 56u);
    ASSERT_EQUAL(fifthTextureColour.GetGreen(), 11u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(fifthTextureColour.GetBlue(),0u);
    // ASSERT_EQUAL(fifthTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(fifthTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,22u,233u,11u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,22u,233u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    firstTextureColour.SetColour(8u, 18u);

    ASSERT_EQUAL(firstTextureColour.GetRed(), 18u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 8u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetBlue(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetAlpha(),0u);
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    const auto ptr =
        fifthTextureColour.GetPoint();

    ASSERT_EQUAL(ptr[0], 11u);
    ASSERT_EQUAL(ptr[1], 56u);
}

void Rendering::TextureColourTesting ::A16B16G16R16Test()
{
    TextureColour<TextureFormat::A16B16G16R16> firstTextureColour;

    ASSERT_EQUAL(firstTextureColour.GetRed(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 0u);
    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A16B16G16R16> secondTextureColour(8u, 322u, 277u, 11u);

    ASSERT_EQUAL(secondTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(secondTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(secondTextureColour.GetGreen(), 322u);
    ASSERT_EQUAL(secondTextureColour.GetBlue(), 277u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(secondTextureColour.GetLuminance(),0u);

    TextureColour<TextureFormat::A16B16G16R16> thirdTextureColour(22u, 11u, 33u);

    ASSERT_EQUAL(thirdTextureColour.GetAlpha(), 0xFFFF);
    ASSERT_EQUAL(thirdTextureColour.GetRed(), 22u);
    ASSERT_EQUAL(thirdTextureColour.GetGreen(), 11u);
    ASSERT_EQUAL(thirdTextureColour.GetBlue(), 33u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(thirdTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A16B16G16R16> fourthTextureColour(22u);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A16B16G16R16> fifthTextureColour(22u,12u);

    firstTextureColour.SetColour(8u, 22u, 233u, 11u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 11u);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    firstTextureColour.SetColour(8u, 22u, 233u);

    ASSERT_EQUAL(firstTextureColour.GetAlpha(), 0xFFFF);
    ASSERT_EQUAL(firstTextureColour.GetRed(), 8u);
    ASSERT_EQUAL(firstTextureColour.GetGreen(), 22u);
    ASSERT_EQUAL(firstTextureColour.GetBlue(), 233u);

    // 下面代码不应该通过编译
    // ASSERT_EQUAL(firstTextureColour.GetLuminance(),0u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(8u,18u);

    const auto ptr =
        secondTextureColour.GetPoint();

    ASSERT_EQUAL(ptr[0], 11u);
    ASSERT_EQUAL(ptr[1], 277u);
    ASSERT_EQUAL(ptr[2], 322u);
    ASSERT_EQUAL(ptr[3], 8u);
}

void Rendering::TextureColourTesting ::R16FTest()
{
//     TextureColour<TextureFormat::R16F> firstTextureColour;
// 
//     ASSERT_APPROXIMATE(firstTextureColour.GetRed().ToFloat(), 0.0f, 1e-4f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(firstTextureColour.GetGreen().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetBlue().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetAlpha().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     // 下面代码不应该通过编译
//     /*
// 	TextureColour<TextureFormat::R16F> 
// 		secondTextureColour(HalfFloat(0.01f),HalfFloat(0.1f),
// 		                    HalfFloat(0.5f),HalfFloat(0.66f));
// 							*/
// 
//     // 下面代码不应该通过编译
//     // TextureColour<TextureFormat::R16F>
//     // 	 thirdTextureColour(HalfFloat(0.01f),HalfFloat(0.1f),HalfFloat(0.5f));
// 
//     TextureColour<TextureFormat::R16F> fourthTextureColour(HalfFloat(0.1f));
// 
//     ASSERT_APPROXIMATE(fourthTextureColour.GetRed().ToFloat(), 0.1f, 1e-4f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(fourthTextureColour.GetAlpha().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(fourthTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(fourthTextureColour.GetGreen().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(fourthTextureColour.GetBlue().ToFloat(),0.0f,1e-8f);
// 
//     // 下面代码不应该通过编译
//     // TextureColour<TextureFormat::R16F>
//     // 	fifthTextureColour(HalfFloat(0.01f),HalfFloat(0.1f));
// 
//     // 下面代码不应该通过编译
//     // firstTextureColour.SetColour(HalfFloat(1.0f),HalfFloat(0.1f),
//     // 	                         HalfFloat(0.01f),HalfFloat(0.02f));
// 
//     // 下面代码不应该通过编译
//     // firstTextureColour.SetColour(HalfFloat(1.0f),HalfFloat(0.1f),HalfFloat(0.01f));
// 
//     firstTextureColour.SetColour(HalfFloat(1.2f));
// 
//     ASSERT_APPROXIMATE(firstTextureColour.GetRed().ToFloat(), 1.0f, 1e-8f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(firstTextureColour.GetAlpha().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetGreen().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetBlue().ToFloat(),0.0f,1e-8f);
// 
//     // 下面代码不应该通过编译
//     // firstTextureColour.SetColour(HalfFloat(0.2f),HalfFloat(0.01f));
// 
//     const auto ptr =
//         fourthTextureColour.GetPoint();
// 
//     ASSERT_APPROXIMATE(ptr[0].ToFloat(), 0.1f, 1e-4f);
}

void Rendering::TextureColourTesting ::G16R16FTest()
{
//     TextureColour<TextureFormat::G16R16F> firstTextureColour;
// 
//     ASSERT_APPROXIMATE(firstTextureColour.GetRed().ToFloat(), 0.0f, 1e-4f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetGreen().ToFloat(), 0.0f, 1e-4f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(firstTextureColour.GetBlue().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetAlpha().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     // 下面代码不应该通过编译
//     /*
// 	TextureColour<TextureFormat::G16R16F> 
// 		secondTextureColour(HalfFloat(0.01f),HalfFloat(0.1f),
// 		                    HalfFloat(0.5f),HalfFloat(0.66f)); 
// 							*/
// 
//     // 下面代码不应该通过编译
//     // TextureColour<TextureFormat::G16R16F>
//     // 	 thirdTextureColour(HalfFloat(0.01f),HalfFloat(0.1f),HalfFloat(0.5f));
// 
//     // 下面代码不应该通过编译
//     // TextureColour<TextureFormat::G16R16F> fourthTextureColour(HalfFloat(0.5f));
// 
//     TextureColour<TextureFormat::G16R16F> fifthTextureColour(HalfFloat(0.2f), HalfFloat(0.9f));
// 
//     ASSERT_APPROXIMATE(fifthTextureColour.GetRed().ToFloat(), 0.9f, 1e-4f);
//     ASSERT_APPROXIMATE(fifthTextureColour.GetGreen().ToFloat(), 0.2f, 1e-4f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(fifthTextureColour.GetBlue().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(fifthTextureColour.GetAlpha().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(fifthTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     // 下面代码不应该通过编译
//     // firstTextureColour.SetColour(HalfFloat(1.0f),HalfFloat(0.1f),
//     //	                         HalfFloat(0.01f),HalfFloat(0.02f));
// 
//     // 下面代码不应该通过编译
//     // firstTextureColour.SetColour(HalfFloat(1.0f),HalfFloat(0.1f),HalfFloat(0.01f));
// 
//     // 下面代码不应该通过编译
//     // firstTextureColour.SetColour(HalfFloat(1.2f));
// 
//     firstTextureColour.SetColour(HalfFloat(0.2f), HalfFloat(0.01f));
// 
//     ASSERT_APPROXIMATE(firstTextureColour.GetRed().ToFloat(), 0.01f, 1e-4f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetGreen().ToFloat(), 0.2f, 1e-4f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(firstTextureColour.GetBlue().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetAlpha().ToFloat(),0.0f,1e-8f);
//     // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     const TextureColour<TextureFormat::G16R16F>::BitType* ptr =
//         fifthTextureColour.GetPoint();
// 
//     ASSERT_APPROXIMATE(ptr[0].ToFloat(), 0.2f, 1e-4f);
//     ASSERT_APPROXIMATE(ptr[1].ToFloat(), 0.9f, 1e-4f);
}

void Rendering::TextureColourTesting ::A16B16G16R16FTest()
{
//     TextureColour<TextureFormat::A16B16G16R16F> firstTextureColour;
// 
//     ASSERT_APPROXIMATE(firstTextureColour.GetRed().ToFloat(), 0.0f, 1e-4f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetGreen().ToFloat(), 0.0f, 1e-4f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetBlue().ToFloat(), 0.0f, 1e-4f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetAlpha().ToFloat(), 0.0f, 1e-4f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     TextureColour<TextureFormat::A16B16G16R16F>
//         secondTextureColour(HalfFloat(0.01f), HalfFloat(0.1f),
//                             HalfFloat(0.5f), HalfFloat(0.66f));
// 
//     ASSERT_APPROXIMATE(secondTextureColour.GetRed().ToFloat(), 0.01f, 1e-4f);
//     ASSERT_APPROXIMATE(secondTextureColour.GetGreen().ToFloat(), 0.1f, 1e-4f);
//     ASSERT_APPROXIMATE(secondTextureColour.GetBlue().ToFloat(), 0.5f, 1e-8f);
//     ASSERT_APPROXIMATE(secondTextureColour.GetAlpha().ToFloat(), 0.66f, 1e-3f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(secondTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     TextureColour<TextureFormat::A16B16G16R16F>
//         thirdTextureColour(HalfFloat(0.01f), HalfFloat(0.1f), HalfFloat(0.5f));
// 
//     ASSERT_APPROXIMATE(thirdTextureColour.GetRed().ToFloat(), 0.01f, 1e-4f);
//     ASSERT_APPROXIMATE(thirdTextureColour.GetGreen().ToFloat(), 0.1f, 1e-4f);
//     ASSERT_APPROXIMATE(thirdTextureColour.GetBlue().ToFloat(), 0.5f, 1e-8f);
//     ASSERT_APPROXIMATE(thirdTextureColour.GetAlpha().ToFloat(), 1.0f, 1e-8f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(thirdTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     // 下面代码不应该通过编译
//     // TextureColour<TextureFormat::A16B16G16R16F> fourthTextureColour(HalfFloat(0.5f));
// 
//     // 下面代码不应该通过编译
//     // TextureColour<TextureFormat::A16B16G16R16F>
//     //	fifthTextureColour(HalfFloat(0.01f),HalfFloat(0.1f));
// 
//     firstTextureColour.SetColour(HalfFloat(1.0f), HalfFloat(0.1f),
//                                  HalfFloat(0.01f), HalfFloat(0.02f));
// 
//     ASSERT_APPROXIMATE(firstTextureColour.GetRed().ToFloat(), 1.0f, 1e-8f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetGreen().ToFloat(), 0.1f, 1e-4f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetBlue().ToFloat(), 0.01f, 1e-4f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetAlpha().ToFloat(), 0.02f, 1e-4f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     firstTextureColour.SetColour(HalfFloat(1.0f), HalfFloat(0.1f),
//                                  HalfFloat(0.01f));
// 
//     ASSERT_APPROXIMATE(firstTextureColour.GetRed().ToFloat(), 1.0f, 1e-8f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetGreen().ToFloat(), 0.1f, 1e-4f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetBlue().ToFloat(), 0.01f, 1e-5f);
//     ASSERT_APPROXIMATE(firstTextureColour.GetAlpha().ToFloat(), 1.0f, 1e-8f);
// 
//     // 下面代码不应该通过编译
//     // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance().ToFloat(),0.0f,1e-8f);
// 
//     // 下面代码不应该通过编译
//     // firstTextureColour.SetColour(HalfFloat(1.2f));
// 
//     // 下面代码不应该通过编译
//     // firstTextureColour.SetColour(HalfFloat(0.2f),HalfFloat(0.01f));
// 
//     const TextureColour<TextureFormat::A16B16G16R16F>::BitType* ptr =
//         secondTextureColour.GetPoint();
// 
//     ASSERT_APPROXIMATE(ptr[0].ToFloat(), 0.66f, 1e-3f);
//     ASSERT_APPROXIMATE(ptr[1].ToFloat(), 0.5f, 1e-8f);
//     ASSERT_APPROXIMATE(ptr[2].ToFloat(), 0.1f, 1e-4f);
//     ASSERT_APPROXIMATE(ptr[3].ToFloat(), 0.01f, 1e-5f);
}

void Rendering::TextureColourTesting ::R32FTest()
{
    TextureColour<TextureFormat::R32F> firstTextureColour;

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 0.0f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(firstTextureColour.GetGreen(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(firstTextureColour.GetBlue(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance(),0.0f,1e-8f);

    // TextureColour<TextureFormat::R32F> secondTextureColour(0.01f,0.1f,0.5f,0.66f);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::R32F> thirdTextureColour(0.01f,0.1f,0.5f);

    TextureColour<TextureFormat::R32F> fourthTextureColour(0.1f);

    ASSERT_APPROXIMATE(fourthTextureColour.GetRed(), 0.1f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(fourthTextureColour.GetAlpha(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(fourthTextureColour.GetLuminance(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(fourthTextureColour.GetGreen(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(fourthTextureColour.GetBlue(),0.0f,1e-8f);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::R32F> fifthTextureColour(0.01f,0.1f);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(1.0f,0.1f,0.01f,0.02f);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(1.0f,0.1f,0.01f);

    firstTextureColour.SetColour(1.2f);

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 1.0f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(fourthTextureColour.GetAlpha(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(fourthTextureColour.GetLuminance(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(fourthTextureColour.GetGreen(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(fourthTextureColour.GetBlue(),0.0f,1e-8f);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(0.2f,0.01f);

    const auto ptr =
        fourthTextureColour.GetPoint();

    ASSERT_APPROXIMATE(ptr[0], 0.1f, 1e-8f);
}

void Rendering::TextureColourTesting ::G32R32FTest()
{
    TextureColour<TextureFormat::G32R32F> firstTextureColour;

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.0f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(firstTextureColour.GetBlue(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance(),0.0f,1e-8f);

    // TextureColour<TextureFormat::G32R32F>
    // 	secondTextureColour(0.01f,0.1f,0.5f,0.66f);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::G32R32F> thirdTextureColour(0.01f,0.1f,0.5f);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::G32R32F> fourthTextureColour(0.5f);

    TextureColour<TextureFormat::G32R32F> fifthTextureColour(0.2f, 0.5f);

    ASSERT_APPROXIMATE(fifthTextureColour.GetRed(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(fifthTextureColour.GetGreen(), 0.2f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(fifthTextureColour.GetBlue(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(fifthTextureColour.GetAlpha(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(fifthTextureColour.GetLuminance(),0.0f,1e-8f);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(1.0f,0.1f,0.01f,0.02f);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(1.0f,0.1f,0.01f);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(1.2f);

    firstTextureColour.SetColour(0.2f, 0.01f);

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.2f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(firstTextureColour.GetBlue(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(),0.0f,1e-8f);
    // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance(),0.0f,1e-8f);

    const auto ptr =
        fifthTextureColour.GetPoint();

    ASSERT_APPROXIMATE(ptr[0], 0.2f, 1e-8f);
    ASSERT_APPROXIMATE(ptr[1], 0.5f, 1e-8f);
}

void Rendering::TextureColourTesting ::A32B32G32R32FTest()
{
    TextureColour<TextureFormat::A32B32G32R32F> firstTextureColour;

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetBlue(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(), 0.0f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance(),0.0f,1e-8f);

    TextureColour<TextureFormat::A32B32G32R32F> secondTextureColour(0.01f, 0.1f, 0.5f, 1.66f);

    ASSERT_APPROXIMATE(secondTextureColour.GetRed(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(secondTextureColour.GetGreen(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondTextureColour.GetBlue(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(secondTextureColour.GetAlpha(), 1.0f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(secondTextureColour.GetLuminance(),0.0f,1e-8f);

    TextureColour<TextureFormat::A32B32G32R32F> thirdTextureColour(0.01f, 0.1f, 0.5f);

    ASSERT_APPROXIMATE(thirdTextureColour.GetRed(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(thirdTextureColour.GetGreen(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(thirdTextureColour.GetBlue(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(thirdTextureColour.GetAlpha(), 1.0f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(thirdTextureColour.GetLuminance(),0.0f,1e-8f);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A32B32G32R32F> fourthTextureColour(0.5f);

    // 下面代码不应该通过编译
    // TextureColour<TextureFormat::A32B32G32R32F> fifthTextureColour(0.01f,0.1f);

    firstTextureColour.SetColour(1.0f, 0.1f, 0.01f, 0.02f);

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetBlue(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(), 0.02f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance(),0.0f,1e-8f);

    firstTextureColour.SetColour(1.0f, 0.1f, 0.01f);

    ASSERT_APPROXIMATE(firstTextureColour.GetRed(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetGreen(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetBlue(), 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(firstTextureColour.GetAlpha(), 1.0f, 1e-8f);

    // 下面代码不应该通过编译
    // ASSERT_APPROXIMATE(firstTextureColour.GetLuminance(),0.0f,1e-8f);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(1.2f);

    // 下面代码不应该通过编译
    // firstTextureColour.SetColour(0.2f,0.01f);

    const auto ptr =
        secondTextureColour.GetPoint();

    ASSERT_APPROXIMATE(ptr[0], 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(ptr[1], 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(ptr[2], 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(ptr[3], 0.01f, 1e-8f);
}

void Rendering::TextureColourTesting ::ConvertingTest()
{
//     TextureColour<TextureFormat::A32B32G32R32F> firstTextureColour(0.01f, 0.1f, 0.5f, 1.66f);
// 
//     TextureColour<TextureFormat::A16B16G16R16F> secondTextureColour(firstTextureColour);
// 
//     ASSERT_APPROXIMATE(secondTextureColour.GetRed().ToFloat(), 0.01f, 1e-4f);
//     ASSERT_APPROXIMATE(secondTextureColour.GetGreen().ToFloat(), 0.1f, 1e-4f);
//     ASSERT_APPROXIMATE(secondTextureColour.GetBlue().ToFloat(), 0.5f, 1e-3f);
//     ASSERT_APPROXIMATE(secondTextureColour.GetAlpha().ToFloat(), 1.0f, 1e-3f);
// 
//     // 下面代码不应该通过编译
//     // TextureColour<TextureFormat::R32F> thirdTextureColour(firstTextureColour);
// 
//     TextureColour<TextureFormat::R8G8B8> fourthTextureColour(2u, 3u, 4u);
// 
//     TextureColour<TextureFormat::A8B8G8R8> fifthTextureColour(fourthTextureColour);
// 
//     ASSERT_EQUAL(fifthTextureColour.GetRed(), 2u);
//     ASSERT_EQUAL(fifthTextureColour.GetGreen(), 3u);
//     ASSERT_EQUAL(fifthTextureColour.GetBlue(), 4u);
//     ASSERT_EQUAL(fifthTextureColour.GetAlpha(), 0xFF);
// 
//     // 下面代码不应该通过编译
//     // TextureColour<TextureFormat::L8> sixthTextureColour(fourthTextureColour);
// 
//     TextureColour<TextureFormat::A16B16G16R16F> seventhTextureColour(fourthTextureColour);
// 
//     ASSERT_APPROXIMATE(seventhTextureColour.GetRed().ToFloat(), 2.0f / 255.0f, 1e-4f);
//     ASSERT_APPROXIMATE(seventhTextureColour.GetGreen().ToFloat(), 3.0f / 255.0f, 1e-4f);
//     ASSERT_APPROXIMATE(seventhTextureColour.GetBlue().ToFloat(), 4.0f / 255.0f, 1e-4f);
//     ASSERT_APPROXIMATE(seventhTextureColour.GetAlpha().ToFloat(), 1.0f, 1e-8f);
// 
//     TextureColour<TextureFormat::R8G8B8> eighthTextureColour(seventhTextureColour);
// 
//     ASSERT_EQUAL(eighthTextureColour.GetRed(), 2u);
//     ASSERT_EQUAL(eighthTextureColour.GetGreen(), 3u);
//     ASSERT_EQUAL(eighthTextureColour.GetBlue(), 4u);
// 
//     TextureColour<TextureFormat::A32B32G32R32F> ninthTextureColour(eighthTextureColour);
// 
//     ASSERT_APPROXIMATE(ninthTextureColour.GetRed(), 2.0f / 255.0f, 1e-8f);
//     ASSERT_APPROXIMATE(ninthTextureColour.GetGreen(), 3.0f / 255.0f, 1e-8f);
//     ASSERT_APPROXIMATE(ninthTextureColour.GetBlue(), 4.0f / 255.0f, 1e-8f);
//     ASSERT_APPROXIMATE(ninthTextureColour.GetAlpha(), 1.0f, 1e-8f);
}

void Rendering::TextureColourTesting ::OperatorTest()
{
//     TextureColour<TextureFormat::R32F> firstTextureColour(0.01f);
//     TextureColour<TextureFormat::R32F> secondTextureColour(0.2f);
// 
//     secondTextureColour += firstTextureColour;
// 
//     ASSERT_APPROXIMATE(secondTextureColour.GetRed(), 0.21f, 1e-7f);
// 
//     TextureColour<TextureFormat::G16R16> thirdTextureColour(22u, 25u);
//     TextureColour<TextureFormat::G16R16> fourthTextureColour(27u, 55u);
// 
//     fourthTextureColour += thirdTextureColour;
// 
//     ASSERT_EQUAL(fourthTextureColour.GetRed(), 80u);
//     ASSERT_EQUAL(fourthTextureColour.GetGreen(), 49u);
// 
//     TextureColour<TextureFormat::R8G8B8> fifthTextureColour(25u, 25u, 22u);
//     TextureColour<TextureFormat::R8G8B8> sixthTextureColour(25u, 15u, 23u);
// 
//     fifthTextureColour *= sixthTextureColour;
// 
//     ASSERT_EQUAL(fifthTextureColour.GetRed(), 25u * 25u / 255u);
//     ASSERT_EQUAL(fifthTextureColour.GetGreen(), 25u * 15u / 255u);
//     ASSERT_EQUAL(fifthTextureColour.GetBlue(), 22u * 23u / 255u);
// 
//     TextureColour<TextureFormat::A16B16G16R16F>
//         seventhTextureColour(HalfFloat(0.1f), HalfFloat(0.3f),
//                              HalfFloat(0.2f), HalfFloat(0.4f));
//     TextureColour<TextureFormat::A16B16G16R16F>
//         eighthTextureColour(HalfFloat(0.5f), HalfFloat(0.7f),
//                             HalfFloat(0.6f), HalfFloat(0.8f));
// 
//     seventhTextureColour *= eighthTextureColour;
// 
//     ASSERT_APPROXIMATE(seventhTextureColour.GetRed().ToFloat(),
//                        0.05f, 1e-4f);
//     ASSERT_APPROXIMATE(seventhTextureColour.GetGreen().ToFloat(),
//                        0.21f, 1e-3f);
//     ASSERT_APPROXIMATE(seventhTextureColour.GetBlue().ToFloat(),
//                        0.12f, 1e-3f);
//     ASSERT_APPROXIMATE(seventhTextureColour.GetAlpha().ToFloat(),
//                        0.32f, 1e-3f);
// 
//     TextureColour<TextureFormat::R5G6B5> ninthTextureColour(1u, 5u, 14u);
// 
//     ninthTextureColour *= int8_t(5);
// 
//     ASSERT_EQUAL(ninthTextureColour.GetRed(), 5u);
//     ASSERT_EQUAL(ninthTextureColour.GetGreen(), 25u);
//     ASSERT_EQUAL(ninthTextureColour.GetBlue(), 0x1F);
// 
//     TextureColour<TextureFormat::A1R5G5B5>
//         elevenTextureColour(1u, 5u, 14u);
// 
//     elevenTextureColour /= int8_t(5);
// 
//     ASSERT_EQUAL(elevenTextureColour.GetRed(), 0u);
//     ASSERT_EQUAL(elevenTextureColour.GetGreen(), 1u);
//     ASSERT_EQUAL(elevenTextureColour.GetBlue(), 2u);
//     ASSERT_EQUAL(elevenTextureColour.GetAlpha(), 0u);
// 
//     TextureColour<TextureFormat::R32F>
//         twelveTextureColour = firstTextureColour + secondTextureColour;
// 
//     ASSERT_APPROXIMATE(twelveTextureColour.GetRed(), 0.22f, 1e-7f);
// 
//     twelveTextureColour = secondTextureColour - firstTextureColour;
// 
//     ASSERT_APPROXIMATE(twelveTextureColour.GetRed(), 0.2f, 1e-7f);
// 
//     twelveTextureColour = secondTextureColour * firstTextureColour;
// 
//     ASSERT_APPROXIMATE(twelveTextureColour.GetRed(), 0.0021f, 1e-7f);
// 
//     ASSERT_TRUE(fifthTextureColour == fifthTextureColour);
//     ASSERT_FALSE(fifthTextureColour == sixthTextureColour);
//     ASSERT_FALSE(fifthTextureColour != fifthTextureColour);
//     ASSERT_TRUE(fifthTextureColour != sixthTextureColour);
// 
//     ASSERT_TRUE(Approximate(twelveTextureColour, twelveTextureColour, 1e-8f));
//     ASSERT_FALSE(Approximate(firstTextureColour, secondTextureColour, 1e-8f));
//     ASSERT_TRUE(Approximate(seventhTextureColour, seventhTextureColour, HalfFloat(1e-8f)));

    // 以下代码不应该通过编译
    // ASSERT_TRUE(twelveTextureColour == twelveTextureColour);
    // ASSERT_TRUE(Approximate(fifthTextureColour,sixthTextureColour,0));
}