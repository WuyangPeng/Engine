// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:14)

#ifndef IMAGICS_IMAGICS_TIMAGE_DETAIL_H
#define IMAGICS_IMAGICS_TIMAGE_DETAIL_H

#include "TImage.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/Assertion/ImagicsCustomAssertMacro.h"

template <typename T>
Imagics::TImage<T>
	::TImage(int numDimensions, int* bounds, T* data)
    :Lattice(numDimensions, bounds)
{
    SetData(data);
}

template <typename T>
Imagics::TImage<T>
	::TImage(const TImage& image)
    :Lattice(image)
{
    mData = NEW1<T>(mQuantity);
    memcpy(mData, image.mData, mQuantity*sizeof(T));
}

template <typename T>
Imagics::TImage<T>
	::TImage(const char* filename)
{
    Load(filename);
}

template <typename T>
Imagics::TImage<T>
	::TImage(int numDimensions)
    : Lattice(numDimensions)
{
}

template <typename T>
Imagics::TImage<T>
	::~TImage()
{
    DELETE1(mData);
}

template <typename T>
void Imagics::TImage<T>
	::SetData(T* data)
{
    if (data)
    {
        mData = data;
    }
    else
    {
		IMAGICS_ASSERTION_0(mQuantity > 0, "Quantity must be positive\n");
        mData = NEW1<T>(mQuantity);
        memset(mData, 0, mQuantity*sizeof(T));
    }
}

template <typename T>
T* Imagics::TImage<T>
	::GetData() const
{
    return mData;
}

template <typename T>
T& Imagics::TImage<T>
	::operator[] (int i) const
{
    return mData[i];
}

template <typename T>
Imagics::TImage<T>& Imagics
	::TImage<T>::operator= (const TImage& image)
{
    Lattice::operator=(image);

    DELETE1(mData);
    mData = NEW1<T>(mQuantity);
    memcpy(mData, image.mData, mQuantity*sizeof(T));

    return *this;
}

template <typename T>
Imagics::TImage<T>& Imagics::TImage<T>
	::operator= (T value)
{
    for (int i = 0; i < mQuantity; ++i)
    {
        mData[i] = value;
    }

    return *this;
}

template <typename T>
bool Imagics::TImage<T>
	::operator== (const TImage& image) const
{
    if (Lattice::operator!=(image))
    {
        return false;
    }

    return memcmp(mData, image.mData, mQuantity*sizeof(T)) == 0;
}

template <typename T>
bool Imagics::TImage<T>
	::operator!= (const TImage& image) const
{
    return !operator==(image);
}

template <typename T>
bool Imagics::TImage<T>
	::Load(const char* filename)
{
	CoreTools::ReadFileManager inFile(CoreTools::StringConversion::MultiByteConversionStandard(filename));
    
    if (!Lattice::Load(inFile))
    {
        mData = 0;
        
        return false;
    }

    int rtti, sizeOf;
    inFile.Read(sizeof(int), &rtti);
    inFile.Read(sizeof(int), &sizeOf);

    mData = NEW1<T>(mQuantity);
    if (rtti == T::GetRTTI())
    {
        inFile.Read(sizeof(T), mQuantity, mData);
    }
    else
    {
		char* fileData = NEW1<char>(mQuantity*sizeOf);
        inFile.Read(sizeOf, mQuantity, fileData);
        ImageConvert(mQuantity, rtti, fileData, T::GetRTTI(), mData);
        DELETE1(fileData);
    }
 
    return true;
}

template <typename T>
bool Imagics::TImage<T>
	::Save(const char* filename) const
{
	CoreTools::WriteFileManager outFile(CoreTools::StringConversion::MultiByteConversionStandard(filename));
	
    if (!Lattice::Save(outFile))
    {  
        return false;
    }

    int rtti = T::GetRTTI();
    outFile.Write(sizeof(int), &rtti);

    int sizeOf = (int)(sizeof(T));
    outFile.Write(sizeof(int), &sizeOf);

    outFile.Write(sizeof(T), mQuantity, mData);
 
    return true;
}

#endif // IMAGICS_IMAGICS_TIMAGE_DETAIL_H