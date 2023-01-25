///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/12 22:47)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

System::TestingHelper::TestingHelper(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, information, environmentDirectory }
{
    // ����δ��ɣ��������಻��ʽ�жϡ�
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TestingHelper)
