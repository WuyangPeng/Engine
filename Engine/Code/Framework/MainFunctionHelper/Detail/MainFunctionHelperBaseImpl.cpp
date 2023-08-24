///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:40)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBaseImpl.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::MainFunctionHelperBaseImpl::MainFunctionHelperBaseImpl(EnvironmentDirectory environmentDirectory) noexcept
    : environmentDirectory{ std::move(environmentDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, MainFunctionHelperBaseImpl);

System::String Framework::MainFunctionHelperBaseImpl::GetEngineInstallationDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    // Ӧ�ò�������Ŀ¼�ṹ�����Ŀ⡣
    // ����Ҫ����EnvironmentDirectory�����õĻ�������������Ӧ�ó�����Ҹ��������ļ���
    // EnvironmentDirectory���õ�ֵ���Դ������ж�ȡ����ֱ��ʹ��Ĭ��ֵ��
    return environmentDirectory.GetEngineDirectory();
}

Framework::EnvironmentDirectory Framework::MainFunctionHelperBaseImpl::GetEnvironmentDirectory() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return environmentDirectory;
}