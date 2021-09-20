///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/26 23:54)

#include "Example/BookCpp/AppliedCpp/AppliedCppExport.h"

#include "APThumbNail.h"
#include "Example/BookCpp/AppliedCpp/Helper/AppliedCppClassInvariantMacro.h"

#include <gsl/gsl_util>
#include <cstdio>
#include <memory>

// setw()������
#include <iomanip>
#include <iostream>

///  �򵥵Ķ�������ͼ����������

/// ���
///       1         2         3         4         5         6    6
///345678901234567890123456789012345678901234567890123456789012345

BookIntermediate::AppliedCpp::APThumbNail::APThumbNail() noexcept
{
    APPLIED_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookIntermediate::AppliedCpp, APThumbNail)

void BookIntermediate::AppliedCpp::APThumbNail::CreateThumbNail(const char* inputFile, const char* outputFile, int factor)
{
    APPLIED_CPP_CLASS_IS_VALID_9;

    // ��֤����
    if (inputFile == nullptr || outputFile == nullptr || factor <= 1)
    {
        throw Invalid();
    }

    // ��ȡԭʼͼƬ
    ReadImage(inputFile);
    if (!image.IsImageValid())
    {
        throw Invalid();
    }

    // �������ǵ��ڲ�����ͼ
    thumbNail = APImage(image.Width() / factor, image.Height() / factor);

    // ��apImage�е�����rangeErrorsת��Ϊ���ǵ���Ч����
    try
    {
        for (int y = 0; y < thumbNail.Height(); y++)
        {
            for (int x = 0; x < thumbNail.Width(); x++)
            {
                // ת��Ϊͼ���������ҵ�ƽ��ֵ
                const unsigned char pixel = AveragePixels(x * factor, y * factor, factor);
                thumbNail.SetPixel(x, y, pixel);
            }
        }
    }
    catch (const APImage::RangeError&)
    {
        throw Invalid();
    }

    WriteImage(outputFile);
}

unsigned char BookIntermediate::AppliedCpp::APThumbNail::AveragePixels(int x0, int y0, int factor)
{
    int sum = 0;

    // ����ͼ���е�ƽ����������
    try
    {
        for (int y = 0; y < factor; y++)
        {
            for (int x = 0; x < factor; x++)
            {
                sum += image.GetPixel(x + x0, y + y0);
            }
        }
    }
    catch (const APImage::RangeError&)
    {
        throw Invalid();
    }

    // ����ת���Ƿǳ���ȫ��

    return gsl::narrow_cast<unsigned char>(sum / (factor * factor));
}

void BookIntermediate::AppliedCpp::APThumbNail::ReadImage([[maybe_unused]] const char* inputFile)
{
    // ���ǽ����Ժ����۴˲��衣 ���ڣ����ٶ����ļ��ж�ȡͼ�񲢽�����Ϊ��ά�������������ͼ���С�
    // ���´��뽫����һ���ϳɵ�64x64ͼ��

    image = APImage(64, 64);

    try
    {
        for (int y = 0; y < image.Height(); y++)
        {
            for (int x = 0; x < image.Width(); x++)
            {
                image.SetPixel(x, y, gsl::narrow_cast<unsigned char>(y % 255));
            }
        }
    }
    catch (const APImage::RangeError&)
    {
        throw Invalid();
    }
}

void BookIntermediate::AppliedCpp::APThumbNail::WriteImage([[maybe_unused]] const char* outputFile) const
{
    // ���ǽ����Ժ����۴˲��衣 ���ڣ�����������ͼͼ����д���ļ���
    // ���´��뽫ͼ����ʾΪʮ������ֵ��
    APImage output = thumbNail;

    // �������ĸ�ʽ��״̬
    const std::ios_base::fmtflags flags = std::cout.flags(std::cout.hex);
    const auto width = std::cout.width(2);

    for (int y = 0; y < output.Height(); y++)
    {
        for (int x = 0; x < output.Width(); x++)
        {
            // (int)ȷ��������ʾΪ���֣��������ַ���
            std::cout << static_cast<int>(output.GetPixel(x, y)) << " ";
        }

        std::cout << std::endl;
    }

    std::cout.flags(flags);
    std::cout.width(width);
}
