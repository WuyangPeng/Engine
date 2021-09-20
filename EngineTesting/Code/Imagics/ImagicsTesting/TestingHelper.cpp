// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 17:51)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Imagics, TestingHelper,"ÕºœÒ∑÷Œˆ")

// private
void Imagics::TestingHelper
	::AddSuites()
{
	AddMacroSuite(); 
	AddBinaryOperationsSuite();
	AddExtractionSuite();
	AddFiltersSuite();
	AddImagesSuite();
	AddRasterDrawingSuite();
	AddSegmentersSuite();
	AddOpenCVSuite();
}

void Imagics::TestingHelper
	::AddMacroSuite()
{
	ADD_TEST_BEGIN(macroSuite, "∫Í"); 

	ADD_TEST_END(macroSuite);
}

void Imagics::TestingHelper
	::AddBinaryOperationsSuite()
{
	ADD_TEST_BEGIN(binaryOperationsSuite, "‘ÀÀ„∑˚"); 

	ADD_TEST_END(binaryOperationsSuite);
}

void Imagics::TestingHelper
	::AddExtractionSuite()
{
	ADD_TEST_BEGIN(extractionSuite, "Ã·»°"); 

	ADD_TEST_END(extractionSuite);
}

void Imagics::TestingHelper
	::AddFiltersSuite()
{
	ADD_TEST_BEGIN(filtersSuite, "π˝¬À∆˜"); 

	ADD_TEST_END(filtersSuite);
}

void Imagics::TestingHelper
	::AddImagesSuite()
{
	ADD_TEST_BEGIN(imagesSuite, "Õº∆¨"); 

	ADD_TEST_END(imagesSuite);
}

void Imagics::TestingHelper
	::AddRasterDrawingSuite()
{
	ADD_TEST_BEGIN(rasterDrawingSuite, "π‚’§Õº"); 

	ADD_TEST_END(rasterDrawingSuite);
}

void Imagics::TestingHelper
	::AddSegmentersSuite()
{
	ADD_TEST_BEGIN(segmentersSuite, "œﬂ∂Œ"); 

	ADD_TEST_END(segmentersSuite);
}

void Imagics::TestingHelper
	::AddOpenCVSuite()
{
	ADD_TEST_BEGIN(openCVSuite, "OpenCV"); 

	ADD_TEST_END(openCVSuite);
}

