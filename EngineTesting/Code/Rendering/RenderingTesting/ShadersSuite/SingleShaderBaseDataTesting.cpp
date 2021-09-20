// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:33)

#include "SingleShaderBaseDataTesting.h"
#include "Rendering/Shaders/SingleShaderBaseData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SingleShaderBaseDataTesting) 

void Rendering::SingleShaderBaseDataTesting
	::MainTest()
{ 
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
}
 
void Rendering::SingleShaderBaseDataTesting
	::InitTest()
{
	 SingleShaderBaseData firstSingleShaderBaseData;

	 ASSERT_EQUAL(firstSingleShaderBaseData.GetName(),"");
	 ASSERT_ENUM_EQUAL(firstSingleShaderBaseData.GetType(),ShaderFlags::VariableType::None);
	 ASSERT_ENUM_EQUAL(firstSingleShaderBaseData.GetSemantic(),ShaderFlags::VariableSemantic::None);

	 firstSingleShaderBaseData.SetData("TestData",ShaderFlags::VariableType::Half,ShaderFlags::VariableSemantic::Color1);

	 ASSERT_EQUAL(firstSingleShaderBaseData.GetName(),"TestData");
	 ASSERT_ENUM_EQUAL(firstSingleShaderBaseData.GetType(),ShaderFlags::VariableType::Half);
	 ASSERT_ENUM_EQUAL(firstSingleShaderBaseData.GetSemantic(),ShaderFlags::VariableSemantic::Color1);

	 SingleShaderBaseData secondSingleShaderBaseData("SingleShaderBaseData",ShaderFlags::VariableType::Float3X1,ShaderFlags::VariableSemantic::BlendWeight);

	 ASSERT_EQUAL(secondSingleShaderBaseData.GetName(),"SingleShaderBaseData");
	 ASSERT_ENUM_EQUAL(secondSingleShaderBaseData.GetType(),ShaderFlags::VariableType::Float3X1);
	 ASSERT_ENUM_EQUAL(secondSingleShaderBaseData.GetSemantic(),ShaderFlags::VariableSemantic::BlendWeight);
}

void Rendering::SingleShaderBaseDataTesting
	::CopyTest()
{
	SingleShaderBaseData firstSingleShaderBaseData("SingleShaderBaseData",ShaderFlags::VariableType::Int3X4,ShaderFlags::VariableSemantic::TextureCoord4);
	SingleShaderBaseData secondSingleShaderBaseData(firstSingleShaderBaseData);

	ASSERT_EQUAL(secondSingleShaderBaseData.GetName(),firstSingleShaderBaseData.GetName());
	ASSERT_ENUM_EQUAL(secondSingleShaderBaseData.GetType(),firstSingleShaderBaseData.GetType());
	ASSERT_ENUM_EQUAL(secondSingleShaderBaseData.GetSemantic(),firstSingleShaderBaseData.GetSemantic());

	secondSingleShaderBaseData.SetData("SecondSingleShaderBaseData",ShaderFlags::VariableType::Fixed4,ShaderFlags::VariableSemantic::TextureCoord2);

	ASSERT_EQUAL(firstSingleShaderBaseData.GetName(),"SingleShaderBaseData");
	ASSERT_ENUM_EQUAL(firstSingleShaderBaseData.GetType(),ShaderFlags::VariableType::Int3X4);
	ASSERT_ENUM_EQUAL(firstSingleShaderBaseData.GetSemantic(),ShaderFlags::VariableSemantic::TextureCoord4);
	ASSERT_EQUAL(secondSingleShaderBaseData.GetName(),"SecondSingleShaderBaseData");
	ASSERT_ENUM_EQUAL(secondSingleShaderBaseData.GetType(),ShaderFlags::VariableType::Fixed4);
	ASSERT_ENUM_EQUAL(secondSingleShaderBaseData.GetSemantic(),ShaderFlags::VariableSemantic::TextureCoord2);

	SingleShaderBaseData thirdSingleShaderBaseData("ThirdSingleShaderBaseData",ShaderFlags::VariableType::Fixed2,ShaderFlags::VariableSemantic::Position);

	firstSingleShaderBaseData = thirdSingleShaderBaseData;
	ASSERT_EQUAL(thirdSingleShaderBaseData.GetName(),firstSingleShaderBaseData.GetName());
	ASSERT_ENUM_EQUAL(thirdSingleShaderBaseData.GetType(),firstSingleShaderBaseData.GetType());
	ASSERT_ENUM_EQUAL(thirdSingleShaderBaseData.GetSemantic(),firstSingleShaderBaseData.GetSemantic());

	firstSingleShaderBaseData.SetData("FirstSingleShaderBaseData",ShaderFlags::VariableType::Half3X1,ShaderFlags::VariableSemantic::BlendIndices);
	
	ASSERT_EQUAL(firstSingleShaderBaseData.GetName(),"FirstSingleShaderBaseData");
	ASSERT_ENUM_EQUAL(firstSingleShaderBaseData.GetType(),ShaderFlags::VariableType::Half3X1);
	ASSERT_ENUM_EQUAL(firstSingleShaderBaseData.GetSemantic(),ShaderFlags::VariableSemantic::BlendIndices);
	ASSERT_EQUAL(thirdSingleShaderBaseData.GetName(),"ThirdSingleShaderBaseData");
	ASSERT_ENUM_EQUAL(thirdSingleShaderBaseData.GetType(),ShaderFlags::VariableType::Fixed2);
	ASSERT_ENUM_EQUAL(thirdSingleShaderBaseData.GetSemantic(),ShaderFlags::VariableSemantic::Position);
}
