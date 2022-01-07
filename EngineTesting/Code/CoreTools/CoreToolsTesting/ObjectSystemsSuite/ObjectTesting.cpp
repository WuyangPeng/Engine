// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:32)

#include "ObjectTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/StringObject.h"
#include "Detail/IntObject.h"
#include "Detail/EnumObject.h"
#include "Detail/NullObject.h"
#include "Detail/PointerObject.h"
#include "Detail/TestObject.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/AssertMacro.h"

#include "CoreTools/Helper/ClassInvariantMacro.h" 

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ObjectTesting)

void CoreTools::ObjectTesting
	::MainTest()
{
	ObjectManager::Create();

	 

	ObjectManager::Destroy();
}
 

