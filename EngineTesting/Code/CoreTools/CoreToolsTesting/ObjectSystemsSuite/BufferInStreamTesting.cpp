///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/18 16:12)

#include "BufferInStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::BufferInStreamTesting::BufferInStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferInStreamTesting)

void CoreTools::BufferInStreamTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::BufferInStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BufferInStreamTest);
}

void CoreTools::BufferInStreamTesting::BufferInStreamTest()
{
    const auto fileBuffer = GetBufferInformation();

    const BufferInStream bufferInStream{ fileBuffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 3, "top level ��С����");

    std::vector<ObjectInterfaceSharedPtr> objects{};
    for (const auto& value : inTopLevel)
    {
        ASSERT_TRUE(inTopLevel.IsTopLevel(value));
        objects.emplace_back(value);
    }

    ASSERT_TRUE(objects.at(0)->IsExactly(BoolObject::GetCurrentRttiType()));
    ASSERT_TRUE(objects.at(1)->IsExactly(EnumObject::GetCurrentRttiType()));
    ASSERT_TRUE(objects.at(2)->IsExactly(IntObject::GetCurrentRttiType()));
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferInStreamTesting::GetBufferInformation() const
{
    auto outTopLevel = OutTopLevel::Create();

    outTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));

    const BufferOutStream bufferOutStream{ outTopLevel };

    return bufferOutStream.GetBufferOutStreamInformation();
}
