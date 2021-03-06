#ifndef _H_PUNK_THREAD_WIN32
#define _H_PUNK_THREAD_WIN32

#include "../../../config.h"
#include "os_handle.h"

namespace System
{
	class PUNK_ENGINE Thread : public OsHandle
	{
	public:
		bool Create(unsigned (__stdcall *thread_func)(void*), void* data = 0, unsigned stack = 4096); 
		bool Join();
		bool Resume();
		bool Destroy();
		//bool Terminate();
		~Thread();
	};
}

#endif
