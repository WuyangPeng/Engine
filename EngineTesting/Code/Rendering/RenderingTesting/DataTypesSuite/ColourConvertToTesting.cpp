// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 14:58)

#include "ColourConvertToTesting.h"
#include "Rendering/DataTypes/ColourConvertTo.h"
#include "Rendering/DataTypes/ColourTextureFormatTraits.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,ColourConvertToTesting) 
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::ColourConvertToTesting
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
 
void Rendering::ColourConvertToTesting
	::R5G6B5ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 2);
// 
// 		ColourConvertTo::ConvertToR5G6B5(boost::numeric_cast<int>(colour.size()),
// 			                             &colour[0],&buffer[0]);
// 
// 		unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned short red = static_cast<unsigned short>(colour[i].GetRed() *
//                                                              ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_RedMaxValue +
//                                                              0.5f);
//         
//             unsigned short green = static_cast<unsigned short>(colour[i].GetGreen() *
//                                                                ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_GreenMaxValue +
//                                                                0.5f);
//         
//             unsigned short blue = static_cast<unsigned short>(colour[i].GetBlue() *
//                                                               ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_BlueMaxValue +
//                                                               0.5f);
// 
//             unsigned short value = blue | (green << 5) | (red << 11);
//    
//             ASSERT_EQUAL(value,*target);        
//        
//             ++target;
// 		}
// 	}
}

void Rendering::ColourConvertToTesting
	::A1R5G5B5ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 2);
// 
// 		ColourConvertTo::ConvertToA1R5G5B5(boost::numeric_cast<int>(colour.size()),
// 			                               &colour[0],&buffer[0]);
// 
// 		unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned short red = static_cast<unsigned short>(colour[i].GetRed() *
//                                                              ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_RedMaxValue +
//                                                              0.5f);
//         
//             unsigned short green = static_cast<unsigned short>(colour[i].GetGreen() *
//                                                                ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_GreenMaxValue +
//                                                                0.5f);
//         
//             unsigned short blue = static_cast<unsigned short>(colour[i].GetBlue() *
//                                                               ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_BlueMaxValue +
//                                                               0.5f);
// 
//             unsigned short alpha = static_cast<unsigned short>(colour[i].GetAlpha() *
//                                                                ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_AlphaMaxValue +
//                                                                0.5f);
// 
//             unsigned short value = blue | (green << 5) | (red << 10) | (alpha << 15);
//    
//             ASSERT_EQUAL(value,*target);        
//        
//             ++target;
// 		}
// 
// 	}
}

void Rendering::ColourConvertToTesting
	::A4R4G4B4ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 2);
// 
// 		ColourConvertTo::ConvertToA4R4G4B4(boost::numeric_cast<int>(colour.size()),
// 			                               &colour[0],&buffer[0]);
// 
// 		unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned short red = static_cast<unsigned short>(colour[i].GetRed() *
//                                                              ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_RedMaxValue +
//                                                              0.5f);
//         
//             unsigned short green = static_cast<unsigned short>(colour[i].GetGreen() *
//                                                                ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_GreenMaxValue +
//                                                                0.5f);
//         
//             unsigned short blue = static_cast<unsigned short>(colour[i].GetBlue() *
//                                                               ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_BlueMaxValue +
//                                                               0.5f);
// 
//             unsigned short alpha = static_cast<unsigned short>(colour[i].GetAlpha() *
//                                                                ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_AlphaMaxValue +
//                                                                0.5f);
// 
//             unsigned short value = blue | (green << 4) | (red << 8) | (alpha << 12);
//    
//             ASSERT_EQUAL(value,*target);        
//        
//             ++target;
// 		}
// 	}
}

void Rendering::ColourConvertToTesting
	::A8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size());
// 
// 		ColourConvertTo::ConvertToA8(boost::numeric_cast<int>(colour.size()),
// 			                         &colour[0],&buffer[0]);
// 
// 		unsigned char* target = reinterpret_cast<unsigned char*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned char alpha = static_cast<unsigned char>(colour[i].GetAlpha() *
//                                                              ColourTextureFormatTraits<TextureFormat::A8>::sm_AlphaMaxValue +
//                                                              0.5f);
//    
//             ASSERT_EQUAL(alpha,*target);        
//        
//             ++target;
// 		}
// 	}
}

void Rendering::ColourConvertToTesting
	::L8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size());
// 
// 		ColourConvertTo::ConvertToL8(boost::numeric_cast<int>(colour.size()),
// 			                         &colour[0],&buffer[0]);
// 
// 		unsigned char* target = reinterpret_cast<unsigned char*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned char red = static_cast<unsigned char>(colour[i].GetRed() *
//                                                            ColourTextureFormatTraits<TextureFormat::L8>::sm_LuminanceMaxValue +
//                                                            0.5f);
//    
//             ASSERT_EQUAL(red,*target);        
//        
//             ++target;
// 
// 		}
// 	}
}

void Rendering::ColourConvertToTesting
	::A8L8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 2);
// 
// 		ColourConvertTo::ConvertToA8L8(boost::numeric_cast<int>(colour.size()),
// 			                           &colour[0],&buffer[0]);
// 
// 		unsigned char* target = reinterpret_cast<unsigned char*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned char red = static_cast<unsigned char>(colour[i].GetRed() *
//                                                            ColourTextureFormatTraits<TextureFormat::A8L8>::sm_LuminanceMaxValue +
//                                                            0.5f);
// 
//    
//             ASSERT_EQUAL(red,*target++);        
//        
//             unsigned char alpha = static_cast<unsigned char>(colour[i].GetAlpha() *
//                                                              ColourTextureFormatTraits<TextureFormat::A8L8>::sm_AlphaMaxValue +
//                                                              0.5f);
// 
//             ASSERT_EQUAL(alpha,*target++);  
// 		}
// 
// 	}
}

void Rendering::ColourConvertToTesting
	::R8G8B8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int k = 0;k < 16;++k)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 
// 		vector<char> buffer(colour.size() * 3);
// 
// 		ColourConvertTo::ConvertToR8G8B8(boost::numeric_cast<int>(colour.size()),
// 			                             &colour[0],&buffer[0]);
// 
// 		unsigned char* target = reinterpret_cast<unsigned char*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
// 
//             unsigned char blue = static_cast<unsigned char>(colour[i].GetBlue() *
//                                                             ColourTextureFormatTraits<TextureFormat::R8G8B8>::sm_RedMaxValue +
//                                                             0.5f);
// 
//    
//             ASSERT_EQUAL(blue,*target++); 
// 
//             unsigned char green = static_cast<unsigned char>(colour[i].GetGreen() *
//                                                              ColourTextureFormatTraits<TextureFormat::R8G8B8>::sm_GreenMaxValue +
//                                                              0.5f);
// 
//    
//             ASSERT_EQUAL(green,*target++); 
// 
//             unsigned char red = static_cast<unsigned char>(colour[i].GetRed() *
//                                                            ColourTextureFormatTraits<TextureFormat::R8G8B8>::sm_RedMaxValue +
//                                                            0.5f);
// 
//    
//             ASSERT_EQUAL(red,*target++);         
// 
// 		}
// 
// 		}

	/*}*/
}

void Rendering::ColourConvertToTesting
	::A8R8G8B8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 4);
// 
// 		ColourConvertTo::ConvertToA8R8G8B8(boost::numeric_cast<int>(colour.size()),
// 			                               &colour[0],&buffer[0]);
// 
// 		unsigned char* target = reinterpret_cast<unsigned char*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
// 
//             unsigned char blue = static_cast<unsigned char>(colour[i].GetBlue() *
//                                                             ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::sm_RedMaxValue +
//                                                             0.5f);
// 
//    
//             ASSERT_EQUAL(blue,*target++); 
// 
//             unsigned char green = static_cast<unsigned char>(colour[i].GetGreen() *
//                                                              ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::sm_GreenMaxValue +
//                                                              0.5f);
// 
//    
//             ASSERT_EQUAL(green,*target++); 
// 
//             unsigned char red = static_cast<unsigned char>(colour[i].GetRed() *
//                                                            ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::sm_RedMaxValue +
//                                                            0.5f);
// 
//    
//             ASSERT_EQUAL(red,*target++);        
// 
//             unsigned char alpha = static_cast<unsigned char>(colour[i].GetAlpha() *
//                                                              ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::sm_AlphaMaxValue +
//                                                              0.5f);
// 
//             ASSERT_EQUAL(alpha,*target++);  
// 
// 		}
// 	}
}

void Rendering::ColourConvertToTesting
	::A8B8G8R8ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 			
// 			vector<char> buffer(colour.size() * 4);
// 			
// 			ColourConvertTo::ConvertToA8B8G8R8(boost::numeric_cast<int>(colour.size()),
// 			                                   &colour[0],&buffer[0]);
// 
// 		unsigned char* target = reinterpret_cast<unsigned char*>(&buffer[0]);
//  
// 		for (unsigned k = 0; k < colour.size(); ++k)
// 		{
// 
//             unsigned char red = static_cast<unsigned char>(colour[k].GetRed() *
//                                                            ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::sm_RedMaxValue +
//                                                            0.5f);
// 
//    
//             ASSERT_EQUAL(red,*target++);   
// 
//             unsigned char green = static_cast<unsigned char>(colour[k].GetGreen() *
//                                                              ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::sm_GreenMaxValue +
//                                                              0.5f);
// 
//    
//             ASSERT_EQUAL(green,*target++); 
// 
// 
//             unsigned char blue = static_cast<unsigned char>(colour[k].GetBlue() *
//                                                             ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::sm_RedMaxValue +
//                                                             0.5f);
// 
//    
//             ASSERT_EQUAL(blue,*target++); 
//      
//             unsigned char alpha = static_cast<unsigned char>(colour[k].GetAlpha() *
//                                                              ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::sm_AlphaMaxValue +
//                                                              0.5f);
// 
//             ASSERT_EQUAL(alpha,*target++);  
// 		}
// 		}
// 	}
}

void Rendering::ColourConvertToTesting
	::L16ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 			
// 			vector<char> buffer(colour.size() * 2);
// 			
// 			ColourConvertTo::ConvertToL16(boost::numeric_cast<int>(colour.size()),
// 				                          &colour[0],&buffer[0]);
// 			
// 			unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 			for (unsigned k = 0; k < colour.size(); ++k)
// 			{
// 				unsigned short red = static_cast<unsigned short>(colour[k].GetRed() *
//                                                                  ColourTextureFormatTraits<TextureFormat::L16>::sm_LuminanceMaxValue +
//                                                                  0.5f);
// 				
// 				ASSERT_EQUAL(red,*target);  
// 				
// 				
// 				++target;
// 			}
// 		}
// 	}
}

void Rendering::ColourConvertToTesting
	::G16R16ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 4);
// 
// 		ColourConvertTo::ConvertToG16R16(boost::numeric_cast<int>(colour.size()),
// 			                             &colour[0],&buffer[0]);
// 
// 		unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned short red = static_cast<unsigned short>(colour[i].GetRed() *
//                                                              ColourTextureFormatTraits<TextureFormat::G16R16>::sm_RedMaxValue +
//                                                              0.5f);
//    
//             ASSERT_EQUAL(red,*target++);        
//        
//             unsigned short green = static_cast<unsigned short>(colour[i].GetGreen() *
//                                                                ColourTextureFormatTraits<TextureFormat::G16R16>::sm_RedMaxValue +
//                                                                0.5f);
//    
//             ASSERT_EQUAL(green,*target++);  
// 		}
// 
// 	}
}

void Rendering::ColourConvertToTesting
	::A16B16G16R16ConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 8);
// 
// 		ColourConvertTo::ConvertToA16B16G16R16(boost::numeric_cast<int>(colour.size()),
// 			                                 &colour[0],&buffer[0]);
// 
// 		unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned short red = static_cast<unsigned short>(colour[i].GetRed() *
//                                                              ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_RedMaxValue +
//                                                              0.5f);
//    
//             ASSERT_EQUAL(red,*target++);        
//        
//             unsigned short green = static_cast<unsigned short>(colour[i].GetGreen() *
//                                                                ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_RedMaxValue +
//                                                                0.5f);
//    
//             ASSERT_EQUAL(green,*target++);  
// 
//             unsigned short blue = static_cast<unsigned short>(colour[i].GetBlue() *
//                                                               ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_BlueMaxValue +
//                                                               0.5f);
//    
//             ASSERT_EQUAL(blue,*target++); 
// 
//             unsigned short alpha = static_cast<unsigned short>(colour[i].GetAlpha() *
//                                                                ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_AlphaMaxValue +
//                                                                0.5f);
//    
//             ASSERT_EQUAL(alpha,*target++); 
// 		}

	/*}*/
}

void Rendering::ColourConvertToTesting
	::R16FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 2);
// 
// 		ColourConvertTo::ConvertToR16F(boost::numeric_cast<int>(colour.size()),
// 			                           &colour[0],&buffer[0]);
// 
// 		unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned short red = HalfFloat(colour[i].GetRed()).ToHalfFloat();
//    
//             ASSERT_EQUAL(red,*target);        
//        
//             ++target;
// 		}
// 
// 	}
}

void Rendering::ColourConvertToTesting
	::G16R16FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 4);
// 
// 		ColourConvertTo::ConvertToG16R16F(boost::numeric_cast<int>(colour.size()),
// 			                              &colour[0],&buffer[0]);
// 
// 		unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned short red = HalfFloat(colour[i].GetRed()).ToHalfFloat();
//    
//             ASSERT_EQUAL(red,*target++);        
//        
//             unsigned short green = HalfFloat(colour[i].GetGreen()).ToHalfFloat();
//    
//             ASSERT_EQUAL(green,*target++);  
// 		}
// 
// 	}
}

void Rendering::ColourConvertToTesting
	::A16B16G16R16FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 8);
// 
// 		ColourConvertTo::ConvertToA16B16G16R16F(boost::numeric_cast<int>(colour.size()),
// 			                                    &colour[0],&buffer[0]);
// 
// 		unsigned short* target = reinterpret_cast<unsigned short*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             unsigned short red = HalfFloat(colour[i].GetRed()).ToHalfFloat();
//    
//             ASSERT_EQUAL(red,*target++);        
//        
//             unsigned short green = HalfFloat(colour[i].GetGreen()).ToHalfFloat();
//    
//             ASSERT_EQUAL(green,*target++);  
// 
//             unsigned short blue = HalfFloat(colour[i].GetBlue()).ToHalfFloat();
//    
//             ASSERT_EQUAL(blue,*target++);        
//        
//             unsigned short alpha = HalfFloat(colour[i].GetAlpha()).ToHalfFloat();
//    
//             ASSERT_EQUAL(alpha,*target++); 
// 		}
// 
// 	}
}

void Rendering::ColourConvertToTesting
	::R32FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 4);
// 
// 		ColourConvertTo::ConvertToR32F(boost::numeric_cast<int>(colour.size()),
// 			                           &colour[0],&buffer[0]);
// 
// 		float* target = reinterpret_cast<float*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             float red = colour[i].GetRed();
//    
//             ASSERT_EQUAL(red,*target);        
//        
//             ++target;
// 		}
// 
// 	}
}

void Rendering::ColourConvertToTesting
	::G32R32FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 8);
// 
// 		ColourConvertTo::ConvertToG32R32F(boost::numeric_cast<int>(colour.size()),
// 			                              &colour[0],&buffer[0]);
// 
// 		float* target = reinterpret_cast<float*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             float red = colour[i].GetRed();
//    
//             ASSERT_EQUAL(red,*target++);      
// 
//             float green = colour[i].GetGreen();
//    
//             ASSERT_EQUAL(green,*target++);        
// 
// 		}
// 
// 	}
}

void Rendering::ColourConvertToTesting
	::A32B32G32R32FConvertTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		vector<ColourConvertTo::FloatColour> colour;
// 
// 		for (int i = 0;i < 16;++i)
// 		{			
// 			colour.push_back(ColourConvertTo::FloatColour(floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator),
// 												          floatRandomDistribution(generator)));
// 		}
// 
// 		vector<char> buffer(colour.size() * 16);
// 
// 		ColourConvertTo::ConvertToA32B32G32R32F(boost::numeric_cast<int>(colour.size()),
// 			                                    &colour[0],&buffer[0]);
// 
// 		float* target = reinterpret_cast<float*>(&buffer[0]);
//  
// 		for (unsigned i = 0; i < colour.size(); ++i)
// 		{
//             float red = colour[i].GetRed();
//    
//             ASSERT_EQUAL(red,*target++);      
// 
//             float green = colour[i].GetGreen();
//    
//             ASSERT_EQUAL(green,*target++);    
// 
//             float blue = colour[i].GetBlue();
//    
//             ASSERT_EQUAL(blue,*target++); 
// 
//             float alpha = colour[i].GetAlpha();
//    
//             ASSERT_EQUAL(alpha,*target++);     
// 
// 		}
// 
// 	}
}

