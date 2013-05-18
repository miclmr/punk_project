#include "test10.h"

namespace Test10
{
	class TestApp : public Punk::Application
	{
		System::Object* m_map;
	public:
		TestApp()
		{
		}

		virtual void OnInit(const Punk::Config &value)
		{

		}

		virtual void OnRender(GPU::Frame* frame) override
		{


		}

	};

	void Test::Run()
	{
		TestApp app;
		try
		{
			app.Init(Punk::Config());
			System::Mouse::Instance()->LockInWindow(false);
			app.Run();
		}
		catch(System::PunkException& e)
		{
			out_error() << e.ToString() << std::endl;
			m_result = false;
		}
		catch(...)
		{
			m_result = false;
		}
	}

	bool Test::Succeed()
	{
		return m_result;
	}

}