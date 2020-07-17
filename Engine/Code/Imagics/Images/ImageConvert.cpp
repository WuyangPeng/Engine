// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:15)

#include "Imagics/ImagicsExport.h"

#include "Element.h"
#include "ImageConvert.h"
#include "Imagics/Helper/ImageConvertMacro.h"

namespace Imagics
{
	IMAGICS_IMAGE_CONVERTER(char, uchar)
	IMAGICS_IMAGE_CONVERTER(char, short)
	IMAGICS_IMAGE_CONVERTER(char, ushort)
	IMAGICS_IMAGE_CONVERTER(char, int)
	IMAGICS_IMAGE_CONVERTER(char, uint)
	IMAGICS_IMAGE_CONVERTER(char, long)
	IMAGICS_IMAGE_CONVERTER(char, ulong)
	IMAGICS_IMAGE_CONVERTER(char, float)
	IMAGICS_IMAGE_CONVERTER(char, double)
	IMAGICS_IMAGE_CONVERTER(char, rgb5)
	IMAGICS_IMAGE_CONVERTER(char, rgb8)

	IMAGICS_IMAGE_CONVERTER(uchar, char)
	IMAGICS_IMAGE_CONVERTER(uchar, short)
	IMAGICS_IMAGE_CONVERTER(uchar, ushort)
	IMAGICS_IMAGE_CONVERTER(uchar, int)
	IMAGICS_IMAGE_CONVERTER(uchar, uint)
	IMAGICS_IMAGE_CONVERTER(uchar, long)
	IMAGICS_IMAGE_CONVERTER(uchar, ulong)
	IMAGICS_IMAGE_CONVERTER(uchar, float)
	IMAGICS_IMAGE_CONVERTER(uchar, double)
	IMAGICS_IMAGE_CONVERTER(uchar, rgb5)
	IMAGICS_IMAGE_CONVERTER(uchar, rgb8)

	IMAGICS_IMAGE_CONVERTER(short, char)
	IMAGICS_IMAGE_CONVERTER(short, uchar)
	IMAGICS_IMAGE_CONVERTER(short, ushort)
	IMAGICS_IMAGE_CONVERTER(short, int)
	IMAGICS_IMAGE_CONVERTER(short, uint)
	IMAGICS_IMAGE_CONVERTER(short, long)
	IMAGICS_IMAGE_CONVERTER(short, ulong)
	IMAGICS_IMAGE_CONVERTER(short, float)
	IMAGICS_IMAGE_CONVERTER(short, double)
	IMAGICS_IMAGE_CONVERTER(short, rgb5)
	IMAGICS_IMAGE_CONVERTER(short, rgb8)

	IMAGICS_IMAGE_CONVERTER(ushort, char)
	IMAGICS_IMAGE_CONVERTER(ushort, uchar)
	IMAGICS_IMAGE_CONVERTER(ushort, short)
	IMAGICS_IMAGE_CONVERTER(ushort, int)
	IMAGICS_IMAGE_CONVERTER(ushort, uint)
	IMAGICS_IMAGE_CONVERTER(ushort, long)
	IMAGICS_IMAGE_CONVERTER(ushort, ulong)
	IMAGICS_IMAGE_CONVERTER(ushort, float)
	IMAGICS_IMAGE_CONVERTER(ushort, double)
	IMAGICS_IMAGE_CONVERTER(ushort, rgb5)
	IMAGICS_IMAGE_CONVERTER(ushort, rgb8)

	IMAGICS_IMAGE_CONVERTER(int, char)
	IMAGICS_IMAGE_CONVERTER(int, uchar)
	IMAGICS_IMAGE_CONVERTER(int, short)
	IMAGICS_IMAGE_CONVERTER(int, ushort)
	IMAGICS_IMAGE_CONVERTER(int, uint)
	IMAGICS_IMAGE_CONVERTER(int, long)
	IMAGICS_IMAGE_CONVERTER(int, ulong)
	IMAGICS_IMAGE_CONVERTER(int, float)
	IMAGICS_IMAGE_CONVERTER(int, double)
	IMAGICS_IMAGE_CONVERTER(int, rgb5)
	IMAGICS_IMAGE_CONVERTER(int, rgb8)

	IMAGICS_IMAGE_CONVERTER(uint, char)
	IMAGICS_IMAGE_CONVERTER(uint, uchar)
	IMAGICS_IMAGE_CONVERTER(uint, short)
	IMAGICS_IMAGE_CONVERTER(uint, ushort)
	IMAGICS_IMAGE_CONVERTER(uint, int)
	IMAGICS_IMAGE_CONVERTER(uint, long)
	IMAGICS_IMAGE_CONVERTER(uint, ulong)
	IMAGICS_IMAGE_CONVERTER(uint, float)
	IMAGICS_IMAGE_CONVERTER(uint, double)
	IMAGICS_IMAGE_CONVERTER(uint, rgb5)
	IMAGICS_IMAGE_CONVERTER(uint, rgb8)

	IMAGICS_IMAGE_CONVERTER(long, char)
	IMAGICS_IMAGE_CONVERTER(long, uchar)
	IMAGICS_IMAGE_CONVERTER(long, short)
	IMAGICS_IMAGE_CONVERTER(long, ushort)
	IMAGICS_IMAGE_CONVERTER(long, int)
	IMAGICS_IMAGE_CONVERTER(long, uint)
	IMAGICS_IMAGE_CONVERTER(long, ulong)
	IMAGICS_IMAGE_CONVERTER(long, float)
	IMAGICS_IMAGE_CONVERTER(long, double)
	IMAGICS_IMAGE_CONVERTER(long, rgb5)
	IMAGICS_IMAGE_CONVERTER(long, rgb8)

	IMAGICS_IMAGE_CONVERTER(ulong, char)
	IMAGICS_IMAGE_CONVERTER(ulong, uchar)
	IMAGICS_IMAGE_CONVERTER(ulong, short)
	IMAGICS_IMAGE_CONVERTER(ulong, ushort)
	IMAGICS_IMAGE_CONVERTER(ulong, int)
	IMAGICS_IMAGE_CONVERTER(ulong, uint)
	IMAGICS_IMAGE_CONVERTER(ulong, long)
	IMAGICS_IMAGE_CONVERTER(ulong, float)
	IMAGICS_IMAGE_CONVERTER(ulong, double)
	IMAGICS_IMAGE_CONVERTER(ulong, rgb5)
	IMAGICS_IMAGE_CONVERTER(ulong, rgb8)

	IMAGICS_IMAGE_CONVERTER(float, char)
	IMAGICS_IMAGE_CONVERTER(float, uchar)
	IMAGICS_IMAGE_CONVERTER(float, short)
	IMAGICS_IMAGE_CONVERTER(float, ushort)
	IMAGICS_IMAGE_CONVERTER(float, int)
	IMAGICS_IMAGE_CONVERTER(float, uint)
	IMAGICS_IMAGE_CONVERTER(float, long)
	IMAGICS_IMAGE_CONVERTER(float, ulong)
	IMAGICS_IMAGE_CONVERTER(float, double)
	IMAGICS_IMAGE_CONVERTER(float, rgb5)
	IMAGICS_IMAGE_CONVERTER(float, rgb8)

	IMAGICS_IMAGE_CONVERTER(double, char)
	IMAGICS_IMAGE_CONVERTER(double, uchar)
	IMAGICS_IMAGE_CONVERTER(double, short)
	IMAGICS_IMAGE_CONVERTER(double, ushort)
	IMAGICS_IMAGE_CONVERTER(double, int)
	IMAGICS_IMAGE_CONVERTER(double, uint)
	IMAGICS_IMAGE_CONVERTER(double, long)
	IMAGICS_IMAGE_CONVERTER(double, ulong)
	IMAGICS_IMAGE_CONVERTER(double, float)
	IMAGICS_IMAGE_CONVERTER(double, rgb5)
	IMAGICS_IMAGE_CONVERTER(double, rgb8)

	IMAGICS_IMAGE_CONVERTER(rgb5, char)
	IMAGICS_IMAGE_CONVERTER(rgb5, uchar)
	IMAGICS_IMAGE_CONVERTER(rgb5, short)
	IMAGICS_IMAGE_CONVERTER(rgb5, ushort)
	IMAGICS_IMAGE_CONVERTER(rgb5, int)
	IMAGICS_IMAGE_CONVERTER(rgb5, uint)
	IMAGICS_IMAGE_CONVERTER(rgb5, long)
	IMAGICS_IMAGE_CONVERTER(rgb5, ulong)
	IMAGICS_IMAGE_CONVERTER(rgb5, float)
	IMAGICS_IMAGE_CONVERTER(rgb5, double)
	IMAGICS_IMAGE_CONVERTER(rgb5, rgb8)

	IMAGICS_IMAGE_CONVERTER(rgb8, char)
	IMAGICS_IMAGE_CONVERTER(rgb8, uchar)
	IMAGICS_IMAGE_CONVERTER(rgb8, short)
	IMAGICS_IMAGE_CONVERTER(rgb8, ushort)
	IMAGICS_IMAGE_CONVERTER(rgb8, int)
	IMAGICS_IMAGE_CONVERTER(rgb8, uint)
	IMAGICS_IMAGE_CONVERTER(rgb8, long)
	IMAGICS_IMAGE_CONVERTER(rgb8, ulong)
	IMAGICS_IMAGE_CONVERTER(rgb8, float)
	IMAGICS_IMAGE_CONVERTER(rgb8, double)
	IMAGICS_IMAGE_CONVERTER(rgb8, rgb5)

	typedef void(*Converter)(int, void*, void*);
	static Converter gsConvert[Imagics::gNumImageElements][Imagics::gNumImageElements] =
	{
		{ 
			0,
			IMAGICS_IMAGE_ENTRY(char, uchar),
			IMAGICS_IMAGE_ENTRY(char, short),
			IMAGICS_IMAGE_ENTRY(char, ushort),
			IMAGICS_IMAGE_ENTRY(char, int),
			IMAGICS_IMAGE_ENTRY(char, uint),
			IMAGICS_IMAGE_ENTRY(char, long),
			IMAGICS_IMAGE_ENTRY(char, ulong),
			IMAGICS_IMAGE_ENTRY(char, float),
			IMAGICS_IMAGE_ENTRY(char, double),
			IMAGICS_IMAGE_ENTRY(char, rgb5),
			IMAGICS_IMAGE_ENTRY(char, rgb8)
		},

		{ 
			IMAGICS_IMAGE_ENTRY(uchar, char),
			0,
			IMAGICS_IMAGE_ENTRY(uchar, short),
			IMAGICS_IMAGE_ENTRY(uchar, ushort),
			IMAGICS_IMAGE_ENTRY(uchar, int),
			IMAGICS_IMAGE_ENTRY(uchar, uint),
			IMAGICS_IMAGE_ENTRY(uchar, long),
			IMAGICS_IMAGE_ENTRY(uchar, ulong),
			IMAGICS_IMAGE_ENTRY(uchar, float),
			IMAGICS_IMAGE_ENTRY(uchar, double),
			IMAGICS_IMAGE_ENTRY(uchar, rgb5),
			IMAGICS_IMAGE_ENTRY(uchar, rgb8) 
		},

		{ 
			IMAGICS_IMAGE_ENTRY(short, char),
			IMAGICS_IMAGE_ENTRY(short, uchar),
			0,
			IMAGICS_IMAGE_ENTRY(short, ushort),
			IMAGICS_IMAGE_ENTRY(short, int),
			IMAGICS_IMAGE_ENTRY(short, uint),
			IMAGICS_IMAGE_ENTRY(short, long),
			IMAGICS_IMAGE_ENTRY(short, ulong),
			IMAGICS_IMAGE_ENTRY(short, float),
			IMAGICS_IMAGE_ENTRY(short, double),
			IMAGICS_IMAGE_ENTRY(short, rgb5),
			IMAGICS_IMAGE_ENTRY(short, rgb8)
		},

		{ 
			IMAGICS_IMAGE_ENTRY(ushort, char),			
			IMAGICS_IMAGE_ENTRY(ushort, uchar),	
			IMAGICS_IMAGE_ENTRY(ushort, short),
			0,
			IMAGICS_IMAGE_ENTRY(ushort, int),
			IMAGICS_IMAGE_ENTRY(ushort, uint),
			IMAGICS_IMAGE_ENTRY(ushort, long),
			IMAGICS_IMAGE_ENTRY(ushort, ulong),
			IMAGICS_IMAGE_ENTRY(ushort, float),
			IMAGICS_IMAGE_ENTRY(ushort, double),
			IMAGICS_IMAGE_ENTRY(ushort, rgb5),
			IMAGICS_IMAGE_ENTRY(ushort, rgb8)
		},

		{
			IMAGICS_IMAGE_ENTRY(int, char),
			IMAGICS_IMAGE_ENTRY(int, uchar),
			IMAGICS_IMAGE_ENTRY(int, short),
			IMAGICS_IMAGE_ENTRY(int, ushort),
			0,
			IMAGICS_IMAGE_ENTRY(int, uint),
			IMAGICS_IMAGE_ENTRY(int, long),
			IMAGICS_IMAGE_ENTRY(int, ulong),
			IMAGICS_IMAGE_ENTRY(int, float),
			IMAGICS_IMAGE_ENTRY(int, double),
			IMAGICS_IMAGE_ENTRY(int, rgb5),
			IMAGICS_IMAGE_ENTRY(int, rgb8)
		},

		{ 
			IMAGICS_IMAGE_ENTRY(uint, char),
			IMAGICS_IMAGE_ENTRY(uint, uchar),
			IMAGICS_IMAGE_ENTRY(uint, short),
			IMAGICS_IMAGE_ENTRY(uint, ushort),
			IMAGICS_IMAGE_ENTRY(uint, int),
			0,
			IMAGICS_IMAGE_ENTRY(uint, long),
			IMAGICS_IMAGE_ENTRY(uint, ulong),
			IMAGICS_IMAGE_ENTRY(uint, float),
			IMAGICS_IMAGE_ENTRY(uint, double),
			IMAGICS_IMAGE_ENTRY(uint, rgb5),
			IMAGICS_IMAGE_ENTRY(uint, rgb8) 
		},

		{ 
			IMAGICS_IMAGE_ENTRY(long, char),
			IMAGICS_IMAGE_ENTRY(long, uchar),
			IMAGICS_IMAGE_ENTRY(long, short),
			IMAGICS_IMAGE_ENTRY(long, ushort),
			IMAGICS_IMAGE_ENTRY(long, int),
			IMAGICS_IMAGE_ENTRY(long, uint),
			0,
			IMAGICS_IMAGE_ENTRY(long, ulong),
			IMAGICS_IMAGE_ENTRY(long, float),
			IMAGICS_IMAGE_ENTRY(long, double),
			IMAGICS_IMAGE_ENTRY(long, rgb5),
			IMAGICS_IMAGE_ENTRY(long, rgb8)
		},

		{ 
			IMAGICS_IMAGE_ENTRY(ulong, char),
			IMAGICS_IMAGE_ENTRY(ulong, uchar),
			IMAGICS_IMAGE_ENTRY(ulong, short),
			IMAGICS_IMAGE_ENTRY(ulong, ushort),
			IMAGICS_IMAGE_ENTRY(ulong, int),
			IMAGICS_IMAGE_ENTRY(ulong, uint),
			IMAGICS_IMAGE_ENTRY(ulong, long),
			0,
			IMAGICS_IMAGE_ENTRY(ulong, float),
			IMAGICS_IMAGE_ENTRY(ulong, double),
			IMAGICS_IMAGE_ENTRY(ulong, rgb5),
			IMAGICS_IMAGE_ENTRY(ulong, rgb8) 
		},

		{ 
			IMAGICS_IMAGE_ENTRY(float, char),
			IMAGICS_IMAGE_ENTRY(float, uchar),
			IMAGICS_IMAGE_ENTRY(float, short),
			IMAGICS_IMAGE_ENTRY(float, ushort),
			IMAGICS_IMAGE_ENTRY(float, int),
			IMAGICS_IMAGE_ENTRY(float, uint),
			IMAGICS_IMAGE_ENTRY(float, long),
			IMAGICS_IMAGE_ENTRY(float, ulong),
			0,
			IMAGICS_IMAGE_ENTRY(float, double),
			IMAGICS_IMAGE_ENTRY(float, rgb5),
			IMAGICS_IMAGE_ENTRY(float, rgb8)
		},

		{ 
			IMAGICS_IMAGE_ENTRY(double, char),
			IMAGICS_IMAGE_ENTRY(double, uchar),
			IMAGICS_IMAGE_ENTRY(double, short),
			IMAGICS_IMAGE_ENTRY(double, ushort),
			IMAGICS_IMAGE_ENTRY(double, int),
			IMAGICS_IMAGE_ENTRY(double, uint),
			IMAGICS_IMAGE_ENTRY(double, long),
			IMAGICS_IMAGE_ENTRY(double, ulong),
			IMAGICS_IMAGE_ENTRY(double, float),
			0,
			IMAGICS_IMAGE_ENTRY(double, rgb5),
			IMAGICS_IMAGE_ENTRY(double, rgb8)
		},

		{ 
			IMAGICS_IMAGE_ENTRY(rgb5, char),
			IMAGICS_IMAGE_ENTRY(rgb5, uchar),
			IMAGICS_IMAGE_ENTRY(rgb5, short),
			IMAGICS_IMAGE_ENTRY(rgb5, ushort),
			IMAGICS_IMAGE_ENTRY(rgb5, int),
			IMAGICS_IMAGE_ENTRY(rgb5, uint),
			IMAGICS_IMAGE_ENTRY(rgb5, long),
			IMAGICS_IMAGE_ENTRY(rgb5, ulong),
			IMAGICS_IMAGE_ENTRY(rgb5, float),
			IMAGICS_IMAGE_ENTRY(rgb5, double),
			0,
			IMAGICS_IMAGE_ENTRY(rgb5, rgb8)
		},

		{ 
			IMAGICS_IMAGE_ENTRY(rgb8, char),
			IMAGICS_IMAGE_ENTRY(rgb8, uchar),
			IMAGICS_IMAGE_ENTRY(rgb8, short),
			IMAGICS_IMAGE_ENTRY(rgb8, ushort),
			IMAGICS_IMAGE_ENTRY(rgb8, int),
			IMAGICS_IMAGE_ENTRY(rgb8, uint),
			IMAGICS_IMAGE_ENTRY(rgb8, long),
			IMAGICS_IMAGE_ENTRY(rgb8, ulong),
			IMAGICS_IMAGE_ENTRY(rgb8, float),
			IMAGICS_IMAGE_ENTRY(rgb8, double),
			IMAGICS_IMAGE_ENTRY(rgb8, rgb5),
			0
		}
	};
}

void Imagics
	::ImageConvert(int quantity, int srcRTTI, void* srcData,int trgRTTI, void* trgData)
{
    Converter convert = gsConvert[srcRTTI][trgRTTI];
    convert(quantity, srcData, trgData);
}

 
