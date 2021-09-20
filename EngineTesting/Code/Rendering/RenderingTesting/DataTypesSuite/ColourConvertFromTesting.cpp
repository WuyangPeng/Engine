// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 14:49)

#include "ColourConvertFromTesting.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/ColourConvertFrom.h"
#include "Rendering/DataTypes/TextureColourDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,ColourConvertFromTesting) 

void Rendering::ColourConvertFromTesting
	::MainTest()
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
 
void Rendering::ColourConvertFromTesting
	::R5G6B5ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘R5G6B5
// 		vector<FloatColour> r5g6b5Colour(buffer.size() / 2);
// 
// 		ColourConvertFrom::ConvertFromR5G6B5(boost::numeric_cast<int>(r5g6b5Colour.size()),&buffer[0],&r5g6b5Colour[0]);
// 
// 		const unsigned short* source = 
// 			reinterpret_cast<const unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < r5g6b5Colour.size(); ++i)
// 		{
// 			unsigned char red = static_cast<unsigned char>((*source & 0xF800u) >> 11);
// 			unsigned char green = static_cast<unsigned char>((*source & 0x07E0u) >> 5);
// 			unsigned char blue = static_cast<unsigned char>(*source & 0x001Fu);
// 						
// 			TextureColour<TextureFormat::R5G6B5> textureColour(red,green,blue);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(r5g6b5Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(r5g6b5Colour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);
// 			ASSERT_APPROXIMATE(r5g6b5Colour[i].GetBlue(),floatTextureColour.GetBlue(),1e-8f);
// 
// 			++source;	
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::A1R5G5B5ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘A1R5G5B5
// 		vector<ColourConvertFrom::FloatColour> a1r5g5b5Colour(buffer.size() / 2);
// 
// 		ColourConvertFrom::ConvertFromA1R5G5B5(boost::numeric_cast<int>(a1r5g5b5Colour.size()),&buffer[0],&a1r5g5b5Colour[0]);
// 
// 		const unsigned short* source = reinterpret_cast<const unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < a1r5g5b5Colour.size(); ++i)
// 		{
// 			unsigned char red = static_cast<unsigned char>((*source & 0x7C00u) >> 10);
// 			unsigned char green = static_cast<unsigned char>((*source & 0x03E0u) >> 5);
// 			unsigned char blue = static_cast<unsigned char>(*source & 0x001Fu);
// 			unsigned char alpha = static_cast<unsigned char>((*source & 0x8000u) >> 15);
// 						
// 			TextureColour<TextureFormat::A1R5G5B5> textureColour(red,green,blue,alpha);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(a1r5g5b5Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(a1r5g5b5Colour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);
// 			ASSERT_APPROXIMATE(a1r5g5b5Colour[i].GetBlue(),floatTextureColour.GetBlue(),1e-8f);
// 			ASSERT_APPROXIMATE(a1r5g5b5Colour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-8f);
// 
// 			++source;	
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::A4R4G4B4ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘A4R4G4B4
// 		vector<ColourConvertFrom::FloatColour> a4r4g4b4Colour(buffer.size() / 2);
// 
// 		ColourConvertFrom::ConvertFromA4R4G4B4(boost::numeric_cast<int>(a4r4g4b4Colour.size()),&buffer[0],&a4r4g4b4Colour[0]);
// 
// 		const unsigned short* source = reinterpret_cast<const unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < a4r4g4b4Colour.size(); ++i)
// 		{
// 			unsigned char red = static_cast<unsigned char>((*source & 0x0F00u) >> 8);
// 			unsigned char green = static_cast<unsigned char>((*source & 0x00F0u) >> 4);
// 			unsigned char blue = static_cast<unsigned char>(*source & 0x000Fu);
// 			unsigned char alpha = static_cast<unsigned char>((*source & 0xF000u) >> 12);
// 						
// 			TextureColour<TextureFormat::A4R4G4B4> textureColour(red,green,blue,alpha);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(a4r4g4b4Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(a4r4g4b4Colour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);
// 			ASSERT_APPROXIMATE(a4r4g4b4Colour[i].GetBlue(),floatTextureColour.GetBlue(),1e-8f);
// 			ASSERT_APPROXIMATE(a4r4g4b4Colour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-8f);
// 
// 			++source;	
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::A8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘A8
// 		vector<ColourConvertFrom::FloatColour> a8Colour(buffer.size());
// 
// 		ColourConvertFrom::ConvertFromA8(boost::numeric_cast<int>(a8Colour.size()),&buffer[0],&a8Colour[0]);
// 
// 		const unsigned char* source = reinterpret_cast<const unsigned char*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < a8Colour.size(); ++i)
// 		{
// 			unsigned char alpha = *source;
// 
// 			TextureColour<TextureFormat::A8R8G8B8> textureColour(0,0,0,alpha);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(a8Colour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-8f);
// 
// 			++source;	
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::L8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘L8
// 		vector<ColourConvertFrom::FloatColour> l8Colour(buffer.size());
// 
// 		ColourConvertFrom::ConvertFromL8(boost::numeric_cast<int>(l8Colour.size()),&buffer[0],&l8Colour[0]);
// 
// 		const unsigned char* source = reinterpret_cast<const unsigned char*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < l8Colour.size(); ++i)
// 		{
// 			unsigned char luminance = *source;
// 
// 			TextureColour<TextureFormat::A8R8G8B8> textureColour(luminance,0,0,0);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(l8Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 
// 			++source;	
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::A8L8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘A8L8
// 		vector<ColourConvertFrom::FloatColour> a8l8Colour(buffer.size() / 2);
// 
// 		ColourConvertFrom::ConvertFromA8L8(boost::numeric_cast<int>(a8l8Colour.size()),&buffer[0],&a8l8Colour[0]);
// 
// 		const unsigned char* source = reinterpret_cast<const unsigned char*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < a8l8Colour.size(); ++i)
// 		{ 
// 			unsigned char luminance = *source++;
// 			unsigned char alpha = *source++;
// 
// 			TextureColour<TextureFormat::A8R8G8B8> textureColour(luminance,0,0,alpha);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(a8l8Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(a8l8Colour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-8f);
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::R8G8B8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘R8G8B8
// 		vector<ColourConvertFrom::FloatColour> r8g8b8Colour(buffer.size() / 3);
// 
// 		ColourConvertFrom::ConvertFromR8G8B8(boost::numeric_cast<int>(r8g8b8Colour.size()),  &buffer[0],&r8g8b8Colour[0]);
// 
// 		const unsigned char* source =  reinterpret_cast<const unsigned char*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < r8g8b8Colour.size(); ++i)
// 		{ 
// 			unsigned char blue = *source++;
// 			unsigned char green = *source++;
// 			unsigned char red = *source++;
// 
// 			TextureColour<TextureFormat::R8G8B8> textureColour(red,green,blue);
// 			TextureColour<TextureFormat::A32B32G32R32F>  floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(r8g8b8Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(r8g8b8Colour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);
// 			ASSERT_APPROXIMATE(r8g8b8Colour[i].GetBlue(),floatTextureColour.GetBlue(),1e-8f);
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::A8R8G8B8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘A8R8G8B8
// 		vector<ColourConvertFrom::FloatColour> a8r8g8b8Colour(buffer.size() / 4);
// 
// 		ColourConvertFrom::ConvertFromA8R8G8B8(boost::numeric_cast<int>(a8r8g8b8Colour.size()), &buffer[0],&a8r8g8b8Colour[0]);
// 
// 		const unsigned char* source = reinterpret_cast<const unsigned char*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < a8r8g8b8Colour.size(); ++i)
// 		{ 
// 			unsigned char blue = *source++;
// 			unsigned char green = *source++;
// 			unsigned char red = *source++;
// 			unsigned char alpha = *source++;
// 
// 			TextureColour<TextureFormat::A8R8G8B8> textureColour(red,green,blue,alpha);
// 			TextureColour<TextureFormat::A32B32G32R32F> 
// 				floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(a8r8g8b8Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(a8r8g8b8Colour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);
// 			ASSERT_APPROXIMATE(a8r8g8b8Colour[i].GetBlue(),floatTextureColour.GetBlue(),1e-8f);
// 			ASSERT_APPROXIMATE(a8r8g8b8Colour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-8f);
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::A8B8G8R8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘A8B8G8R8
// 		vector<ColourConvertFrom::FloatColour> a8b8g8r8Colour(buffer.size() / 4);
// 
// 		ColourConvertFrom::ConvertFromA8B8G8R8(boost::numeric_cast<int>(a8b8g8r8Colour.size()),
// 			                                   &buffer[0],&a8b8g8r8Colour[0]);
// 
// 		const unsigned char* source = reinterpret_cast<const unsigned char*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < a8b8g8r8Colour.size(); ++i)
// 		{ 
// 			unsigned char red = *source++;
// 			unsigned char green = *source++;
// 			unsigned char blue = *source++;
// 			unsigned char alpha = *source++;
// 
// 			TextureColour<TextureFormat::A8B8G8R8> textureColour(red,green,blue,alpha);
// 			TextureColour<TextureFormat::A32B32G32R32F> 
// 				floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(a8b8g8r8Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(a8b8g8r8Colour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);
// 			ASSERT_APPROXIMATE(a8b8g8r8Colour[i].GetBlue(),floatTextureColour.GetBlue(),1e-8f);
// 			ASSERT_APPROXIMATE(a8b8g8r8Colour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-8f);
// 		}
	/*}*/
}

void Rendering::ColourConvertFromTesting
	::L16ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘L16
// 		vector<ColourConvertFrom::FloatColour> l16Colour(buffer.size() / 2);
// 
// 		ColourConvertFrom::ConvertFromL16(boost::numeric_cast<int>(l16Colour.size()), &buffer[0],&l16Colour[0]);
// 
// 		const unsigned short* source = reinterpret_cast<const unsigned short*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < l16Colour.size(); ++i)
// 		{
// 			unsigned short luminance = *source;
// 
// 			TextureColour<TextureFormat::A16B16G16R16> textureColour(luminance,0,0,0);
// 			TextureColour<TextureFormat::A32B32G32R32F> 
// 				floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(l16Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 
// 			++source;	
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::G16R16ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘G16R16
// 		vector<ColourConvertFrom::FloatColour> g16r16Colour(buffer.size() / 4);
// 
// 		ColourConvertFrom::ConvertFromG16R16(boost::numeric_cast<int>(g16r16Colour.size()), &buffer[0],&g16r16Colour[0]);
// 
// 		const unsigned short* source = reinterpret_cast<const unsigned short*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < g16r16Colour.size(); ++i)
// 		{
// 			unsigned short red = *source++;
// 			unsigned short green = *source++;
// 
// 			TextureColour<TextureFormat::A16B16G16R16> textureColour(red,green,0,0);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(g16r16Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(g16r16Colour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);			
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::A16B16G16R16ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<char> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(integerRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘A16B16G16R16
// 		vector<ColourConvertFrom::FloatColour> a16b16g16r16Colour(buffer.size() / 8);
// 
// 		ColourConvertFrom::ConvertFromA16B16G16R16(boost::numeric_cast<int>(a16b16g16r16Colour.size()),
// 			                                       &buffer[0],&a16b16g16r16Colour[0]);
// 
// 		const unsigned short* source = reinterpret_cast<const unsigned short*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < a16b16g16r16Colour.size(); ++i)
// 		{
// 			unsigned short red = *source++;
// 			unsigned short green = *source++;
// 			unsigned short blue = *source++;
// 			unsigned short alpha = *source++;
// 
// 			TextureColour<TextureFormat::A16B16G16R16> textureColour(red,green,blue,alpha);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(a16b16g16r16Colour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);
// 			ASSERT_APPROXIMATE(a16b16g16r16Colour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);			
// 			ASSERT_APPROXIMATE(a16b16g16r16Colour[i].GetBlue(),floatTextureColour.GetBlue(),1e-8f);
// 			ASSERT_APPROXIMATE(a16b16g16r16Colour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-8f);			
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::R16FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<unsigned short> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(HalfFloat(floatRandomDistribution(generator)).ToHalfFloat());
// 		}
// 
// 		// ≤‚ ‘R16F
// 		vector<ColourConvertFrom::FloatColour> r16fColour(buffer.size());
// 
// 		ColourConvertFrom::ConvertFromR16F(boost::numeric_cast<int>(r16fColour.size()),
// 			                               reinterpret_cast<const char*>(&buffer[0]),
// 										   &r16fColour[0]);
// 
// 		const unsigned short* source = reinterpret_cast<const unsigned short*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < r16fColour.size(); ++i)
// 		{
// 			HalfFloat halfFloat;
// 			halfFloat.FromHalfFloatType(*source++);
// 
// 			TextureColour<TextureFormat::A16B16G16R16F> textureColour(halfFloat,HalfFloat(),HalfFloat(),HalfFloat());
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(r16fColour[i].GetRed(),floatTextureColour.GetRed(),1e-3f);	
// 		}
// 	}
}

void Rendering::ColourConvertFromTesting
	::G16R16FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<unsigned short> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(HalfFloat(floatRandomDistribution(generator)).ToHalfFloat());
// 		}
// 
// 		// ≤‚ ‘G16R16F
// 		vector<ColourConvertFrom::FloatColour> g16r16fColour(buffer.size() / 2);
// 
// 		ColourConvertFrom::ConvertFromG16R16F(boost::numeric_cast<int>(g16r16fColour.size()),
// 			                                  reinterpret_cast<const char*>(&buffer[0]),
// 										      &g16r16fColour[0]);
// 
// 		const unsigned short* source = reinterpret_cast<const unsigned short*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < g16r16fColour.size(); ++i)
// 		{
// 
// 			HalfFloat redHalfFloat;
// 			redHalfFloat.FromHalfFloatType(*source++);
// 	
// 			HalfFloat greenHalfFloat;
// 			greenHalfFloat.FromHalfFloatType(*source++); 
// 
// 			TextureColour<TextureFormat::A16B16G16R16F> textureColour(redHalfFloat, greenHalfFloat,HalfFloat(),HalfFloat());
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(g16r16fColour[i].GetRed(),floatTextureColour.GetRed(),1e-3f);	
// 			ASSERT_APPROXIMATE(g16r16fColour[i].GetGreen(),floatTextureColour.GetGreen(),1e-3f);
// 		}
// 	}

}

void Rendering::ColourConvertFromTesting
	::A16B16G16R16FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<unsigned short> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(HalfFloat(floatRandomDistribution(generator)).ToHalfFloat());
// 		}
// 
// 		// ≤‚ ‘A16B16G16R16F
// 		vector<ColourConvertFrom::FloatColour> a16b16g16r16fColour(buffer.size() / 4);
// 
// 		ColourConvertFrom::ConvertFromA16B16G16R16F(boost::numeric_cast<int>(a16b16g16r16fColour.size()),
// 			                                        reinterpret_cast<const char*>(&buffer[0]),
// 										            &a16b16g16r16fColour[0]);
// 
// 		const unsigned short* source = reinterpret_cast<const unsigned short*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < a16b16g16r16fColour.size(); ++i)
// 		{
// 			HalfFloat redHalfFloat;
// 			redHalfFloat.FromHalfFloatType(*source++);
// 	
// 			HalfFloat greenHalfFloat;
// 			greenHalfFloat.FromHalfFloatType(*source++); 
// 
// 			HalfFloat blueHalfFloat;
// 			blueHalfFloat.FromHalfFloatType(*source++); 
// 
// 			HalfFloat alphaHalfFloat;
// 			alphaHalfFloat.FromHalfFloatType(*source++);
// 
// 			TextureColour<TextureFormat::A16B16G16R16F> textureColour(redHalfFloat, greenHalfFloat, blueHalfFloat, alphaHalfFloat);
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(textureColour);
// 
// 			ASSERT_APPROXIMATE(a16b16g16r16fColour[i].GetRed(),floatTextureColour.GetRed(),1e-3f);	
// 			ASSERT_APPROXIMATE(a16b16g16r16fColour[i].GetGreen(),floatTextureColour.GetGreen(),1e-3f);
// 			ASSERT_APPROXIMATE(a16b16g16r16fColour[i].GetBlue(),floatTextureColour.GetBlue(),1e-3f);	
// 			ASSERT_APPROXIMATE(a16b16g16r16fColour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-3f);
// 		}
// 	}

}

void Rendering::ColourConvertFromTesting
	::R32FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<float> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(floatRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘R32F
// 		vector<ColourConvertFrom::FloatColour> r32fColour(buffer.size());
// 
// 		ColourConvertFrom::ConvertFromR32F(boost::numeric_cast<int>(r32fColour.size()),
// 			                               reinterpret_cast<const char*>(&buffer[0]),
// 										   &r32fColour[0]);
// 
// 		const float* source = 
// 			reinterpret_cast<const float*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < r32fColour.size(); ++i)
// 		{
// 			float red = *source++; 
// 
// 			TextureColour<TextureFormat::A32B32G32R32F> floatTextureColour(red,0.0f,0.0f,0.0f);
// 
// 			ASSERT_APPROXIMATE(r32fColour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);	
// 		}
// 	}

}

void Rendering::ColourConvertFromTesting
	::G32R32FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<float> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(floatRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘G32R32F
// 		vector<ColourConvertFrom::FloatColour> g32r32fColour(buffer.size() / 2);
// 
// 		ColourConvertFrom::ConvertFromG32R32F(boost::numeric_cast<int>(g32r32fColour.size()),
// 			                                  reinterpret_cast<const char*>(&buffer[0]),
// 										      &g32r32fColour[0]);
// 
// 		const float* source = reinterpret_cast<const float*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < g32r32fColour.size(); ++i)
// 		{
// 			float red = *source++; 
// 			float green = *source++; 
// 
// 			TextureColour<TextureFormat::A32B32G32R32F> 
// 				floatTextureColour(red,green,0.0f,0.0f);
// 
// 			ASSERT_APPROXIMATE(g32r32fColour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);	
// 			ASSERT_APPROXIMATE(g32r32fColour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);	
// 		}
// 	}

}

void Rendering::ColourConvertFromTesting
	::A32B32G32R32FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<float> buffer;
// 
// 		for (int i = 0;i < 16 * 3;++i)
// 		{
// 			buffer.push_back(floatRandomDistribution(generator));
// 		}
// 
// 		// ≤‚ ‘A32B32G32R32F
// 		vector<ColourConvertFrom::FloatColour> a32b32g32r32fColour(buffer.size() / 4);
// 
// 		ColourConvertFrom::ConvertFromA32B32G32R32F(boost::numeric_cast<int>(a32b32g32r32fColour.size()),
// 			                                        reinterpret_cast<const char*>(&buffer[0]),
// 								      		        &a32b32g32r32fColour[0]);
// 
// 		const float* source = reinterpret_cast<const float*>(&buffer[0]);
// 
// 		for (unsigned i = 0; i < a32b32g32r32fColour.size(); ++i)
// 		{
// 			float red = *source++; 
// 			float green = *source++; 
// 			float blue = *source++; 
// 			float alpha = *source++; 
// 
// 			TextureColour<TextureFormat::A32B32G32R32F> 
// 				floatTextureColour(red,green, blue, alpha);
// 
// 			ASSERT_APPROXIMATE(a32b32g32r32fColour[i].GetRed(),floatTextureColour.GetRed(),1e-8f);	
// 			ASSERT_APPROXIMATE(a32b32g32r32fColour[i].GetGreen(),floatTextureColour.GetGreen(),1e-8f);
// 			ASSERT_APPROXIMATE(a32b32g32r32fColour[i].GetBlue(),floatTextureColour.GetBlue(),1e-8f);
// 			ASSERT_APPROXIMATE(a32b32g32r32fColour[i].GetAlpha(),floatTextureColour.GetAlpha(),1e-8f);
// 		}
// 	}

}
