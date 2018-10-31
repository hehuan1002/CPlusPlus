#pragma once
#include <mutex>

// RAII¿‡
class CLockGuard
{
public:
	CLockGuard(std::mutex &m):_m(m) { _m.lock();}
	~CLockGuard(){_m.unlock();}
private:
	std::mutex &_m;
};
