// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/30 16:15)

#include "Imagics/ImagicsExport.h"

#include "Lattice.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/Assertion/ImagicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26451)
const char* Imagics::Lattice ::msHeader = "Magic Image";

Imagics::Lattice ::Lattice(int numDimensions, int* bounds)
{
    IMAGICS_ASSERTION_0(numDimensions > 0 && bounds, "Invalid inputs\n");
    for (int i = 0; i < numDimensions; ++i)
    {
        IMAGICS_ASSERTION_0(bounds && bounds[i] > 0, "Bounds must be positive\n");
    }

    mNumDimensions = numDimensions;
    mBounds = bounds;
    mOffsets = nullptr;  // NEW1<int>(numDimensions);

    ComputeQuantityAndOffsets();
}

Imagics::Lattice ::Lattice(const Lattice& lattice)
{
    mNumDimensions = lattice.mNumDimensions;
    mQuantity = lattice.mQuantity;
    mBounds = nullptr;  // NEW1<int>(mNumDimensions);
    mOffsets = nullptr;  //  NEW1<int>(mNumDimensions);

    const size_t numBytes = mNumDimensions * sizeof(int);
    memcpy(mBounds, lattice.mBounds, numBytes);
    memcpy(mOffsets, lattice.mOffsets, numBytes);
}

Imagics::Lattice ::Lattice(int numDimensions)
{
    IMAGICS_ASSERTION_0(numDimensions > 0, "Dimensions must be positive\n");

    mNumDimensions = numDimensions;
    mBounds = 0;
    mOffsets = nullptr;  //    NEW1<int>(numDimensions);
    memset(mOffsets, 0, numDimensions * sizeof(int));
    mQuantity = 0;
}

Imagics::Lattice ::Lattice() noexcept
{
    mNumDimensions = 0;
    mBounds = 0;
    mOffsets = 0;
    mQuantity = 0;
}

Imagics::Lattice ::~Lattice()
{
    EXCEPTION_TRY
    {
        // 	DELETE1(mBounds);
        // 	DELETE1(mOffsets);
    }
    EXCEPTION_ALL_CATCH(Mathematics)
}

void Imagics::Lattice ::SetBounds(int* bounds)
{
    if (bounds == nullptr)
    {
        return;
    }

    IMAGICS_ASSERTION_0(bounds != 0, "Bounds must be specified\n");
    for (int i = 0; i < mNumDimensions; i++)
    {
        IMAGICS_ASSERTION_0(bounds[i] > 0, "Bounds must be positive\n");
    }

    mBounds = bounds;
    ComputeQuantityAndOffsets();
}

void Imagics::Lattice ::ComputeQuantityAndOffsets() noexcept
{
    int i = 0;

    // Calculate number of lattice points.
    mQuantity = 1;
    for (i = 0; i < mNumDimensions; ++i)
    {
        mQuantity *= mBounds[i];
    }

    // Calculate offset indices of neighboring lattice points.
    mOffsets[0] = 1;
    for (i = 1; i < mNumDimensions; ++i)
    {
        mOffsets[i] = mBounds[i - 1] * mOffsets[i - 1];
    }
}

Imagics::Lattice& Imagics::Lattice ::operator=(const Lattice& lattice)
{
    if (mNumDimensions != lattice.mNumDimensions)
    {
        //         DELETE1(mBounds);
        //         DELETE1(mOffsets);
        mNumDimensions = lattice.mNumDimensions;
        mQuantity = lattice.mQuantity;
        mBounds = nullptr;  // NEW1<int>(mNumDimensions);
        mOffsets = nullptr;  //  NEW1<int>(mNumDimensions);
    }

    const size_t numBytes = mNumDimensions * sizeof(int);
    memcpy(mBounds, lattice.mBounds, numBytes);
    memcpy(mOffsets, lattice.mOffsets, numBytes);
    mQuantity = lattice.mQuantity;

    return *this;
}

bool Imagics::Lattice ::operator==(const Imagics::Lattice& lattice) const noexcept
{
    if (mNumDimensions != lattice.mNumDimensions)
    {
        return false;
    }

    const int numBytes = mNumDimensions * sizeof(int);
    return memcmp(mBounds, lattice.mBounds, numBytes) == 0;
}

bool Imagics::Lattice ::operator!=(const Lattice& lattice) const noexcept
{
    return !operator==(lattice);
}

int Imagics::Lattice ::GetIndex(const int* coord) const noexcept
{
    // assert:  coord is array of mNumDimensions elements
    int index = coord[0];
    for (int i = 1; i < mNumDimensions; ++i)
    {
        index += mOffsets[i] * coord[i];
    }
    return index;
}

void Imagics::Lattice ::GetCoordinates(int index, int* coord) const noexcept
{
    // assert:  coord is array of mNumDimensions elements
    for (int i = 0; i < mNumDimensions; ++i)
    {
        coord[i] = index % mBounds[i];
        index /= mBounds[i];
    }
}

bool Imagics::Lattice ::Load(CoreTools::ReadFileManager& inFile)
{
    int numBytes = (int)strlen(msHeader) + 1;
    char* buffer = nullptr;  // NEW1<char>(numBytes);
    inFile.Read(sizeof(char), numBytes, buffer);
    buffer[numBytes - 1] = 0;
    if (strncmp(buffer, msHeader, numBytes) != 0)
    {
        // DELETE1(buffer);
        mNumDimensions = 0;
        mQuantity = 0;
        mBounds = 0;
        mOffsets = 0;
        return false;
    }
    // DELETE1(buffer);

    inFile.Read(sizeof(int), &mNumDimensions);

    //DELETE1(mBounds);
    mBounds = nullptr;  // NEW1<int>(mNumDimensions);
    inFile.Read(sizeof(int), mNumDimensions, mBounds);

    //DELETE1(mOffsets);
    mOffsets = nullptr;  // NEW1<int>(mNumDimensions);

    ComputeQuantityAndOffsets();

    return true;
}

bool Imagics::Lattice ::Save(CoreTools::WriteFileManager& outFile) const
{
    outFile.Write(sizeof(char), (int)strlen(msHeader) + 1, msHeader);
    outFile.Write(sizeof(int), &mNumDimensions);
    outFile.Write(sizeof(int), mNumDimensions, mBounds);
    return true;
}

bool Imagics::Lattice ::LoadRaw(const char* filename, int& numDimensions, int*& bounds, int& quantity, int& rtti, int& sizeOf, char*& data)
{
    CoreTools::ReadFileManager inFile(CoreTools::StringConversion::MultiByteConversionStandard(filename));

    int numBytes = (int)strlen(msHeader) + 1;
    char* buffer = nullptr;  //  NEW1<char>(numBytes);
    inFile.Read(sizeof(char), numBytes, buffer);
    buffer[numBytes - 1] = 0;
    if (strncmp(buffer, msHeader, numBytes) != 0)
    {
        //  DELETE1(buffer);

        return false;
    }
    // DELETE1(buffer);

    inFile.Read(sizeof(int), &numDimensions);

    bounds = nullptr;  // NEW1<int>(numDimensions);
    inFile.Read(sizeof(int), numDimensions, bounds);

    quantity = 1;
    for (int i = 0; i < numDimensions; ++i)
    {
        quantity *= bounds[i];
    }

    inFile.Read(sizeof(int), &rtti);
    inFile.Read(sizeof(int), &sizeOf);

    data = nullptr;  // NEW1<char>(quantity * sizeOf);
    inFile.Read(sizeOf, quantity, data);

    return true;
}

int Imagics::Lattice ::GetDimensions() const noexcept
{
    return mNumDimensions;
}

const int* Imagics::Lattice ::GetBounds() const noexcept
{
    return mBounds;
}

int Imagics::Lattice ::GetBound(int i) const noexcept
{
    return mBounds[i];
}

int Imagics::Lattice ::GetQuantity() const noexcept
{
    return mQuantity;
}

const int* Imagics::Lattice ::GetOffsets() const noexcept
{
    return mOffsets;
}

int Imagics::Lattice ::GetOffset(int i) const noexcept
{
    return mOffsets[i];
}

#include STSTEM_WARNING_POP