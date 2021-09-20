///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/26 23:45)

#include "Example/BookCpp/AppliedCpp/AppliedCppExport.h"

#include "APImage.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/AppliedCpp/Helper/AppliedCppClassInvariantMacro.h"

// memcpy
#include <memory.h>

using std::string;

// �򵥵Ķ�������ͼ����������

/// ���
///       1         2         3         4         5         6    6
///345678901234567890123456789012345678901234567890123456789012345

BookIntermediate::AppliedCpp::APImage::APImage() noexcept
    : width(0), height(0), pixels(nullptr)
{
    APPLIED_CPP_SELF_CLASS_IS_VALID_1;
}

BookIntermediate::AppliedCpp::APImage::APImage(int width, int height)
    : width(width), height(height), pixels(nullptr)
{
    Init();

    APPLIED_CPP_SELF_CLASS_IS_VALID_1;
}

BookIntermediate::AppliedCpp::APImage::APImage(const APImage& src)
    : width(0), height(0), pixels(nullptr)
{
    if (src.IsImageValid())
    {
        // ��Դӳ�������´�����Ϣ
        width = src.Width();
        height = src.Height();
        Init();

        if (pixels != nullptr)
        {
            const auto size = width * height;
            memcpy(pixels, src.pixels, size);
        }
    }

    APPLIED_CPP_SELF_CLASS_IS_VALID_1;
}

BookIntermediate::AppliedCpp::APImage::APImage(APImage&& src) noexcept
    : width(src.width), height(src.height), pixels(src.pixels)
{
    src.pixels = nullptr;

    APPLIED_CPP_SELF_CLASS_IS_VALID_1;
}

BookIntermediate::AppliedCpp::APImage& BookIntermediate::AppliedCpp::APImage::operator=(APImage&& src) noexcept
{
    APPLIED_CPP_CLASS_IS_VALID_1;

    APImage temp(std::move(src));
    Swap(temp);

    return *this;
}

template <class T>
void swap(T& a, T& b) noexcept
{
    T copy(a);
    a = b;
    b = copy;
}

void BookIntermediate::AppliedCpp::APImage::Swap(APImage& src) noexcept
{
    ::swap(width, src.width);
    ::swap(height, src.height);
    ::swap(pixels, src.pixels);
}

#if 1

BookIntermediate::AppliedCpp::APImage& BookIntermediate::AppliedCpp::APImage::operator=(const APImage& src)
{
    APPLIED_CPP_CLASS_IS_VALID_1;

    APImage temp(src);
    Swap(temp);

    return *this;
}

#else  // 0

// ����ԭʼ�ĸ�ֵ�������û������Sutter�Ľ������

BookIntermediate::AppliedCpp::APImage& BookIntermediate::AppliedCpp::APImage::operator=(const APImage& src)
{
    APPLIED_CPP_CLASS_IS_VALID_1;

    if (&src != this)
    {
        // ɾ���κ��������ݲ����´���Դͼ��
        Cleanup();
        width = src.Width();
        height = src.Height();
        Init();

        const auto size = width * height;
        memcpy(pixels, src.pixels, size);
    }

    return *this;
}

#endif  // 0

BookIntermediate::AppliedCpp::APImage::~APImage()
{
    Cleanup();
}

#ifdef OPEN_CLASS_INVARIANT

bool BookIntermediate::AppliedCpp::APImage::IsValid() const noexcept
{
    if (width == 0 && height == 0)
        return pixels == nullptr;
    else
        return pixels != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

void BookIntermediate::AppliedCpp::APImage::Cleanup() noexcept
{
    // ������Ż���ԭʼ�Ŀ�״̬��
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
    delete[] pixels;
#include STSTEM_WARNING_POP

    width = 0;
    height = 0;
    pixels = nullptr;
}

void BookIntermediate::AppliedCpp::APImage::Init()
{
    // �����ڴ���䶼ͨ���˺������С�
    if (width > 0 && height > 0)
    {
        const auto size = width * height;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
        pixels = new unsigned char[size];
#include STSTEM_WARNING_POP
    }
}

void BookIntermediate::AppliedCpp::APImage::SetPixel(int x, int y, unsigned char pixel)
{
    APPLIED_CPP_CLASS_IS_VALID_1;

    if (x < 0 || y < 0 || x >= width || y >= height || !IsImageValid())
    {
        throw RangeError();
    }

    // ͼ������һ�δ洢һ�С�
    const auto step = y * width + x;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
    unsigned char* p = pixels + step;
#include STSTEM_WARNING_POP

    *p = pixel;
}

unsigned char BookIntermediate::AppliedCpp::APImage::GetPixel(int x, int y) const
{
    APPLIED_CPP_CLASS_IS_VALID_CONST_1;

    if (x < 0 || y < 0 || x >= width || y >= height || !IsImageValid())
    {
        throw RangeError();
    }

    // ͼ������һ�δ洢һ�С�
    const auto step = y * width + x;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
    const unsigned char* p = pixels + step;
#include STSTEM_WARNING_POP

    return *p;
}

bool BookIntermediate::AppliedCpp::APImage::IsImageValid() const noexcept
{
    APPLIED_CPP_CLASS_IS_VALID_CONST_1;

    return pixels != nullptr;
}

int BookIntermediate::AppliedCpp::APImage::Width() const noexcept
{
    APPLIED_CPP_CLASS_IS_VALID_CONST_1;

    return width;
}

int BookIntermediate::AppliedCpp::APImage::Height() const noexcept
{
    APPLIED_CPP_CLASS_IS_VALID_CONST_1;

    return height;
}

BookIntermediate::AppliedCpp::APImage BookIntermediate::AppliedCpp::APImage::ArbitraryAlgorithm([[maybe_unused]] const string& args)  
{
    APPLIED_CPP_CLASS_IS_VALID_CONST_1;

    return *this;
}
