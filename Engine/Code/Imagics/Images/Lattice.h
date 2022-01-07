// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:11)

#ifndef IMAGICS_IMAGICS_LATTICE_H
#define IMAGICS_IMAGICS_LATTICE_H

#include "Imagics/ImagicsDll.h"
 

#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/ReadFileManager.h"

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE Lattice
	{
	public:
		// Abstract base class for TImage.
		virtual ~Lattice ();
		
		// Data access.
		int GetDimensions () const noexcept;
		const int* GetBounds () const noexcept;
		int GetBound (int i) const noexcept; 
		int GetQuantity () const noexcept;
		const int* GetOffsets () const noexcept;
		int GetOffset (int i) const noexcept;
		
		// Assignment.
		Lattice& operator= (const Lattice& lattice);
		Lattice& operator= (Lattice&& lattice) = default;
		
		// Comparisons.
		bool operator== (const Lattice& lattice) const noexcept;
		bool operator!= (const Lattice& lattice) const noexcept;
		
		// Conversions between n-dim and 1-dim structures.  The coordinate arrays
		// must have the same number of elements as the dimensions of the lattice.
		int GetIndex (const int* coord) const noexcept;
		void GetCoordinates (int index, int* coord) const noexcept;
		
		// Streaming.
		bool Load(CoreTools::ReadFileManager& inFile);
		bool Save(CoreTools::WriteFileManager& outFile) const;
		
		static bool LoadRaw (const char* filename, int& numDimensions,int*& bounds, int& quantity, int& rtti, int& sizeOf, char*& data);

	protected:
		// Construction.  Lattice accepts responsibility for deleting the
		// bound array.
		Lattice (int numDimensions, int* bounds);
		Lattice (const Lattice& lattice);
		Lattice (Lattice&& lattice) = default;
		Lattice () noexcept;
		
		// For deferred creation of bounds.  Lattice accepts responsibility
		// for deleting the bound array.
		Lattice (int numDimensions);
		void SetBounds (int* bounds);
		void ComputeQuantityAndOffsets () noexcept;
		
		int mNumDimensions;
		int* mBounds;
		int mQuantity;
		int* mOffsets;
		
		// Streaming.
		static const char* msHeader;
	};
}

#endif // IMAGICS_IMAGICS_LATTICE_H
