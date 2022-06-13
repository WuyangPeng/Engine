///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:39)

#include "BufferTargetTesting.h"
#include "Detail/BufferTargetTestingEnum.h"
#include "Detail/NullObject.h"
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

#include <vector>

using std::make_shared;
using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BufferTargetTesting)

void CoreTools::BufferTargetTesting::MainTest() noexcept
{
}