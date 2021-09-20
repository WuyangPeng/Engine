// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:27)

#include "FileInStreamTesting.h"
#include "Detail/NullObject.h"
#include "Detail/BoolObject.h"
#include "Detail/IntObject.h"
#include "Detail/EnumObject.h"
#include "Detail/StringObject.h"
#include "Detail/PointerObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/FileOutStream.h"
#include "CoreTools/ObjectSystems/FileInStream.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"

#include <algorithm>

using std::string;
using std::min;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace CoreTools
{
	const auto fileName = SYSTEM_TEXT("FileInStream.txt"s);
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FileInStreamTesting)

void CoreTools::FileInStreamTesting
	::MainTest()
{
	InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(FileStreamTest);

	InitTerm::ExecuteTerminators();
}

void CoreTools::FileInStreamTesting
	::FileStreamTest() noexcept
{
	 
}

