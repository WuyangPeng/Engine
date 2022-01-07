// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:20)

#include "MemoryTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"


#include <map>
#include <string>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MemoryTesting)

void CoreTools::MemoryTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array4DTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26440)
void CoreTools::MemoryTesting ::SingleTest()
{
     
}

void CoreTools::MemoryTesting ::Array1DTest()
{
     
}

void CoreTools::MemoryTesting ::Array2DTest()
{
   
}

void CoreTools::MemoryTesting ::Array3DTest()
{
    
}

void CoreTools::MemoryTesting ::Array4DTest()
{
     
}

#include STSTEM_WARNING_POP