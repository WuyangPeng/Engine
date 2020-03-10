// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:11)

#ifndef IMAGICS_IMAGICS_LATTICE_H
#define IMAGICS_IMAGICS_LATTICE_H

#include "Imagics/ImagicsDll.h"
 
#include "CoreTools/Helper/MemoryMacro.h"
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
		int GetDimensions () const;
		const int* GetBounds () const;
		int GetBound (int i) const;
		int GetQuantity () const;
		const int* GetOffsets () const;
		int GetOffset (int i) const;
		
		// Assignment.
		Lattice& operator= (const Lattice& lattice);
		
		// Comparisons.
		bool operator== (const Lattice& lattice) const;
		bool operator!= (const Lattice& lattice) const;
		
		// Conversions between n-dim and 1-dim structures.  The coordinate arrays
		// must have the same number of elements as the dimensions of the lattice.
		int GetIndex (const int* coord) const;
		void GetCoordinates (int index, int* coord) const;
		
		// Streaming.
		bool Load(CoreTools::ReadFileManager& inFile);
		bool Save(CoreTools::WriteFileManager& outFile) const;
		
		static bool LoadRaw (const char* filename, int& numDimensions,int*& bounds, int& quantity, int& rtti, int& sizeOf, char*& data);

	protected:
		// Construction.  Lattice accepts responsibility for deleting the
		// bound array.
		Lattice (int numDimensions, int* bounds);
		Lattice (const Lattice& lattice);
		Lattice ();
		
		// For deferred creation of bounds.  Lattice accepts responsibility
		// for deleting the bound array.
		Lattice (int numDimensions);
		void SetBounds (int* bounds);
		void ComputeQuantityAndOffsets ();
		
		int mNumDimensions;
		int* mBounds;
		int mQuantity;
		int* mOffsets;
		
		// Streaming.
		static const char* msHeader;
	};
}

#endif // IMAGICS_IMAGICS_LATTICE_H
