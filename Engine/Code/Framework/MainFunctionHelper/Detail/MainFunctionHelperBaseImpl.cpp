// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 17:54)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBaseImpl.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::MainFunctionHelperBaseImpl
	::MainFunctionHelperBaseImpl(const EnvironmentDirectory& environmentDirectory)	
	:m_EnvironmentDirectory{ environmentDirectory }
{
	GenerateEnvironment();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,MainFunctionHelperBaseImpl);

System::String Framework::MainFunctionHelperBaseImpl
	::GetEngineInstallationDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	// 应用层依赖于目录结构附带的库。
	// 您需要创建EnvironmentDirectory内设置的环境变量才能在应用程序查找各种数据文件。
	// EnvironmentDirectory设置的值可以从配置中读取，或直接使用默认值。
	return m_EnvironmentDirectory.GetEngineDirectory();
}

// private
void Framework::MainFunctionHelperBaseImpl
	::GenerateEnvironment()
{
	// TODO：设置路径涉及文件夹
	// BigEndian/LittleEndian和DirectX/OpenGL。
	// 对于字节顺序的文件夹名称可以在
	// SYSTEM_BIG_ENDIAN/SYSTEM_LITTLE_ENDIAN设置。
	// 对于渲染器类型的文件夹名可以在渲染器类中提供静态字符串。

	// 资源文件的根目录路径
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetResourcePath());

	// 着色器文件的路径。
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetShaderPath());

	// 场景对象的路径。
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetScenePath());

	// 纹理图像文件的路径。
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetTexturePath());

	// 顶点/索引缓冲区的路径
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetVertexPath());

	// 图像文件的路径。
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetImagePath());

	// 配置文件的路径。
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetConfigurationPath());
	ENVIRONMENT_SINGLETON.SetConfigurationPath(m_EnvironmentDirectory.GetConfigurationPath());
}

