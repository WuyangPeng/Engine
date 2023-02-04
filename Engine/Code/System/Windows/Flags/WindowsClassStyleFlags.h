///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/02/02 14:36)

#ifndef SYSTEM_WINDOWS_WINDOWS_CLASS_STYLE_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_CLASS_STYLE_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class WindowsClassStyle
    {
        /// ����ƶ���������ڵĸ߶ȣ��ػ��������ڡ�
        VerticalRedraw = CS_VREDRAW,
        /// ����ƶ���������ڵĿ�ȣ��ػ��������ڡ�
        HorizontalRedraw = CS_HREDRAW,

        Redraw = VerticalRedraw | HorizontalRedraw,

        /// �����򴰿ڷ���˫����������Ϣ
        DoubleClicks = CS_DBLCLKS,

        /// �ô������ÿ������ʵ��������һ��Ψһ�Ĵ�����DC��
        OwnDC = CS_OWNDC,
        /// �ô���������д���ʵ��������һ��������DC��
        ClassDC = CS_CLASSDC,
        /// ���Ӵ��ڵĲü��������õ������ڵ�DC��ȥ�������Ӵ��ڱ�����ڸ������ϻ�������
        ParentDC = CS_PARENTDC,

        /// ��ֹϵͳ�˵��Ĺر�ѡ��
        NoClose = CS_NOCLOSE,

        /// ��λͼ��ʽ���汻�ô����ڵ�����Ļ���֣������Զ��ڲ˵����͵Ĵ��ڱȽϺ��ʣ�
        SaveBits = CS_SAVEBITS,

        /// ���ֽڱ߽��ϣ���x�����ϣ���λ���ڵ��û������λ��
        ByteAlignClient = CS_BYTEALIGNCLIENT,
        /// ���ֽڱ߽��ϣ���x�����ϣ���λ���ڵ�λ��
        ByteAlignWindow = CS_BYTEALIGNWINDOW,

        /// ��ʾ�ô�������һ��Ӧ�ó���ȫ���࣬
        /// �������CreateWindow��CreateWindowEx�����ʹ��ݸ�RegisterClass��instance������ͬ��
        /// �����ָ���÷����������instance������ͬ��
        GlobalWindow = CS_GLOBALCLASS,

        /// ʹһ����������ӰЧ����
        /// ��Ч��������ʱ��
        /// ͨ��SPI_SETDROPSHADOW�رա�
        /// (�����Զ���С�Ҷ��ݵĴ��ڱȽϺ��ʣ�
        /// ����˵�����ǿ���Լ����������ڵ�z˳���ϵ��)
        DropShadow = CS_DROPSHADOW,

        CommonUse = Redraw | OwnDC | DoubleClicks,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class WindowsClassStyle
    {
        VerticalRedraw = 0x0001,
        HorizontalRedraw = 0x0002,

        Redraw = VerticalRedraw | HorizontalRedraw,

        DoubleClicks = 0x0008,
        OwnDC = 0x0020,
        ClassDC = 0x0040,
        ParentDC = 0x0080,
        NoClose = 0x0200,
        SaveBits = 0x0800,
        ByteAlignClient = 0x1000,
        ByteAlignWindow = 0x2000,
        GlobalWindow = 0x4000,
        DropShadow = 0x00020000,

        CommonUse = Redraw | OwnDC | DoubleClicks,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_WINDOWS_WINDOW_CLASS_STYLE_FLAGS_H
