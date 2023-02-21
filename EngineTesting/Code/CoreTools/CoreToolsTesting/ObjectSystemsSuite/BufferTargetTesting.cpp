///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:39)

#include "BufferTargetTesting.h"
#include "Detail/BufferTargetTestingEnum.h" 
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <vector>

using std::make_shared;
using std::string;
using std::vector;

CoreTools::BufferTargetTesting::BufferTargetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferTargetTesting)

void CoreTools::BufferTargetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BufferTargetTesting::MainTest() noexcept
{
}