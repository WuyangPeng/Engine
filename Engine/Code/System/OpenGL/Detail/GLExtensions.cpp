//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 18:56)

#include "System/SystemExport.h"

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
#include "GLARBESExtensions.h"
#include "GLARBExtensions.h"
#include "GLARBImagingExtensions.h"
#include "GLEXTExtensions.h"
#include "GLExtensions.h"
#include "GLUtility.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/Detail/OpenGL/GL11ExtensionsMacro.h"
#include "System/Helper/Noexcept.h"
#include "System/OpenGL/Detail/GL11Extensions.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// 访问OpenGL驱动程序的信息。

const char* System::GetVendorString() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    return reinterpret_cast<const char*>(glGetString(GL_VENDOR));
#include STSTEM_WARNING_POP
}

const char* System::GetRendererString() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    return reinterpret_cast<const char*>(glGetString(GL_RENDERER));
#include STSTEM_WARNING_POP
}

const char* System::GetVersionString() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    return reinterpret_cast<const char*>(glGetString(GL_VERSION));
#include STSTEM_WARNING_POP
}

const char* System::GetExtensionString() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    return reinterpret_cast<const char*>(glGetString(GL_EXTENSIONS));
#include STSTEM_WARNING_POP
}

// OpenGL的系统初始化
void System::PrintOpenGLInfo()
{
    auto vendor = GetVendorString();
    if (vendor != nullptr)
    {
        cout << "vendor = " << vendor << "\n";
    }
    else
    {
        cout << "vendor = <null>\n";
    }

    auto renderer = GetRendererString();
    if (renderer != nullptr)
    {
        cout << "renderer = " << renderer << "\n";
    }
    else
    {
        cout << "renderer = <null>\n";
    }

    auto version = GetVersionString();
    if (version != nullptr)
    {
        cout << "version = " << version << "\n";
    }
    else
    {
        cout << "version = <null>\n";
    }

    auto extensions = GetExtensionString();
    if (extensions != nullptr)
    {
        cout << "extensions =\n";
        const auto length = Strlen(extensions) + 1;
        vector<char> ext(length);

        char* next{ nullptr };
        if (Strcpy(ext.data(), length, extensions))
        {
            char* token = Strtok(ext.data(), " \t\n", &next);
            while (token != nullptr)
            {
                cout << "    " << token << "\n";
                token = Strtok(nullptr, " \t\n", &next);
            }
        }
    }
    else
    {
        cout << "extensions = <null>\n";
    }
}

bool System::InitGL(bool printInfo)
{
    if (printInfo)
    {
        NoexceptNoReturn(PrintOpenGLInfo);
    }

    InitOpenGL12();
    InitGlArbImaging();
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

    InitGlArb();
    InitGlExt();
    InitGlArbEs();

    if (GetOpenGLVersion() != System::OpenGLSystemVersion::VersionNone)
        return true;
    else
        return false;
}
