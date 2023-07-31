///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 18:07)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

SoundEffectExample::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��Ч����"s }
{
    InitSuite();

    SOUND_EFFECT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(SoundEffectExample, TestingHelper)

void SoundEffectExample::TestingHelper::InitSuite() noexcept
{
}
