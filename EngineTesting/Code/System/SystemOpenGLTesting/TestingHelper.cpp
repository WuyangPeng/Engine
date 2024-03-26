/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 16:46)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

System::TestingHelper::TestingHelper(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, information, environmentDirectory }
{
    /// 构造未完成，不调用类不变式判断。
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TestingHelper)
