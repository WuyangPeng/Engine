///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:24)

#include "InsideTheCppObjectModelConstructorTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/InsideTheCppObjectModel/Helper/InsideTheCppObjectModelClassInvariantMacro.h"
#include "Example/BookCpp/InsideTheCppObjectModel/Preface/Constructor.h"

BookAdvanced::InsideTheCppObjectModel::InsideTheCppObjectModelConstructorTesting::InsideTheCppObjectModelConstructorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    INSIDE_THE_CPP_OBJECT_MODEL_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::InsideTheCppObjectModel, InsideTheCppObjectModelConstructorTesting)

void BookAdvanced::InsideTheCppObjectModel::InsideTheCppObjectModelConstructorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::InsideTheCppObjectModel::InsideTheCppObjectModelConstructorTesting::MainTest()
{
    const Constructor constructor{};

    constructor.Main();
}
