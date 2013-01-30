#ifndef _H_PUNK_OPENCL_ERROR_CHECK
#define _H_PUNK_OPENCL_ERROR_CHECK

#include "cl_exceptions.h"

#ifdef _DEBUG

#define THROW_CASE(X, MSG) case X: throw OpenCL_##X##_Exception(System::string(MSG))

#define CHECK_CL_ERROR(CODE, X) { \
	switch(CODE)\
	{ \
	case CL_SUCCESS: break;\
	THROW_CASE(CL_DEVICE_NOT_FOUND, X);\
	THROW_CASE(CL_DEVICE_NOT_AVAILABLE, X);\
	THROW_CASE(CL_COMPILER_NOT_AVAILABLE, X);\
	THROW_CASE(CL_MEM_OBJECT_ALLOCATION_FAILURE, X);\
	THROW_CASE(CL_OUT_OF_RESOURCES, X);\
	THROW_CASE(CL_OUT_OF_HOST_MEMORY, X);\
	THROW_CASE(CL_PROFILING_INFO_NOT_AVAILABLE, X);\
	THROW_CASE(CL_MEM_COPY_OVERLAP, X);\
	THROW_CASE(CL_IMAGE_FORMAT_MISMATCH, X);\
	THROW_CASE(CL_IMAGE_FORMAT_NOT_SUPPORTED, X);\
	THROW_CASE(CL_BUILD_PROGRAM_FAILURE, X);\
	THROW_CASE(CL_MAP_FAILURE, X);\
	THROW_CASE(CL_MISALIGNED_SUB_BUFFER_OFFSET, X);\
	THROW_CASE(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, X);\
	THROW_CASE(CL_INVALID_VALUE, X);\
	THROW_CASE(CL_INVALID_DEVICE_TYPE, X);\
	THROW_CASE(CL_INVALID_PLATFORM, X);\
	THROW_CASE(CL_INVALID_DEVICE, X);\
	THROW_CASE(CL_INVALID_CONTEXT, X);\
	THROW_CASE(CL_INVALID_QUEUE_PROPERTIES, X);\
	THROW_CASE(CL_INVALID_COMMAND_QUEUE, X);\
	THROW_CASE(CL_INVALID_HOST_PTR, X);\
	THROW_CASE(CL_INVALID_MEM_OBJECT, X);\
	THROW_CASE(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, X);\
	THROW_CASE(CL_INVALID_IMAGE_SIZE, X);\
	THROW_CASE(CL_INVALID_SAMPLER, X);\
	THROW_CASE(CL_INVALID_BINARY, X);\
	THROW_CASE(CL_INVALID_BUILD_OPTIONS, X);\
	THROW_CASE(CL_INVALID_PROGRAM, X);\
	THROW_CASE(CL_INVALID_PROGRAM_EXECUTABLE, X);\
	THROW_CASE(CL_INVALID_KERNEL_NAME, X);\
	THROW_CASE(CL_INVALID_KERNEL_DEFINITION, X);\
	THROW_CASE(CL_INVALID_KERNEL, X);\
	THROW_CASE(CL_INVALID_ARG_INDEX, X);\
	THROW_CASE(CL_INVALID_ARG_VALUE, X);\
	THROW_CASE(CL_INVALID_ARG_SIZE, X);\
	THROW_CASE(CL_INVALID_KERNEL_ARGS, X);\
	THROW_CASE(CL_INVALID_WORK_DIMENSION, X);\
	THROW_CASE(CL_INVALID_WORK_GROUP_SIZE, X);\
	THROW_CASE(CL_INVALID_WORK_ITEM_SIZE, X);\
	THROW_CASE(CL_INVALID_GLOBAL_OFFSET, X);\
	THROW_CASE(CL_INVALID_EVENT_WAIT_LIST, X);\
	THROW_CASE(CL_INVALID_EVENT, X);\
	THROW_CASE(CL_INVALID_OPERATION, X);\
	THROW_CASE(CL_INVALID_GL_OBJECT, X);\
	THROW_CASE(CL_INVALID_BUFFER_SIZE, X);\
	THROW_CASE(CL_INVALID_MIP_LEVEL, X);\
	THROW_CASE(CL_INVALID_GLOBAL_WORK_SIZE, X);\
	default: \
		throw OpenCLException(X);\
	} }
#else
#define CHECK_CL_ERROR(CODE, X)
#endif	_DEBUG

#endif	//	_H_PUNK_OPENCL_ERROR_CHECK