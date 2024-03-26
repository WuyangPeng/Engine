/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:47)

#include "OpenGLSamplersTestingBase.h"
#include "System/OpenGL/OpenGLSamplers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLSamplersTestingBase::OpenGLSamplersTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLSamplersTestingBase)

void System::OpenGLSamplersTestingBase::DeleteSamplerTest(OpenGLInt sampler) const noexcept
{
    SetGLDeleteSamplers(sampler);
}

void System::OpenGLSamplersTestingBase::DeleteSamplersTest(const SamplersType& samplers) const noexcept
{
    SetGLDeleteSamplers(bufferSize, samplers.data());
}
