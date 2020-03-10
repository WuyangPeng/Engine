// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:14)

#ifndef IMAGICS_IMAGICS_TIMAGE2D_DETAIL_H
#define IMAGICS_IMAGICS_TIMAGE2D_DETAIL_H

#include "TImage2D.h"

template <typename T>
Imagics::TImage2D<T>
	::TImage2D(int xBound, int yBound, T* data)
    :TImage<T>(2)
{
    int* bounds = NEW1<int>(2);
    bounds[0] = xBound;
    bounds[1] = yBound;
    SetBounds(bounds);
    SetData(data);
}

template <typename T>
Imagics::TImage2D<T>
	::TImage2D(const TImage2D& image)
    :TImage<T>(image)
{
}

template <typename T>
Imagics::TImage2D<T>
	::TImage2D(const char* filename)
    :TImage<T>(filename)
{
}

template <typename T>
T& Imagics::TImage2D<T>
	::operator() (int x, int y) const
{
    return mData[x + mBounds[0]*y];
}

template <typename T>
int Imagics::TImage2D<T>
	::GetIndex(int x, int y) const
{
    return x + mBounds[0]*y;
}

template <typename T>
void Imagics::TImage2D<T>
	::GetCoordinates(int index, int& x, int& y) const
{
    x = index % mBounds[0];
    y = index / mBounds[0];
}

template <typename T>
Imagics::TImage2D<T>& Imagics::TImage2D<T>
	::operator= (const TImage2D& image)
{
    return (TImage2D<T>&) TImage<T>::operator=(image);
}

template <typename T>
Imagics::TImage2D<T>& Imagics::TImage2D<T>
	::operator= (T value)
{
    return (TImage2D<T>&) TImage<T>::operator=(value);
}

#endif // IMAGICS_IMAGICS_TIMAGE2D_DETAIL_H