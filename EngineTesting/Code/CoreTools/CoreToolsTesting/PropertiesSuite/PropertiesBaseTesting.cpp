// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:42)

#include "PropertiesBaseTesting.h" 
#include "Detail/PropertiesBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, PropertiesBaseTesting)

void CoreTools::PropertiesBaseTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::PropertiesBaseTesting
	::GetSetTest()
{
	PropertiesBase propertiesBase;

	ASSERT_EQUAL(propertiesBase.FifthValue, 0);

	propertiesBase.FifthValue = 1;

	ASSERT_EQUAL(propertiesBase.FifthValue, 1);
}


