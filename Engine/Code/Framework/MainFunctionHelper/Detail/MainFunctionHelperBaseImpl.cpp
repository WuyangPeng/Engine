///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 15:21)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBaseImpl.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::MainFunctionHelperBaseImpl::MainFunctionHelperBaseImpl(const EnvironmentDirectory& environmentDirectory) noexcept
    : environmentDirectory{ environmentDirectory }
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