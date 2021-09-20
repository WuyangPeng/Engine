/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// Bitmap.h - Simple bitmap loader
//
// Visit gamemath.com for the latest version of this file.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __BITMAP_H_INCLUDED__
#define __BITMAP_H_INCLUDED__

#include <cstdio>
/////////////////////////////////////////////////////////////////////////////
//
// class Bitmap - a simple class to hold a bitmap image
//
/////////////////////////////////////////////////////////////////////////////
namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
	class Bitmap
	{
	public:

		// An enum to describe the format of the image

		enum EFormat
		{
			eFormat_None,	// dummy placeholder value
			eFormat_8888,	// 32-bit ARGB

			// !KLUDGE! FOr now, this is all we'll support.

		};

		// Constructor/destructor

		Bitmap() noexcept;
		~Bitmap() noexcept;

		Bitmap& operator=(const Bitmap&) = delete;
		Bitmap(const Bitmap&) = delete;
		Bitmap& operator=(Bitmap&&) noexcept = delete;
		Bitmap(Bitmap&&) noexcept = delete;

		// Memory management

		void allocateMemory(int xs, int ys, EFormat format) noexcept;
		void freeMemory() noexcept;

		// Accessors

		int	xSize() const noexcept
		{
			return sizeX;
		}
		int	ySize() const noexcept
		{
			return sizeY;
		}
		EFormat	format() const noexcept
		{
			return fmt;
		}
		void* rawData() const noexcept
		{
			return data;
		}

		// Access to the pixel data.  Colors are specified using
		// the standard 0xAARRGGBB format used by class Renderer

		unsigned getPix(int x, int y) const noexcept;
		void setPix(int x, int y, unsigned argb) noexcept;

		// Load a bitmap from an image file.  Uses the extension to
		// figure out how to load.

		bool load(const char* filename, char* returnErrMsg) noexcept;

		// Load a specific file format.

		bool loadTGA(const char* filename, char* returnErrMsg) noexcept;

		bool loadBMP(const char* filename, char* returnErrMsg) noexcept;

	private:
		bool Cleanup(FILE* f) noexcept;
		bool IOError(char* returnErrMsg, FILE* f) noexcept;

	private:
		int	sizeX;
		int	sizeY;
		EFormat	fmt;
		void* data;
	};
}
/////////////////////////////////////////////////////////////////////////////
#endif // #ifndef __BITMAP_H_INCLUDED__

