#include "erpch.h"
#include "Eram.h"

#include "Eram/Core/Utill.h"

#ifdef ER_PLATFORM_WINDOWS

int main()
{
	Eram::Log::Init();
	ER_INFO("Initialized Log");

	Eram::Application app;
	app.Run();

	return 0;
}

#endif