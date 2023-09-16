///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 23:38)

#include "System/SystemExport.h"

#include "GL10Extensions.h"
#include "GL11Extensions.h"
#include "GL12Extensions.h"
#include "GL13Extensions.h"
#include "GL14Extensions.h"
#include "GL15Extensions.h"
#include "GL20Extensions.h"
#include "GL21Extensions.h"
#include "GL30Extensions.h"
#include "GL31Extensions.h"
#include "GL32Extensions.h"
#include "GL33Extensions.h"
#include "GL40Extensions.h"
#include "GL41Extensions.h"
#include "GL42Extensions.h"
#include "GL43Extensions.h"
#include "GL44Extensions.h"
#include "GL45Extensions.h"
#include "GL46Extensions.h"
#include "GLExtensions.h"
#include "System/Helper/PragmaWarning.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// 访问OpenGL驱动程序的信息。

const char* System::GetVendorString() noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const char*>(GLGetString(GL_VENDOR));

#include SYSTEM_WARNING_POP
}

const char* System::GetRendererString() noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const char*>(GLGetString(GL_RENDERER));

#include SYSTEM_WARNING_POP
}

const char* System::GetVersionString() noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const char*>(GLGetString(GL_VERSION));

#include SYSTEM_WARNING_POP
}

const char* System::GetShadingLanguageVersion() noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const char*>(GLGetString(GL_SHADING_LANGUAGE_VERSION));

#include SYSTEM_WARNING_POP
}

// OpenGL的系统初始化

bool System::InitGL() noexcept
{
    InitOpenGL10();
    InitOpenGL11();
    InitOpenGL12();
    InitOpenGL13();
    InitOpenGL14();
    InitOpenGL15();
    InitOpenGL20();
    InitOpenGL21();
    InitOpenGL30();
    InitOpenGL31();
    InitOpenGL32();
    InitOpenGL33();
    InitOpenGL40();
    InitOpenGL41();
    InitOpenGL42();
    InitOpenGL43();
    InitOpenGL44();
    InitOpenGL45();
    InitOpenGL46();

    if (GetOpenGLVersion() != OpenGLSystemVersion::VersionNone)
        return true;
    else
        return false;
}
