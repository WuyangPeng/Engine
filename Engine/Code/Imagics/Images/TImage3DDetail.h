// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:14)

#ifndef IMAGICS_IMAGICS_TIMAGE3D_DETAIL_H
#define IMAGICS_IMAGICS_TIMAGE3D_DETAIL_H

#include "TImage3D.h"

template <typename T>
Imagics::TImage3D<T>
	::TImage3D(int xBound, int yBound, int zBound, T* data)
    :TImage<T>(3)
{
    int* bounds = NEW1<int>(3);
    bounds[0] = xBound;
    bounds[1] = yBound;
    bounds[2] = zBound;
    SetBounds(bounds);
    SetData(data);
}

template <typename T>
Imagics::TImage3D<T>
	::TImage3D(const TImage3D& image)
    : TImage<T>(image)
{
}

template <typename T>
Imagics::TImage3D<T>
	::TImage3D(const char* filename)
    : TImage<T>(filename)
{
}

template <typename T>
T& Imagics::TImage3D<T>
	::operator() (int x, int y, int z) const
{
    return mData[x + mBounds[0]*(y + mBounds[1]*z)];
}

template <typename T>
int Imagics::TImage3D<T>
	::GetIndex(int x, int y, int z) const
{
    return x + mBounds[0]*(y + mBounds[1]*z);
}

template <typename T>
void Imagics::TImage3D<T>
	::GetCoordinates(int index, int& x, int& y, int& z) const
{
    x = index % mBounds[0];
    index /= mBounds[0];
    y = index % mBounds[1];
    z = index / mBounds[1];
}

template <typename T>
Imagics::TImage3D<T>& Imagics::TImage3D<T>
	::operator= (const TImage3D& image)
{
    return (TImage3D<T>&) TImage<T>::operator=(image);
}

template <typename T>
Imagics::TImage3D<T>& Imagics::TImage3D<T>
	::operator= (T value)
{
    return (TImage3D<T>&) TImage<T>::operator=(value);
}

#endif // IMAGICS_IMAGICS_TIMAGE3D_DETAIL_H