// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 15:47)

#include "ShaderFloatTesting.h"
#include "Rendering/ShaderFloats/ShaderFloat.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h" 


using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ShaderFloatTesting) 

void Rendering::ShaderFloatTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers(); 

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest); 

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::ShaderFloatTesting
	::InitTest()
{
	const int firstNumRegisters = 5;
	ShaderFloat firstShaderFloat; 
	ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 0);

	firstShaderFloat.SetNumRegisters(firstNumRegisters);
	ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), firstNumRegisters);

	ASSERT_UNEQUAL_NULL_PTR(firstShaderFloat.GetData());

	ASSERT_TRUE(firstShaderFloat.AllowUpdater());
	firstShaderFloat.DisableUpdater();
	ASSERT_FALSE(firstShaderFloat.AllowUpdater());
	firstShaderFloat.EnableUpdater();
	ASSERT_TRUE(firstShaderFloat.AllowUpdater());

	vector<float> firstData(firstNumRegisters * 4,1);
	firstShaderFloat.SetRegisters(firstData);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(firstData, firstShaderFloat.GetRegisters());

	const int secondNumRegisters = 10;
	const ShaderFloat secondShaderFloat(secondNumRegisters);
	ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), secondNumRegisters);
	ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
	ASSERT_TRUE(secondShaderFloat.AllowUpdater());
	
	const int thirdNumRegisters = 6;
	vector<float> thirdData(thirdNumRegisters * 4);
	ShaderFloat thirdShaderFloat(thirdData);
	ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), thirdNumRegisters);

	ASSERT_UNEQUAL_NULL_PTR(thirdShaderFloat.GetData());

	ASSERT_TRUE(thirdShaderFloat.AllowUpdater());
	thirdShaderFloat.DisableUpdater();
	ASSERT_FALSE(thirdShaderFloat.AllowUpdater());
	thirdShaderFloat.EnableUpdater();
	ASSERT_TRUE(thirdShaderFloat.AllowUpdater());

	for (int i = 0; i < thirdNumRegisters;++i)
	{
		vector<float> fourthData(4, static_cast<float>(i));
		thirdShaderFloat.SetRegister(i,fourthData);

		vector<float> fifthData = thirdShaderFloat.GetRegister(i);

		for (int registerIndex = 0; registerIndex < 4;++registerIndex)
		{
			ASSERT_APPROXIMATE(thirdShaderFloat[i * 4 + registerIndex], static_cast<float>(i), 1e-8f);
			ASSERT_APPROXIMATE(fifthData[registerIndex], fourthData[registerIndex], 1e-8f);
		}
	}
}

void Rendering::ShaderFloatTesting
	::CopyTest()
{
	const int firstNumRegisters = 5;
	const int secondNumRegisters = 15;

	ShaderFloat firstShaderFloat; 
	ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 0);

	ShaderFloat secondShaderFloat(firstShaderFloat);
	ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), 0);

	firstShaderFloat.SetNumRegisters(firstNumRegisters);
	ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), firstNumRegisters);
	ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), 0);

	ShaderFloat thirdShaderFloat(secondNumRegisters);
	ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), secondNumRegisters);

	thirdShaderFloat = secondShaderFloat;
	ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), 0);

	secondShaderFloat = firstShaderFloat;
	ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), 0);
	ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), firstNumRegisters);
} 

void Rendering::ShaderFloatTesting
	::StreamTest()
{
// 	const int thirdNumRegisters = 10;
// 
// 	CoreTools::OutTopLevel outTopLevel;
// 	ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat(thirdNumRegisters));
// 
// 	for (int i = 0; i < thirdNumRegisters;++i)
// 	{
// 		vector<float> data(4, static_cast<float>(i));
// 		firstShaderFloat->SetRegister(i,data);
// 	}
// 
// 	outTopLevel.Insert(firstShaderFloat);	 
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 		    outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	ASSERT_EQUAL(inTopLevel.GetTopLevelSize(),1);
// 
// 	ShaderFloatSharedPtr secondShaderFloat = 
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<ShaderFloatSharedPtr>();
// 
// 	ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat);
// 
// 	ASSERT_EQUAL(firstShaderFloat->GetRegisters().size(),
// 		         secondShaderFloat->GetRegisters().size());
// 
// 	for (unsigned registerIndex = 0; registerIndex < firstShaderFloat->GetRegisters().size(); ++registerIndex)
// 	{
// 		ASSERT_APPROXIMATE(firstShaderFloat->GetRegisters()[registerIndex], 
// 			               secondShaderFloat->GetRegisters()[registerIndex], 1e-8f);
// 	}
}