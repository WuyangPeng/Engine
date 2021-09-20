///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "CppEffectiveObjectOrientedSoftwareConstructionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppEffectiveObjectOrientedSoftwareConstruction/Helper/CppEffectiveObjectOrientedSoftwareConstructionClassInvariantMacro.h"

BookIntermediate::CppEffectiveObjectOrientedSoftwareConstruction::CppEffectiveObjectOrientedSoftwareConstructionPlaceholderTesting::CppEffectiveObjectOrientedSoftwareConstructionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::CppEffectiveObjectOrientedSoftwareConstruction, CppEffectiveObjectOrientedSoftwareConstructionPlaceholderTesting)

void BookIntermediate::CppEffectiveObjectOrientedSoftwareConstruction::CppEffectiveObjectOrientedSoftwareConstructionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::CppEffectiveObjectOrientedSoftwareConstruction::CppEffectiveObjectOrientedSoftwareConstructionPlaceholderTesting::MainTest() noexcept
{
}
