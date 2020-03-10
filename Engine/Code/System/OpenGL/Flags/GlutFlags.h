// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:35)

#ifndef SYSTEM_OPENGL_GLUT_FLAGS_H
#define SYSTEM_OPENGL_GLUT_FLAGS_H

#include "System/Helper/EnumMacro.h"

#if defined(SYSTEM_USE_GLUT) && defined(WIN32)

#include "System/Helper/Platform.h"
#include "System/Helper/PragmaWarning/Freeglut.h"

namespace System
{
	enum class GlutMacro
	{
		Rgb = GLUT_RGB,                           
		Rgba = GLUT_RGBA ,                         
		Index = GLUT_INDEX,                         
		Single = GLUT_SINGLE ,                       
		Double = GLUT_DOUBLE,                        
		Accum = GLUT_ACCUM ,                        
		Alpha = GLUT_ALPHA,                         
		Depth = GLUT_DEPTH,                         
		Stencil = GLUT_STENCIL,                       
		Multisample = GLUT_MULTISAMPLE,                   
		Stereo = GLUT_STEREO,                  
		Luminance = GLUT_LUMINANCE,                     
	};
}

#else // !defined(SYSTEM_USE_GLUT) || !defined(WIN32)

namespace System
{
	enum class GlutMacro
	{
		Rgb = 0x0000,
		Rgba = 0x0000,
		Index = 0x0001,
		Single = 0x0000,
		Double = 0x0002,
		Accum = 0x0004,
		Alpha = 0x0008,
		Depth = 0x0010,
		Stencil = 0x0020,
		Multisample = 0x0080,
		Stereo = 0x0100,
		Luminance = 0x0200,
	};
}

#endif // defined(SYSTEM_USE_GLUT) && defined(WIN32)

namespace System
{
	ENUM_ORABLE_OPERATOR_DEFINE(GlutMacro);
}

#endif // SYSTEM_OPENGL_GLUT_FLAGS_H
