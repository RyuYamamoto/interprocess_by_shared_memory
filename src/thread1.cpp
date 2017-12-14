#include <iostream>
#include <string>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

using namespace boost::interprocess;

struct TestData
{
	int counter;
	std::string hello;
	TestData(): counter(0), hello("Hello World!") {}
};

int main(int argc, char* argv[])
{
	managed_shared_memory shm(open_or_create, "TestSharedMemory", 1024);
	interprocess_mutex* mx = shm.find_or_construct<interprocess_mutex>("test_mutex")();
	TestData* ptr	= shm.find_or_construct<TestData>("TestData")();

	scoped_lock<interprocess_mutex> lock(*mx);
	ptr->counter++;
}
