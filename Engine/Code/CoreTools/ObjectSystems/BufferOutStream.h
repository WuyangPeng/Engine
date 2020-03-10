// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(BufferOutStreamImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	// дobjects���ڴ�顣������ʧ��ʱ���׳�Error�쳣��

	class CORE_TOOLS_DEFAULT_DECLARE BufferOutStream : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(BufferOutStream);
		using FileBufferPtr = std::shared_ptr<FileBuffer>;

	public:
		explicit BufferOutStream(const OutTopLevel& topLevel);

		CLASS_INVARIANT_DECLARE;

		FileBufferPtr GetBufferOutStreamInformation() const;

	private:
		IMPL_TYPE_DECLARE(BufferOutStream);
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H
