///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:40)

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
