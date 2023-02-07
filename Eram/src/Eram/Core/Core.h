#pragma once

#ifdef ER_ENABLE_ASSERTS
	#define ER_ASSERT(x, ...) { if(!x) { ER_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define ER_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ER_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)