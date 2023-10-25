///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:15)

#include "BufferOutStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::BufferOutStreamTesting::BufferOutStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferOutStreamTesting)

void CoreTools::BufferOutStreamTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::BufferOutStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BufferOutStreamTest);
}

void CoreTools::BufferOutStreamTesting::BufferOutStreamTest()
{
    auto outTopLevel = OutTopLevel::Create();

    outTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<NullObject>(DisableNotThrow::Disable));

    const BufferOutStream bufferOutStream{ outTopLevel };

    const auto fileBuffer = bufferOutStream.GetBufferOutStreamInformation();

    const BufferInStream bufferInStream{ fileBuffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL(inTopLevel.GetTopLevelSize(), 4);
}
