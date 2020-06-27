// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:46)

#include "System/SystemExport.h"

#include "GLPlugin.h"
#include "GLUtility.h"
#include "System/Helper/Noexcept.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Detail/GL11Extensions.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"

#include <cassert>
#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

namespace System
{
	void DoReportNullFunction(const char* glFunction)
	{
		cout << glFunction << " = nullptr" << endl;

		assert(false);
	}
}

void System
	::ReportNullFunction(const char* glFunction) noexcept
{	
	NoexceptNoReturn<const char*>(ReportNullFunction, glFunction);
}

namespace System
{
	void DoReportGLError(const char* glFunction)
	{
		auto code = UnderlyingCastEnum<OpenGLErrorCode>(glGetError());
		while (code != OpenGLErrorCode::NoError)
		{
			auto errorString = GetOpenGLErrorString(code);
			cout << glFunction << ":" << errorString << endl;
			assert(false);
			code = UnderlyingCastEnum<OpenGLErrorCode>(glGetError());
		}
	}
}

void System
	::ReportGLError(const char* glFunction) noexcept
{	
	NoexceptNoReturn<const char*>(DoReportGLError, glFunction);	
}

