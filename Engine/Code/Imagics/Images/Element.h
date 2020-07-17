// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:02)

#ifndef IMAGICS_IMAGICS_ELEMENT_H
#define IMAGICS_IMAGICS_ELEMENT_H

#include "Imagics/ImagicsDll.h"

#include "Imagics/Helper/ElementMacro.h"

namespace Imagics
{
	constexpr int gNumImageElements = 12;
	using uchar = unsigned char;
	using ushort = unsigned short;
	using uint = unsigned int;
	using ulong = unsigned long;
	using rgb5 = unsigned short;
	using rgb8 = unsigned int;
	
	IMAGICS_DECL_ELEMENT(char);
	IMAGICS_DECL_ELEMENT(uchar);
	IMAGICS_DECL_ELEMENT(short);
	IMAGICS_DECL_ELEMENT(ushort);
	IMAGICS_DECL_ELEMENT(int);
	IMAGICS_DECL_ELEMENT(uint);
	IMAGICS_DECL_ELEMENT(long);
	IMAGICS_DECL_ELEMENT(ulong);
	IMAGICS_DECL_ELEMENT(float);
	IMAGICS_DECL_ELEMENT(double);
	IMAGICS_DECL_ELEMENT(rgb5);
	IMAGICS_DECL_ELEMENT(rgb8);
	
	unsigned short GetColor16 (unsigned char r, unsigned char g,unsigned char b);
	unsigned char GetRed16 (unsigned short color);
	unsigned char GetGreen16 (unsigned short color);
	unsigned char GetBlue16 (unsigned short color);
	
	unsigned int GetColor24 (unsigned char r, unsigned char g, unsigned char b);
	unsigned char GetRed24 (unsigned int color);
	unsigned char GetGreen24 (unsigned int color);
	unsigned char GetBlue24 (unsigned int color);
}

#endif // IMAGICS_IMAGICS_ELEMENT_H
