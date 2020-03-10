// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:34)

#ifndef SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_USING_H
#define SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using OpenGLHdc = HDC;
	using OpenGLHglrc = HGLRC;
	using OpenGLProc = PROC;
	using GlyphMetricsFloat = GLYPHMETRICSFLOAT;
	using GlyphMetricsFloatPtr = LPGLYPHMETRICSFLOAT;
	using LayerPlaneDescriptor = LAYERPLANEDESCRIPTOR;
	using LayerPlaneDescriptorPtr = LPLAYERPLANEDESCRIPTOR;
	using OpenGLColorref = COLORREF;
	using WglSwap = WGLSWAP;
	using PixelFormatDescriptor = PIXELFORMATDESCRIPTOR;

#else // !SYSTEM_PLATFORM_WIN32

	struct OpenGLHdcDeclare
	{
		int unused;
	};
	using OpenGLHdc = OpenGLHdcDeclare*;

	struct OpenGLHglrcDeclare
	{
		int unused;
	};
	using OpenGLHglrc = OpenGLHglrcDeclare*;
	using OpenGLProc = int(*)();

	struct PointFloat
	{
		float x;
		float y;
	};

	struct GlyphMetricsFloat
	{
		float gmfBlackBoxX;
		float gmfBlackBoxY;
		PointFloat gmfptGlyphOrigin;
		float gmfCellIncX;
		float gmfCellIncY;
	};

	using GlyphMetricsFloatPtr = GlyphMetricsFloat*;
	using OpenGLColorref = uint32_t;

	struct LayerPlaneDescriptor
	{
		int16_t nSize;
		int16_t nVersion;
		uint32_t dwFlags;
		uint8_t iPixelType;
		uint8_t cColorBits;
		uint8_t cRedBits;
		uint8_t cRedShift;
		uint8_t cGreenBits;
		uint8_t cGreenShift;
		uint8_t cBlueBits;
		uint8_t cBlueShift;
		uint8_t cAlphaBits;
		uint8_t cAlphaShift;
		uint8_t cAccumBits;
		uint8_t cAccumRedBits;
		uint8_t cAccumGreenBits;
		uint8_t cAccumBlueBits;
		uint8_t cAccumAlphaBits;
		uint8_t cDepthBits;
		uint8_t cStencilBits;
		uint8_t cAuxBuffers;
		uint8_t layerPlane;
		uint8_t bReserved;
		OpenGLColorref crTransparent;
	};

	using LayerPlaneDescriptorPtr = LayerPlaneDescriptor*;

	struct WglSwap
	{
		OpenGLHdc hdc;
		WindowUInt uiFlags;
	};

	struct PixelFormatDescriptor
	{
		int16_t  nSize;
		int16_t  nVersion;
		uint32_t dwFlags;
		uint8_t  iPixelType;
		uint8_t  cColorBits;
		uint8_t  cRedBits;
		uint8_t  cRedShift;
		uint8_t  cGreenBits;
		uint8_t  cGreenShift;
		uint8_t  cBlueBits;
		uint8_t  cBlueShift;
		uint8_t  cAlphaBits;
		uint8_t  cAlphaShift;
		uint8_t  cAccumBits;
		uint8_t  cAccumRedBits;
		uint8_t  cAccumGreenBits;
		uint8_t  cAccumBlueBits;
		uint8_t  cAccumAlphaBits;
		uint8_t  cDepthBits;
		uint8_t  cStencilBits;
		uint8_t  cAuxBuffers;
		uint8_t  iLayerType;
		uint8_t  bReserved;
		uint32_t dwLayerMask;
		uint32_t dwVisibleMask;
		uint32_t dwDamageMask;
	};

#endif // SYSTEM_PLATFORM_WIN32    		 
}

#endif // SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_USING_H