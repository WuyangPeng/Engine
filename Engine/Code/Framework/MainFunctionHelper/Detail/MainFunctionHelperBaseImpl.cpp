// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/20 11:52)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBaseImpl.h"
#include "CoreTools/FileManager/Environment.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

Framework::MainFunctionHelperBaseImpl
	::MainFunctionHelperBaseImpl(const EnvironmentDirectory& environmentDirectory) noexcept
	:m_EnvironmentDirectory{ environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, MainFunctionHelperBaseImpl);

System::String Framework::MainFunctionHelperBaseImpl
	::GetEngineInstallationDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	// 应用层依赖于目录结构附带的库。
	// 您需要创建EnvironmentDirectory内设置的环境变量才能在应用程序查找各种数据文件。
	// EnvironmentDirectory设置的值可以从配置中读取，或直接使用默认值。
	return m_EnvironmentDirectory.GetEngineDirectory();
}

Framework::EnvironmentDirectory Framework::MainFunctionHelperBaseImpl
	::GetEnvironmentDirectory() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_EnvironmentDirectory;
} 