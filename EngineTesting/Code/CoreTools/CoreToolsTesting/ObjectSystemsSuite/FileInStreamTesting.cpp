///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:40)

#include "FileInStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "Detail/NullObject.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/FileInStream.h"
#include "CoreTools/ObjectSystems/FileOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include <algorithm>

using std::min;
using std::string;
using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FileInStreamTesting)

void CoreTools::FileInStreamTesting::MainTest()
{
    InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(FileStreamTest);

    InitTerm::ExecuteTerminators();
}

void CoreTools::FileInStreamTesting::FileStreamTest() noexcept
{
}
