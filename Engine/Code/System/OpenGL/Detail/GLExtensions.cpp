// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:46)

#include "System/SystemExport.h"

#include "GLExtensions.h" 
#include "GL12Extensions.h"
#include "GLARBImagingExtensions.h"
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
#include "GLARBExtensions.h"
#include "GLARBESExtensions.h"
#include "GLEXTExtensions.h"
#include "GLUtility.h"
#include "System/Helper/Noexcept.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Detail/GL11Extensions.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/Detail/OpenGL/GL11ExtensionsMacro.h"

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

// 访问OpenGL驱动程序的信息。

const char* System
	::GetVendorString() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	return reinterpret_cast<const char*>(glGetString(GL_VENDOR));
#include STSTEM_WARNING_POP
}

const char* System
	::GetRendererString() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	return reinterpret_cast<const char*>(glGetString(GL_RENDERER));
#include STSTEM_WARNING_POP
}

const char* System
	::GetVersionString() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	return reinterpret_cast<const char*>(glGetString(GL_VERSION));
#include STSTEM_WARNING_POP
}

const char* System
	::GetExtensionString() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	return reinterpret_cast<const char*>(glGetString(GL_EXTENSIONS));
#include STSTEM_WARNING_POP
}

// OpenGL的系统初始化 

void System
	::PrintOpenGLInfo()  
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
		Strcpy(ext.data(), length, extensions);
		char* token = Strtok(ext.data(), " \t\n", &next);
		while (token != nullptr)
		{
			cout << "    " << token << "\n";
			token = Strtok(nullptr, " \t\n", &next);
		}
	}
	else
	{
		cout << "extensions = <null>\n";
	}
}

bool System
	::InitGL(bool printInfo) noexcept
{
	if (printInfo)
	{
		Disable26447NoReturn(PrintOpenGLInfo);
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

