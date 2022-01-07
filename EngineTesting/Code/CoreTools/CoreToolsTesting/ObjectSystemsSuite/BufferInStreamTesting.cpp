// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:16)

#include "BufferInStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/IntObject.h"
#include "Detail/EnumObject.h"
#include "Detail/StringObject.h"
#include "Detail/PointerObject.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"

#include "CoreTools/Helper/AssertMacro.h"

#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BufferInStreamTesting)

void CoreTools::BufferInStreamTesting
	::MainTest()
{
	InitTerm::ExecuteInitializers();


	InitTerm::ExecuteTerminators();
}
