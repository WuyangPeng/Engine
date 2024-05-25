/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/19 20:40)

#include "BufferOutStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
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
    const auto fileBuffer = GetBufferInformation();

    const BufferInStream bufferInStream{ fileBuffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL(inTopLevel.GetTopLevelSize(), 4);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferOutStreamTesting::GetBufferInformation()
{
    auto outTopLevel = OutTopLevel::Create();

    outTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<NullObject>(DisableNotThrow::Disable));

    const BufferOutStream bufferOutStream{ outTopLevel };

    return bufferOutStream.GetBufferOutStreamInformation();
}
