#include <Haven.h>

class Sandbox : public Haven::Application
{
public:
	Sandbox()
	{
		//
	}

	~Sandbox()
	{
		//
	}
};

Haven::Application* Haven::CreateApplication()
{
	return new Sandbox();
}